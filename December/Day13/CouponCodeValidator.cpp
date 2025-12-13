// LEETCODE 3606. Coupon Code Validator

// You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

// code[i]: a string representing the coupon identifier.
// businessLine[i]: a string denoting the business category of the coupon.
// isActive[i]: a boolean indicating whether the coupon is currently active.
// A coupon is considered valid if all of the following conditions hold:

// code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
// businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
// isActive[i] is true.
// Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.

 

// Example 1:

// Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]

// Output: ["PHARMA5","SAVE20"]

// Explanation:

// First coupon is valid.
// Second coupon has empty code (invalid).
// Third coupon is valid.
// Fourth coupon has special character @ (invalid).
// Example 2:

// Input: code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]

// Output: ["ELECTRONICS_50"]

// Explanation:

// First coupon is inactive (invalid).
// Second coupon is valid.
// Third coupon has invalid business line (invalid).
 

// Constraints:

// n == code.length == businessLine.length == isActive.length
// 1 <= n <= 100
// 0 <= code[i].length, businessLine[i].length <= 100
// code[i] and businessLine[i] consist of printable ASCII characters.
// isActive[i] is either true or false.





// 🚀 Approach
// Validation Rules:
//     Skip coupons that are inactive.
//     Skip coupons whose business line is not in the allowed set (electronics, grocery, pharmacy, restaurant).
//     Skip coupons with empty codes.
//     Ensure the coupon code contains only alphanumeric characters or underscores.
// Collection:
//     Store valid coupons as pairs (businessLine, code) for easier sorting later.
// Sorting:
//     Define a fixed order for business lines using a map (electronics → 0, grocery → 1, etc.).
//     Sort the collected coupons first by business line order, then by code lexicographically.
// Result Construction:
//     Extract only the coupon codes from the sorted pairs and return them as the final result.

// 🕛 Complexity
// n = number of coupons
// m = number of valid coupons

// Time complexity: O(n + mlogm)

// Space complexity: O(m)













class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        unordered_set<string> validCat = {"electronics" , "grocery" , "pharmacy" , "restaurant"};

        vector<pair<string , string>> valCoup;

        for (int i = 0; i < n; ++i) {
            string& c = code[i];
            string& b = businessLine[i];
            bool active = isActive[i];

            if (!active) {
                continue;
            }

            if (validCat.find(b) == validCat.end()) {
                continue;
            }

            if (c.empty()) {
                continue;
            }

            bool valCode = all_of(begin(c) , end(c) , [](char ch) {
                return isalnum(ch) || ch == '_';
            });

            if (!valCode) {
                continue;
            }

            valCoup.push_back({b , c});
        }

        unordered_map<string , int> order = {
            {"electronics" , 0},
            {"grocery" , 1},
            {"pharmacy" , 2},
            {"restaurant" , 3}
        };

        sort(valCoup.begin() , valCoup.end() , [&](const pair<string , string>& a , const pair<string , string>& b) {
            if (order[a.first] != order[b.first]) {
                return order[a.first] < order[b.first];
            }
            return a.second < b.second;
        });

        vector<string> res;
        for (auto& p : valCoup) {
            res.push_back(p.second);
        }
        return res;
    }
};