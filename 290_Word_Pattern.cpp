/*
Time Complexity:
- O(n), where n is the number of characters in string `s` (for splitting + iteration)

Space Complexity:
- O(k), where k is the number of unique letters in pattern or words in `s` (for maps)

Did it run on LeetCode?
- Yes

Issues Faced:
- Need to ensure both maps are used to enforce bijection (not just one-way).
- Corner case: mismatched number of words and pattern length must be caught early.

--------------------------------------------------------------------------------
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        int pl = pattern.size();
        vector<string> words;
        string word;

        // Split string into words
        while (iss >> word) {
            words.emplace_back(word);
        }

        // Length mismatch check
        if (words.size() != pl) return false;

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pl; ++i) {
            char p = pattern[i];
            string w = words[i];

            // Check char-to-word mapping
            if (charToWord.find(p) == charToWord.end()) {
                charToWord[p] = w;
            } else {
                if (charToWord[p] != w) return false;
            }

            // Check word-to-char mapping (bijection)
            if (wordToChar.find(w) == wordToChar.end()) {
                wordToChar[w] = p;
            } else {
                if (wordToChar[w] != p) return false;
            }
        }

        return true;
    }
};
