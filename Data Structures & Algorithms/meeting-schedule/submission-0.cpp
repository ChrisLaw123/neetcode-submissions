/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        //sort intervals by begin time

        std::sort(intervals.begin(), intervals.end(), [](auto a, auto b){
            return a.start < b.start;
        });

        for (int i{}; i < intervals.size(); i++) {
            if (i+1 < intervals.size() && intervals[i].end > intervals[i+1].start) {
                return false;
            }
        }
        return true;

    }
};
