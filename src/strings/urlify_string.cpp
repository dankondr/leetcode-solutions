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
    // Yandex interview task
    // Task: Urlify (replace spaces with %20) the string O(n) speed and O(1) memory
    void urlify(string& str) {
        int n = str.size();
        int spaces = 0;
        for (char ch : str) {
            if (ch == ' ') ++spaces;
        }
        str.resize(n + spaces * 2);
        int pos = n - 1;
        for (int i = str.size() - 1; i >= 0; --i) {
            if (str[pos] != ' ') {
                str[i] = str[pos];
            } else {
                str[i - 2] = '%';
                str[i - 1] = '2';
                str[i] = '0';
                i -= 2;
            }
            --pos;
        }
    }
};

int main() {
    /*
        Input: "what is this string"
        Output: "what%20is%20this%20string"
    */
    auto solution = Solution();
    string str = "what is this string";
    solution.urlify(str);
    cout << str << endl;
    return 0;
}