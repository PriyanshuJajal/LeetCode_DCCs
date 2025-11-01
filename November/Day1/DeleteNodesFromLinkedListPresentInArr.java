// LEETCODE 3217. Delete Nodes From Linked List Present in Array

// You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

 

// Example 1:

// Input: nums = [1,2,3], head = [1,2,3,4,5]

// Output: [4,5]

// Explanation:



// Remove the nodes with values 1, 2, and 3.

// Example 2:

// Input: nums = [1], head = [1,2,1,2,1,2]

// Output: [2,2,2]

// Explanation:



// Remove the nodes with value 1.

// Example 3:

// Input: nums = [5], head = [1,2,3,4]

// Output: [1,2,3,4]

// Explanation:



// No node has value 5.

 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
// All elements in nums are unique.
// The number of nodes in the given list is in the range [1, 105].
// 1 <= Node.val <= 105
// The input is generated such that there is at least one node in the linked list that has a value not present in nums.




// 🚀 Approach
// Convert the nums into a Set for fast lookup.
// Remove leading nodes from the head if their values are in the set.
// Traverse the rest of the list using a pointer curr:
//     If curr's next is in the set, unlink and skip it.
//     Otherwise, move curr forward.
// Return the updated head of the list.



// 🕛 Complexity
// n = number of nodes , m = size of nums

// Time complexity: O(n + m)
// Space complexity: O(m)







/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> st = new HashSet<>();
        for (int num : nums) st.add(num);

        while(head != null && st.contains(head.val)) {
            head = head.next;
        }

        ListNode curr = head;
        while(curr.next != null) {
            if (st.contains(curr.next.val)) {
                curr.next = curr.next.next;
            }
            else curr = curr.next;
        }
        return head;
    }
}
