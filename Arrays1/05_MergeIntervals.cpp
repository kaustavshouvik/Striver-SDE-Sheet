#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals (vector<vector<int>>& intervals) {
  vector<vector<int>> res;
          
  sort(intervals.begin(), intervals.end());

  int n = intervals.size();

  res.push_back(intervals[0]);

  for (int i=1; i<n; i++) {
    int m = res.size();
    int end = res[m-1][1];

    int l = intervals[i][0];
    int r = intervals[i][1];

    if (res[m-1][0] <= l && res[m-1][1] >= r) continue;

    if (end >= intervals[i][0]) {
      end = intervals[i][1];
      res[m-1][1] = end;
    } else {
      res.push_back(intervals[i]);
    }
  }

  return res;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("error.txt", "w", stderr);
  freopen("output.txt", "w", stdout);
  #endif

  vector<vector<int>> intervals = {{1, 5}, {3, 6}, {2, 4}, {7, 9}};
  
  for (vector<int> res : mergeIntervals(intervals)) {
    cout << "(" << res[0] << ", " << res[1] << ")\n";
  }

  /*
  (1, 6)
  (7, 9)
  */

  return 0;
}