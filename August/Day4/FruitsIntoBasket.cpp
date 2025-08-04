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
// Use two pointers i and j to define the window: fruits[i...j].
// Use an unordered_map<int, int> (basket) to keep track of fruit type counts.
// Expand the window by incrementing j, and add fruits[j] to the basket.
// If the basket contains more than two types:
// Shrink the window from the left (i) until the basket has only two types.
// Decrement the count of fruits[i] and erase it from the basket if its count drops to 0.
// After each iteration, update res with the length of the current valid window.

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n =  fruits.size();
        int res = 0;
        
        int i = 0, j = 0;
        unordered_map<int , int> basket;

        while(j < n){
            basket[fruits[j]]++;

            while(basket.size() > 2 && i < n){
                basket[fruits[i]]--;
                if (basket[fruits[i]] == 0){
                    basket.erase(fruits[i]);
                }
                i++;
            }

            res = max(res , j - i +1);
            j++;
        }

        return res;
    }
};