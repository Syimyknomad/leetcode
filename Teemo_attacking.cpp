#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()){
            return 0;
        }
        int total_poisoned_time=0;
        int n = timeSeries.size();

        for (int i=0; i<n; ++i){
            if(i==0){
                total_poisoned_time += duration;
            }else{
                int previous_end = timeSeries[i-1]+ duration -1;
                int current_start = timeSeries[i];
                if (current_start <= previous_end){
                    total_poisoned_time += (current_start - timeSeries[i-1]);
                }else{
                    total_poisoned_time += duration;
                }
            }
        }
        return total_poisoned_time;
    }
};
