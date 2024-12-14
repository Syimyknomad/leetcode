#include <iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int>returnSet;
        for (int num: nums2){
            if(set1.count(num)){
                returnSet.insert(num);
            }
        }
        return vector<int>(returnSet.begin(),returnSet.end());
    }
};
