#include <bits/stdc++.h>
using namespace std;

int findDuplicate (int a[], int n) {
  int slow = a[0];
  int fast = a[a[0]];

  while (slow != fast) {
    slow = a[slow];
    fast = a[a[fast]];
  }

  fast = 0;
  while (slow != fast) {
    slow = a[slow];
    fast = a[fast];
  }

  return slow;
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

  int a[] = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
  int n = sizeof(a)/sizeof(a[0]);

  cout << findDuplicate(a, n);

  return 0;
}