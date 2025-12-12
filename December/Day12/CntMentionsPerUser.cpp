// LEETCODE 3433. Count Mentions Per User

// You are given an integer numberOfUsers representing the total number of users and an array events of size n x 3.

// Each events[i] can be either of the following two types:

// Message Event: ["MESSAGE", "timestampi", "mentions_stringi"]
// This event indicates that a set of users was mentioned in a message at timestampi.
// The mentions_stringi string can contain one of the following tokens:
// id<number>: where <number> is an integer in range [0,numberOfUsers - 1]. There can be multiple ids separated by a single whitespace and may contain duplicates. This can mention even the offline users.
// ALL: mentions all users.
// HERE: mentions all online users.
// Offline Event: ["OFFLINE", "timestampi", "idi"]
// This event indicates that the user idi had become offline at timestampi for 60 time units. The user will automatically be online again at time timestampi + 60.
// Return an array mentions where mentions[i] represents the number of mentions the user with id i has across all MESSAGE events.

// All users are initially online, and if a user goes offline or comes back online, their status change is processed before handling any message event that occurs at the same timestamp.

// Note that a user can be mentioned multiple times in a single message event, and each mention should be counted separately.

 

// Example 1:

// Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]]

// Output: [2,2]

// Explanation:

// Initially, all users are online.

// At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]

// At timestamp 11, id0 goes offline.

// At timestamp 71, id0 comes back online and "HERE" is mentioned. mentions = [2,2]

// Example 2:

// Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","12","ALL"]]

// Output: [2,2]

// Explanation:

// Initially, all users are online.

// At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]

// At timestamp 11, id0 goes offline.

// At timestamp 12, "ALL" is mentioned. This includes offline users, so both id0 and id1 are mentioned. mentions = [2,2]

// Example 3:

// Input: numberOfUsers = 2, events = [["OFFLINE","10","0"],["MESSAGE","12","HERE"]]

// Output: [0,1]

// Explanation:

// Initially, all users are online.

// At timestamp 10, id0 goes offline.

// At timestamp 12, "HERE" is mentioned. Because id0 is still offline, they will not be mentioned. mentions = [0,1]

 

// Constraints:

// 1 <= numberOfUsers <= 100
// 1 <= events.length <= 100
// events[i].length == 3
// events[i][0] will be one of MESSAGE or OFFLINE.
// 1 <= int(events[i][1]) <= 105
// The number of id<number> mentions in any "MESSAGE" event is between 1 and 100.
// 0 <= <number> <= numberOfUsers - 1
// It is guaranteed that the user id referenced in the OFFLINE event is online at the time the event occurs.



// 🚀 Approach
// Event Struct
//     Each event is represented with a timestamp, type (OFFLINE or MENTION), and its index in the input.
//     Type encoding: 0 = OFFLINE, 1 = MENTION.
// Sorting Events
//     Events are sorted by timestamp.
//     If two events have the same timestamp, OFFLINE events are processed before MENTION events (ensures correctness when a user goes offline exactly at the mention time).
// Tracking Online Users
//     Maintain an online array where online[userId] stores the time until which the user is offline.
//     If online[userId] <= currTime, the user is considered online.
// Processing Mentions
//     If the mention is "ALL" → increment all users’ mention count.
//     If the mention is "HERE" → increment only those users who are online at currTime.
//     If the mention is a list of specific users (U0 U1 ...) → increment only those users.
// Return the mentions array containing the count of mentions for each user.


// 🕛 Complexity
// E = events.length
// N = numberOfUsers

// Time complexity: O(ElogE + E*N)
// ElogE -> For sorting
// E * N -> Processing each event & in worst case, we loop N times

// Space complexity: O(E + N)












class Solution {
public:
    struct Event {
        int timestamp;
        int type;
        int idx;
    };

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<Event> sorted;
        
        for (int i = 0; i < events.size(); i++) {
            int time = stoi(events[i][1]);
            int type = (events[i][0] == "OFFLINE" ? 0 : 1);
            sorted.push_back({time , type , i});
        }

        sort(begin(sorted) , end(sorted) , [](const Event& a , const Event& b) {
            if (a.timestamp != b.timestamp) return a.timestamp < b.timestamp;
            return a.type < b.type;
        });
        
        vector<int> mentions(numberOfUsers , 0);
        vector<int> online(numberOfUsers , 0);

        for (auto& ev : sorted) {
            int currTime = ev.timestamp;
            vector<string>& ogEvent = events[ev.idx];

            if (ev.type == 0) {
                int userId = stoi(ogEvent[2]);
                online[userId] = currTime + 60;
            }
            else {
                string mentionStr = ogEvent[2];
                if (mentionStr == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) mentions[i]++;
                }
                else if (mentionStr == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (online[i] <= currTime) mentions[i]++;
                    }
                }
                else {
                    stringstream ss(mentionStr);
                    string token;

                    while(ss >> token) {
                        int userId = stoi(token.substr(2));
                        mentions[userId]++;
                    }
                }
            }
        }
        return mentions;
    }
};