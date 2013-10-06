class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    // Note: The Solution object is instantiated only once and is reused by each
    // test case.
    int n = gas.size();
    vector<int> front(n + 1);
    vector<int> back(n + 1);
    int cur = 0;
    front[0] = 0;
    back[n] = 0;
    for (int i = 0; i < n; i++) {
      cur += gas[i] - cost[i];
      front[i + 1] = min(front[i], cur);
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
      cur -= gas[i] - cost[i];
      back[i] = min(back[i + 1], cur);
      if (back[i] >= cur && front[i] >= cur)
        return i;
    }
    return -1;
  }
};
