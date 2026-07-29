// LEETCODE 3518. Smallest Palindromic Rearrangement II

// Time complexity: O(n * 26 * C)
// where n is the half-length (≤ 5000) and C is the small constant number of multiply/divide steps combCapped performs before it exceeds the cap

// Space complexity: O(1)



class Solution {
public:
    typedef long long ll;
    const ll LIMIT = 1000000;

    ll combCapped(ll n , ll r) {
        if (r < 0 || r > n) return 0;

        r = min(r , n - r);
        if (r == 0) return 1;

        __int128 res = 1;
        for (ll i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;

            if (res > LIMIT) return LIMIT + 1;
        }

        return (ll)res;
    }

    ll cntWays(vector<int>& cnt) {
        ll rem = 0;
        for (int x : cnt) {
            rem += x;
        }

        ll ans = 1;
        for (int c : cnt) {
            if (c == 0) continue;

            ll part = combCapped(rem , c);
            ans *= part;

            if (ans > LIMIT) return LIMIT + 1;
            rem -= c;
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26 , 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        } 

        char mid = 0;
        vector<int> half(26);
        int len = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];

            if (freq[i] & 1) {
                mid = char('a' + i);
            }
        }

        if (cntWays(half) < k) return "";

        string left = "";
        for (int pos = 0; pos < len; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0) continue;

                half[ch]--;

                ll ways = cntWays(half);
                if (ways >= k) {
                    left += char('a' + ch);
                    break;
                }

                k-= ways;
                half[ch]++;
            }
        }

        string right = left;
        reverse(begin(right) , end(right));

        if (mid) {
            return left + mid + right;
        }
        
        return left + right;
    }
};