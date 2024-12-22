#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreaterMap;
        stack<int> stack;   

        for (int num : nums2){
            while (!stack.empty() && num >stack.top()){
                nextGreaterMap[stack.top()]=num;
                stack.pop();
            }
            stack.push(num);
        }
        while(!stack.empty()){
            nextGreaterMap[stack.top()]=-1;
            stack.pop();
        }
        vector<int> result;
        for(int num : nums1){
            result.push_back(nextGreaterMap[num]);
        }
        return result;
    }
};
