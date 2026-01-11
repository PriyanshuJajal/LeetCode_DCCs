// LEETCODE 85. Maximal Rectangle

// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.



// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= rows, cols <= 200
// matrix[i][j] is '0' or '1'.



// 🚀 Approach
// Histogram Transformation:
//     Convert each row into a histogram of heights.
//     If matrix[r][c] == '1', increment heights[c] by 1.
//     If matrix[r][c] == '0', reset heights[c] = 0.
// Largest Rectangle in Histogram:
//     For each histogram (row), calculate the largest rectangle using the Next Smaller to Left (NSL) and Next Smaller to Right (NSR) arrays.
//     NSL gives the nearest smaller element to the left of each bar.
//     NSR gives the nearest smaller element to the right of each bar.
//     The width of the rectangle for each bar = NSR[i] - NSL[i] - 1.
//     Area = width[i] * heights[i].
// Iterate Over Rows:
//     Start with the first row as the initial histogram.
//     For each subsequent row, update the histogram and compute the largest rectangle.
//     Keep track of the maximum area encountered.

// 🕛 Complexity
// m = number of rows
// n = number of columns

// Time complexity: O(m * n)
// Space complexity: O(n)









class Solution {
public:
    // NSR -> Next Smaller to Right...
    vector<int> getNSR(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> NSR(n);

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) NSR[i] = n;
            
            else {
                while(!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }

                if (st.empty()) {
                    NSR[i] = n;
                }
                else NSR[i] = st.top();
            }
            st.push(i);
        }
        return NSR;
    }

    // NSL -> Next Smaller to Left...
    vector<int> getNSL(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> NSL(n);

        for (int i = 0; i < n; i++) {
            if (st.empty()) NSL[i] = -1;
            else {
                while(!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }

                if (st.empty()) NSL[i] = -1;
                else NSL[i] = st.top();
            }
            st.push(i);
        }
        return NSL;
    } 

    int findMaxArea(vector<int>& heights) {
        vector<int> NSR = getNSR(heights);
        vector<int> NSL = getNSL(heights);

        int n = heights.size();

        vector<int> width(n);
        for (int i = 0; i < n; i++) {
            width[i] = NSR[i]- NSL[i] - 1;
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int a = width[i] * heights[i];
            maxArea = max(maxArea , a);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n);

        // Adding first row to solve as 1-D array...
        for (int i = 0; i < n; i++) {
            heights[i] = (matrix[0][i] == '1') ? 1 : 0;
        }

        int maxArea = findMaxArea(heights);

        // Adding the other row's valid 1's into 1-D heights array...
        for (int r = 1; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == '0') {
                    heights[c] = 0;
                }
                else heights[c] += 1; 
            }

            maxArea = max(maxArea , findMaxArea(heights));
        }
        return maxArea;
    }
};