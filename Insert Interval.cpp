/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
 public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int i = 0;
    vector<Interval> r;
    while (i < intervals.size()) {
      if (intervals[i].start > newInterval.end) {
        break;
      }
      if (intervals[i].end < newInterval.start) {
        r.push_back(intervals[i]);
      } else {
        newInterval.start = min(newInterval.start, intervals[i].start);
        newInterval.end = max(newInterval.end, intervals[i].end);
      }
      i++;
    }
    r.push_back(newInterval);
    while (i < intervals.size()) {
      r.push_back(intervals[i]);
      i++;
    }
    return r;
  }
};
