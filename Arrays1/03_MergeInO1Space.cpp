#include <bits/stdc++.h>
using namespace std;

int nextGap (int gap) {
  if (gap <= 1) return 0;
  return (gap/2 + gap%2);
}

void MERGE (int a[], int n, int b[], int m) {
  for (int gap = nextGap(n+m); gap > 0; gap = nextGap(gap)) {
    int i = 0;
    int j = i+gap;

    // at this point,
    // i is always 0
    
    // for j, it may be either of 2 cases:
    // either j < n
    // or j >= n

    // we can take a boolean to check it,
    // as if j >= n then (only) first
    // array is not considered.

    bool flag = false;

    if (j < n) {
      flag = true;
      while (j < n) {
        if (a[i] > a[j]) {
          swap(a[i], a[j]);
        }
        j++;
        i++;
      }
    }

    // at this point, if the upper
    // block were executed then
    // j == n but i < n
    // so, we make j = 0 to check
    // in the second array

    // otherwise, j = j-n
    // because j = i + gap and j >= n
    // so the first array
    // is never considered for both i and j
    // that is, a[i] and a[j]
    // is not considered.

    if (flag) j = 0;
    else j = j-n;

    // now, it is where
    // i < n and j < m
    // we can consider now
    // a[i] and b[j]

    while (i < n && j < m) {
      if (a[i] > b[j]) {
        swap(a[i], b[j]);
      }
      i++;
      j++;
    }
 
    // here both i >= n and j >= n
    // so we make i = 0 for b array
    // we can consider now
    // b[i] and b[j]

    i = 0;
    while (j < m) {
      if (b[i] > b[j]) {
        swap(b[i], b[j]);
      }
      i++;
      j++;
    }
  }
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

  int a[] = {2, 5, 7, 8, 11, 16};
  int b[] = {4, 6, 7, 9, 10, 12, 19};

  int n = sizeof(a)/sizeof(a[0]);
  int m = sizeof(b)/sizeof(b[0]);

  MERGE(a, n, b, m);

  for (int i=0; i<n; i++) cout << a[i] << " ";
  cout << "\n";
  for (int i=0; i<m; i++) cout << b[i] << " ";

  return 0;
}