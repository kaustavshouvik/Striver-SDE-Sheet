#include <bits/stdc++.h>
using namespace std;

int maxSumSubArray (int a[], int n) {
  int res = INT_MIN, sum = 0;

  for (int i=0; i<n; i++) {
    sum += a[i];

    res = max(res, sum);

    if (sum < 0) sum = 0;
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

  int a[] = {4, -6, 7, -5, 6, -1, -5, 9, -2};
  int n = sizeof(a)/sizeof(a[0]);

  cout << maxSumSubArray(a, n);

  return 0;
}