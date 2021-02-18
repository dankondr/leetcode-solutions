#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/integer-to-roman
    string intToRoman(int num) {
        vector<int> dec_romans = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        unordered_map<int, string> romans = {
                {1, "I"},
                {4, "IV"},
                {5, "V"},
                {9, "IX"},
                {10, "X"},
                {40, "XL"},
                {50, "L"},
                {90, "XC"},
                {100, "C"},
                {400, "CD"},
                {500, "D"},
                {900, "CM"},
                {1000, "M"}
        };
        string result;
        for (int div : dec_romans) {
            for (int i = 0; i != num / div; ++i) {
                result.append(romans[div]);
            }
            num %= div;
            if (num == 0) { break; }
        }
        return result;
    }
};

int main() {
    /*
        Input: num = 58
        Output: "LVIII"
        Explanation: L = 50, V = 5, III = 3.
    */
    auto solution = Solution();
    int num = 1994;
    string result = solution.intToRoman(num);
    cout << result << endl;
    return 0;
}