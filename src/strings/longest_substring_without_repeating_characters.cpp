#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/longest-substring-without-repeating-characters/
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_map<char, int> seen_characters; // символ и его индекс
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (seen_characters.find(s[i]) != seen_characters.end()) {
                int char_index = seen_characters[s[i]];
                while (l <= char_index) {
                    seen_characters.erase(s[l]);
                    ++l;
                }
            }
            ++r;
            longest = max(longest, r - l);
            seen_characters[s[i]] = i;
        }
        return longest;
    }
};

int main() {
    /*
        Input: s = "abcabcbb"
        Output: 3
        Explanation: The answer is "abc", with the length of 3.
    */
    auto solution = Solution();
    string s = "ddddd";
    int result = solution.lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}