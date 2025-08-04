// LEETCODE 904...

// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

 

// Example 1:

// Input: fruits = [1,2,1]
// Output: 3
// Explanation: We can pick from all 3 trees.
// Example 2:

// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: We can pick from trees [1,2,2].
// If we had started at the first tree, we would only pick from trees [0,1].
// Example 3:

// Input: fruits = [1,2,3,2,2]
// Output: 4
// Explanation: We can pick from trees [2,3,2,2].
// If we had started at the first tree, we would only pick from trees [1,2].
 

// Constraints:

// 1 <= fruits.length <= 105
// 0 <= fruits[i] < fruits.length


// Approach...
// Use two pointers: l for the left boundary and r for the right.
// Traverse the array with r, expanding the window and updating the count of each fruit in a HashMap.
// Whenever the map size exceeds two (i.e., more than two fruit types in the current window), shrink the window from l:
// Decrease the count of fruits[l].
// Remove it from the map if the count becomes zero.
// Move l to the right.
// After each step, update maxFruits as the length of the current valid window.

class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer , Integer> basket = new HashMap<>();
        int l = 0 , maxFruits = 0;

        for (int r = 0; r < fruits.length; r++) {
            int currCnt = basket.getOrDefault(fruits[r] , 0);
            basket.put(fruits[r] , currCnt + 1);

            while(basket.size() > 2) {
                int fruitCnt = basket.get(fruits[l]);
                if (fruitCnt == 1) basket.remove(fruits[l]);
                else basket.put(fruits[l] , fruitCnt - 1);
                l++;
            }
            maxFruits = Math.max(maxFruits , r - l + 1);
        } 
        return maxFruits;
    }
}