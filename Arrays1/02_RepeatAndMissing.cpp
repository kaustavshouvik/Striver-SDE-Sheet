#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void repeatAndMissingNum (int a[], int n) {
  int x_xor_y = 0;

  // Take xor of whole array
  for (int i=0; i<n; i++) x_xor_y ^= a[i];

  // Take xor from 1 to n
  for (int i=1; i<=n; i++) x_xor_y ^= i;

  int x = 0, y = 0;

  int MSB = (int)log2(x_xor_y);

  for (int i=0; i<n; i++) {
    if (a[i]&(1<<MSB)) {
      x ^= a[i];
    } else {
      y ^= a[i];
    }
  }

  for (int i=1; i<=n; i++) {
    if (i&(1<<MSB)) {
      x ^= i;
    } else {
      y ^= i;
    }
  }

  bool found = false;

  for (int i=0; i<n; i++) {
    if (a[i] == x) {
      found = true;
    }
  }

  if (found) {
    cout << "Repeating Number: " << x << "\n";
    cout << "Missing number " << y << "\n";
  } else {
    cout << "Repeating Number: " << y << "\n";
    cout << "Missing number " << x << "\n";
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

  int n = 5;
  int a[n] = {5, 1, 2, 2, 3};

  repeatAndMissingNum(a, n);

  return 0;
}