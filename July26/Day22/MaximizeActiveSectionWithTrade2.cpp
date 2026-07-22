// LEETCODE 3501. Maximize Active Section with Trade II

// Let n be the length of the string s
// Time Complexity: O(n + qlogn)
// Space Complexity: O(n)


class SegTree {
private:
    int n;
    vector<int> arr;
    vector<int> seg;

    void build(int p , int l , int r) {
        if (l == r) {
            seg[p] = arr[l];
            return;
        }

        int mid = (l + r) >> 1;

        build(p << 1 , l , mid);
        build(p << 1 | 1 , mid + 1 , r);
        seg[p] = max(seg[p << 1] , seg[p << 1 | 1]);
    }

    int _query(int p , int l , int r , int L , int R) {
        if (L <= l && r <= R) {
            return seg[p];
        }

        int mid = (l + r) >> 1;
        int res = 0;

        if (L <= mid) {
            res = max(res , _query(p << 1 , l , mid , L , R));
        }

        if (R > mid) {
            res = max(res , _query(p << 1 | 1 , mid + 1 , r , L , R));
        }

        return res;
    }

public:
    SegTree(const vector<int>& arr) : arr(arr) {
        n = arr.size();
        seg.resize(n << 2 , 0);
        build(1 , 0 , n - 1);
    }

    int query(int L , int R) {
        if (L > R) return 0;

        return _query(1 , 0 , n - 1 , L , R);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int cnt1 = count(begin(s) , end(s) , '1');

        vector<int> zeroBlocks;
        vector<int> leftBlock;
        vector<int> rightBlock;

        int i = 0;
        while(i < n) {
            int st = i;
            while(i < n && s[i] == s[st]) {
                i++;
            }

            if (s[st] == '0') {
                zeroBlocks.push_back(i - st);
                leftBlock.push_back(st);
                rightBlock.push_back(i - 1);
            }
        }

        int m = zeroBlocks.size();
        if (m < 2) {
            return vector<int>(queries.size() , cnt1);
        }

        vector<int> tmpSum(m - 1);
        for (int i = 0; i < m - 1; i++) {
            tmpSum[i] = zeroBlocks[i] + zeroBlocks[i + 1];
        }

        SegTree seg(tmpSum);
        vector<int> ans;

        for (const auto& q : queries) {
            int l = q[0] , r = q[1];

            int i = lower_bound(begin(rightBlock) , end(rightBlock) , l) - rightBlock.begin();
            int j = upper_bound(begin(leftBlock) , end(leftBlock) , r) - leftBlock.begin() - 1;

            if (i > m - 1 || j < 0 || i >= j) {
                ans.push_back(cnt1);
                continue;
            }

            int firstLen = rightBlock[i] - max(leftBlock[i] , l) + 1;
            int lastLen = min(rightBlock[j] , r) - leftBlock[j] + 1;

            if (i + 1 == j) {
                int bestGain = firstLen + lastLen;
                ans.push_back(bestGain + cnt1);
                continue;
            }

            int val1 = firstLen + zeroBlocks[i + 1];
            int val2 = zeroBlocks[j - 1] + lastLen;
            int val3 = seg.query(i + 1 , j - 2);

            int bestGain = max({val1 , val2 , val3});
            ans.push_back(cnt1 + bestGain);
        }

        return ans;
    }
};