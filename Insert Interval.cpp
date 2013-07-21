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
  // there are two cases: new interval overlap/not overlap with intervals.
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<Interval> r;
    if (intervals.empty()) {
      r.push_back(newInterval);
      return r;
    }
    if (newInterval.end < intervals[0].start) {
      r.push_back(newInterval);
    }
    bool insert_new = false;
    for (int i = 0; i < intervals.size(); i++) {
      if (intervals[i].start > newInterval.end ||
          intervals[i].end < newInterval.start) {
        if (insert_new && intervals[i].start > newInterval.end) {
          insert_new = false;
          r.push_back(newInterval);
        }
        if (i > 0 && intervals[i].start > newInterval.end &&
            intervals[i - 1].end < newInterval.start) {
          r.push_back(newInterval);
        }
        r.push_back(intervals[i]);

      } else {
        insert_new = true;
        if (intervals[i].start < newInterval.start) {
          newInterval.start = intervals[i].start;
        }
        if (intervals[i].end > newInterval.end) {
          newInterval.end = intervals[i].end;
        }
      }
    }
    if (insert_new) {
      r.push_back(newInterval);
    }
    if (newInterval.start > intervals[intervals.size() - 1].end) {
      r.push_back(newInterval);
    }
    return r;
  }
};
