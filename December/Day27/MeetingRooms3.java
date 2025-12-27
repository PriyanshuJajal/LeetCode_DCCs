// LEETCODE 2402. Meeting Rooms III

// You are given an integer n. There are n rooms numbered from 0 to n - 1.

// You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

// Meetings are allocated to rooms in the following manner:

// Each meeting will take place in the unused room with the lowest number.
// If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
// When a room becomes unused, meetings that have an earlier original start time should be given the room.
// Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

// A half-closed interval [a, b) is the interval between a and b including a and not including b.

 

// Example 1:

// Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
// Output: 0
// Explanation:
// - At time 0, both rooms are not being used. The first meeting starts in room 0.
// - At time 1, only room 1 is not being used. The second meeting starts in room 1.
// - At time 2, both rooms are being used. The third meeting is delayed.
// - At time 3, both rooms are being used. The fourth meeting is delayed.
// - At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
// - At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
// Both rooms 0 and 1 held 2 meetings, so we return 0. 
// Example 2:

// Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
// Output: 1
// Explanation:
// - At time 1, all three rooms are not being used. The first meeting starts in room 0.
// - At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
// - At time 3, only room 2 is not being used. The third meeting starts in room 2.
// - At time 4, all three rooms are being used. The fourth meeting is delayed.
// - At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
// - At time 6, all three rooms are being used. The fifth meeting is delayed.
// - At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
// Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 
 

// Constraints:

// 1 <= n <= 100
// 1 <= meetings.length <= 105
// meetings[i].length == 2
// 0 <= starti < endi <= 5 * 105
// All the values of starti are unique.








// 🚀 Approach
// Sort meetings by start time so we process them chronologically.
// Maintain two priority queues:
//     available: a min‑heap of free room indices (so we always pick the smallest index).
//     usedRooms: a min‑heap of pairs (endTime , roomIndex) representing currently occupied rooms, ordered by earliest finishing time.
// For each meeting:
//     Free up rooms whose end time ≤ current meeting start, moving them back to available.
//     If there is an available room:
//         Assign the meeting to the smallest available room.
//         Push (end , room) into usedRooms.
//     Otherwise:
//         Take the room that finishes earliest from usedRooms.
//         Delay the meeting to start at that room’s end time.
//         Push (endTime + duration , room) back into usedRooms.
//     Increment the usage count for the assigned room.
// After processing all meetings, scan roomsUsed to find the room with the maximum usage.

// 🕛 Complexity

// m = number of meetings
// n = number of rooms

// Time complexity: O(mlogm + mlogn)
// Space complexity: O(m + n)










import java.util.*;

class Solution {
    static class Pair implements Comparable<Pair> {
        long endTime;
        int room;

        Pair(long endTime, int room) {
            this.endTime = endTime;
            this.room = room;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.endTime == other.endTime) {
                return Integer.compare(this.room, other.room);
            }
            return Long.compare(this.endTime, other.endTime);
        }
    }

    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));
        int[] roomsUsed = new int[n];

        PriorityQueue<Pair> usedRooms = new PriorityQueue<>(); // (endTime, room)
        PriorityQueue<Integer> available = new PriorityQueue<>(); // available rooms by index

        for (int room = 0; room < n; room++) {
            available.offer(room);
        }

        for (int[] meet : meetings) {
            int st = meet[0];
            int end = meet[1];
            int duration = end - st;

            while (!usedRooms.isEmpty() && usedRooms.peek().endTime <= st) {
                int room = usedRooms.poll().room;
                available.offer(room);
            }

            if (!available.isEmpty()) {
                int room = available.poll();
                usedRooms.offer(new Pair(end, room));
                roomsUsed[room]++;
            }
            else {
                Pair earliest = usedRooms.poll();
                int room = earliest.room;
                long endTime = earliest.endTime;
                usedRooms.offer(new Pair(endTime + duration, room));
                roomsUsed[room]++;
            }
        }

        int res = -1;
        int maxUse = 0;
        for (int room = 0; room < n; room++) {
            if (roomsUsed[room] > maxUse) {
                maxUse = roomsUsed[room];
                res = room;
            }
        }
        return res;
    }
}