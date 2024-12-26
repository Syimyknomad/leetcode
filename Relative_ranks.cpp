#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> scoreIndexPairs;
        for (int i = 0; i < n; ++i) {
            scoreIndexPairs.push_back({score[i], i});
        }
        sort(scoreIndexPairs.begin(), scoreIndexPairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return b.first < a.first;
        });
        vector<string> result(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                result[scoreIndexPairs[i].second] = "Gold Medal";
            } else if (i == 1) {
                result[scoreIndexPairs[i].second] = "Silver Medal";
            } else if (i == 2) {
                result[scoreIndexPairs[i].second] = "Bronze Medal";
            } else {
                result[scoreIndexPairs[i].second] = to_string(i + 1);
            }
        }

        return result;
    }
};
