#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& a) {
  int n = a.size(), m = a[0].size();
  
  int col = 1;
  
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (a[i][j] == 0) {
        if (j == 0) {
          col = 0;
        } else {
          a[0][j] = 0;
          a[i][0] = 0;
        }
      }
    }
  }
  
  for (int i=n-1; i>=0; i--) {
    for (int j=m-1; j>=0; j--) {
      if (j == 0) {
        if (col == 0) a[i][j] = 0;
      } else {
        if (a[0][j] == 0 || a[i][0] == 0) {
          a[i][j] = 0;
        }
      }
    }
  }
}

int32_t main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("error.txt", "w", stderr);
  freopen("output.txt", "w", stdout);
  #endif

  vector<vector<int>> a = {
    {0, 1, 2, 0},
    {3, 4, 5, 2},
    {1, 3, 1, 5}
  };

  setZeroes(a);

  for (vector<int> row : a) {
    for (int x : row) cout << x << " ";
    cout << "\n";
  }

  return 0;
}