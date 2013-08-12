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
  struct Cmp {
    bool operator()(const Interval &l, const Interval &r) {
      return l.start < r.start;
    }
  } cmp;

public:
  vector<Interval> merge(vector<Interval> &intervals) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<Interval> r;
    if (intervals.empty())
      return r;

    sort(intervals.begin(), intervals.end(),
         [](const Interval & a, const Interval & b) {
      return a.start < b.start;
    });
    int s = intervals[0].start, e = intervals[0].end;
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i].start > e) {
        r.push_back(Interval(s, e));
        s = intervals[i].start;
        e = intervals[i].end;
      } else if (intervals[i].end > e) {
        e = intervals[i].end;
      }
    }
    r.push_back(Interval(s, e));
    return r;
  }
};
