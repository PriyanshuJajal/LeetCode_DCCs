class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            // To store the sum of above to elements...
            vector<int> row(i + 1 , 1);
            for (int j = 1; j < i; j++) {
                row[j] = res[i - 1][j] + res[i - 1][j - 1];
            }
            // Append it to the actual result vector res...
            res.push_back(row);
        }
        return res;
    }
};