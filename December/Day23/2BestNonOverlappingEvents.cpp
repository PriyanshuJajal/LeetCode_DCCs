// LEETCODE 2054. Two Best Non-Overlapping Events

// You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

// Return this maximum sum.

// Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

 

// Example 1:


// Input: events = [[1,3,2],[4,5,2],[2,4,3]]
// Output: 4
// Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
// Example 2:

// Example 1 Diagram
// Input: events = [[1,3,2],[4,5,2],[1,5,5]]
// Output: 5
// Explanation: Choose event 2 for a sum of 5.
// Example 3:


// Input: events = [[1,5,3],[1,5,1],[6,6,5]]
// Output: 8
// Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
 

// Constraints:

// 2 <= events.length <= 105
// events[i].length == 3
// 1 <= startTimei <= endTimei <= 109
// 1 <= valuei <= 106




// 🚀 Approach
// Sort events by start time so we process them in chronological order.
// Use a min-heap priority queue (pq) where each element is (end, value):
//     This allows us to quickly discard events that end before the current event’s start.
// Maintain a variable maxVal to store the maximum value of any event that has already ended before the current event starts.
// For each event [a, b, val]:
//     Pop from the heap while the earliest ending event (pq.top().first) ends before a.
//         Update maxVal with the maximum value seen so far.
//     Update maxSum = max(maxSum , val + maxVal) → this considers taking the current event plus the best non-overlapping event.
//     Push the current event (b , val) into the heap.
// Return maxSum at the end.


// 🕛 Complexity
// Time complexity: O(nlogn)
// Space complexity: O(n)











class Solution {
public:
    typedef pair<int , int> P;
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<P , vector<P> , greater<P>> pq;
        sort(begin(events) , end(events));
        int maxVal = 0 , maxSum = 0;

        for (auto& e : events) {
            int a = e[0];
            int b = e[1];
            int val = e[2];

            while(!pq.empty() && pq.top().first < a) {
                maxVal = max(maxVal , pq.top().second);
                pq.pop();
            }
            maxSum = max(maxSum , val + maxVal);
            pq.push({b , val});
        }
        return maxSum;
    }
};