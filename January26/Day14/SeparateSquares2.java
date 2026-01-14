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









import java.util.*;

class SegmentTree {
    private int[] count;
    private int[] covered;
    private int[] xs;
    private int n;

    public SegmentTree(int[] xs_) {
        this.xs = xs_;
        this.n = xs.length - 1;
        this.count = new int[4 * n];
        this.covered = new int[4 * n];
    }

    private void modify(int qleft, int qright, int qval, int left, int right, int pos) {
        if (xs[right + 1] <= qleft || xs[left] >= qright) {
            return;
        }

        if (qleft <= xs[left] && xs[right + 1] <= qright) {
            count[pos] += qval;
        } else {
            int mid = (left + right) / 2;
            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        if (count[pos] > 0) {
            covered[pos] = xs[right + 1] - xs[left];
        } else {
            if (left == right) {
                covered[pos] = 0;
            } else {
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
            }
        }
    }

    public void update(int qleft, int qright, int qval) {
        modify(qleft, qright, qval, 0, n - 1, 0);
    }

    public int query() {
        return covered[0];
    }
}

class Solution {
    public double separateSquares(int[][] squares) {
        List<int[]> events = new ArrayList<>();
        TreeSet<Integer> xsSet = new TreeSet<>();

        for (int[] sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;
            events.add(new int[]{y, 1, x, xr});
            events.add(new int[]{y + l, -1, x, xr});
            xsSet.add(x);
            xsSet.add(xr);
        }

        events.sort((a, b) -> Integer.compare(a[0], b[0]));

        int[] xs = xsSet.stream().mapToInt(Integer::intValue).toArray();
        SegmentTree segTree = new SegmentTree(xs);

        List<Double> psum = new ArrayList<>();
        List<Integer> widths = new ArrayList<>();
        double totalArea = 0.0;
        int prev = events.get(0)[0];

        for (int[] e : events) {
            int y = e[0], delta = e[1], xl = e[2], xr = e[3];
            int len = segTree.query();

            totalArea += 1L * len * (y - prev);
            segTree.update(xl, xr, delta);

            psum.add(totalArea);
            widths.add(segTree.query());
            prev = y;
        }

        long target = (long) ((totalArea + 1) / 2);
        int i = Collections.binarySearch(psum, (double) target);
        if (i < 0) i = -i - 2; 

        double area = psum.get(i);
        int width = widths.get(i);
        int height = events.get(i)[0];

        return height + (totalArea - area * 2) / (width * 2.0);
    }
}