// LEETCODE 61. Rotate List

// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:


// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
 

// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109


// 🚀 Approach
// Edge Cases: If k == 0, or the list is empty or has only one node, return the head as-is.
// Count Nodes: Traverse the list to count the total number of nodes (cnt) and keep a pointer to the last node (curr).
// Make Circular: Connect the last node to the head to form a circular list.
// Normalize k: Use k %= cnt to handle cases where k is larger than the list length.
// Find New Tail: The new tail is at position cnt - k from the start.
// Break the Circle: Traverse to the new tail, set head = tail.next, and break the circle by setting tail.next = null.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr = head;
        if (k == 0 || head == nullptr || head -> next == nullptr) return head;

        int cnt = 1;
        while(curr -> next != nullptr) {
            cnt++;
            curr = curr -> next;
        }
        curr -> next = head;

        k %= cnt;
        int same = abs(k - cnt);
        curr = head;

        for (int i = 1; i < same; i++) {
            curr = curr -> next;
        }

        head = curr -> next;
        curr -> next = nullptr;

        return head;
    }
};