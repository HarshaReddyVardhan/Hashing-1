/*
Time Complexity:
- Let n be the number of strings and k be the average length of each string.
- Hashing each string takes O(k).
- Inserting into the map and building the result takes O(n).
- Overall Time Complexity: O(n * k)

Space Complexity:
- The hash map stores groups of strings → O(n * k)
- Each string is stored in result vector → O(n * k)
- Overall Space Complexity: O(n * k)

Did it run on LeetCode?
- Yes
Problems Faced:
- Using unsigned long long caused integer overflow when multiplying many primes for long strings.
- Switching to double avoids overflow by using floating-point approximation.
- ⚠️ However, double can lose precision for large values, potentially causing hash collisions (false positives).
- It worked for practical test cases, but not guaranteed to be 100% correct in edge cases.

Approach in 3 Sentences:
1. Map each character to a unique prime number.
2. For every string, compute the product of its character primes to use as a hash (same for all anagrams).
3. Group all strings with the same hash in a map and return the grouped results.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int primes[26] = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
            31, 37, 41, 43, 47, 53, 59, 61, 67, 
            71, 73, 79, 83, 89, 97, 101
        };

        unordered_map<double, vector<string>> mp;
        vector<vector<string>> ans;

        for (const auto& x : strs) {
            double hash = 1.0;
            for (char y : x) {
                hash *= primes[y - 'a'];
            }
            mp[hash].push_back(x);
        }

        for (const auto& x : mp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};
