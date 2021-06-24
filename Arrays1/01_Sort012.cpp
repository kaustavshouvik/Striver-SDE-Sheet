#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void sort012 (int a[], int n) {
  int lo = 0, mid = 0, hi = n-1;

  while (mid <= hi) {
    if (a[mid] == 0) {
      swap(a[mid], a[lo]);
      lo++, mid++;
    } else if (a[mid] == 1) {
      mid++;
    } else {
      swap(a[mid], a[hi]);
      hi--;
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

  int a[] = {0, 2, 0, 1, 0, 2, 2, 1, 0, 0, 1};
  int n = sizeof(a)/sizeof(a[0]);

  sort012(a, n);

  for (int i=0; i<n; i++) {
    cout << a[i] << " ";
  }

  return 0;
}