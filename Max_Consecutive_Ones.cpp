#include <vector>
#include <algorithm>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int max_count = 0;       
        int current_count = 0;   

        for (int num : nums) {
            if (num == 1) {
                current_count++; 
                max_count = std::max(max_count, current_count); 
            } else {
                current_count = 0; 
            }
        }

        return max_count; 
    }
};
