class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int count = 0;
        int maxend = -1;
        for (auto& interval : intervals) {
            if (interval[1] <= maxend) {
                count++;
            } else {
                maxend = interval[1];
            }
        }

        return intervals.size() - count;
    }
};