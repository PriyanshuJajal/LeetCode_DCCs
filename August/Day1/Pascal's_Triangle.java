class Solution {
    void pascal(List<List<Integer>> list , int i , int n) {
        List<Integer> li = new ArrayList<>();
        
        // Base Case...
        if (i >= n) return;
        if (i == 0) li.add(1);
        else {
            // Always starts with 1...
            li.add(1);
            for (int j = 1; j < i; j++) {
                // Add the above two elements...
                li.add(list.get(i - 1).get(j) + list.get(i - 1).get(j - 1));
            }
            // Always ends with 1...
            li.add(1);
        }
        list.add(li);

        // Recursive call...
        pascal(list , i + 1 , n);
    }

    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        pascal(res , 0 , numRows);
        return res;
    }
}