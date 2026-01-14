// LEETCODE 3454. Separate Squares II

// You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

// Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.

// Answers within 10-5 of the actual answer will be accepted.

// Note: Squares may overlap. Overlapping areas should be counted only once in this version.

 

// Example 1:

// Input: squares = [[0,0,1],[2,2,1]]

// Output: 1.00000

// Explanation:



// Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.

// Example 2:

// Input: squares = [[0,0,2],[1,1,1]]

// Output: 1.00000

// Explanation:



// Since the blue square overlaps with the red square, it will not be counted again. Thus, the line y = 1 splits the squares into two equal parts.

 

// Constraints:

// 1 <= squares.length <= 5 * 104
// squares[i] = [xi, yi, li]
// squares[i].length == 3
// 0 <= xi, yi <= 109
// 1 <= li <= 109
// The total area of all the squares will not exceed 1015.


// Approach: Line sweep + segment tree + coordinate compression + binary search.

// Time Complexity: O(n\log n).
// Space Complexity: O(n).









class SegmentTree {
private:
    vector<int> count;
    vector<int> covered;
    vector<int> xs;
    int n;

    void modify(int qleft , int qright , int qval , int left , int right , int pos) {
        if (xs[right + 1] <= qleft || xs[left] >= qright) {
            return;
        }

        if (qleft <= xs[left] && xs[right + 1] <= qright) {
            count[pos] += qval;
        }
        else {
            int mid = (left + right) / 2;
            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        if (count[pos] > 0) {
            covered[pos] = xs[right + 1] - xs[left];
        }
        else {
            if (left == right) covered[pos] = 0;
            else covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
        }
    }

public:
    SegmentTree(vector<int>& xs_) : xs(xs_) {
        n = xs.size() - 1;
        count.resize(4 * n, 0);
        covered.resize(4 * n, 0);
    }

    void update(int qleft, int qright, int qval) {
        modify(qleft, qright, qval, 0, n - 1, 0);
    }

    int query() { return covered[0]; }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> events;
        set<int> xsSet;

        for (auto& sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;
            events.emplace_back(y, 1, x, xr);
            events.emplace_back(y + l, -1, x, xr);
            xsSet.insert(x);
            xsSet.insert(xr);
        }

        sort(begin(events), end(events));
   
        vector<int> xs(begin(xsSet), end(xsSet));

        SegmentTree segTree(xs);

        vector<double> psum;
        vector<int> widths;
        double total_area = 0.0;
        int prev = get<0>(events[0]);

        for (auto& [y, delta, xl, xr] : events) {
            int len = segTree.query();

            total_area += 1LL * len * (y - prev);
            segTree.update(xl, xr, delta);

            psum.push_back(total_area);
            widths.push_back(segTree.query());
            prev = y;
        }
        long long target = (long long)(total_area + 1) / 2;

        int i = lower_bound(begin(psum), end(psum), target) - begin(psum) - 1;

        double area = psum[i];
        int width = widths[i], height = get<0>(events[i]);

        return height + (total_area - area * 2) / (width * 2.0);
    }
};