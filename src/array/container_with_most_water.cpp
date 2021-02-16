#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/container-with-most-water/
    int maxArea(vector<int>& height) {
        int result = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            result = max(result, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return result;
    }
};

int main() {
    /*
        Input: height = [1,8,6,2,5,4,8,3,7]
        Output: 49 (second and last)
        Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
        In this case, the max area of water (blue section) the container can contain is 49.
    */
    auto solution = Solution();
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << solution.maxArea(height) << endl;
    return 0;
}