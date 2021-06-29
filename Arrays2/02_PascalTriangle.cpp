#include <bits/stdc++.h>
using namespace std;

// Type 1:
// Given n, print the first n rows
void pascalTriangle1 (int n) {
  vector<vector<int>> a(n);

  for (int i=0; i<n; i++) {
    vector<int> row(i+1);
    row[0] = row[i] = 1;
    
    for (int j=1; j<i; j++) {
      row[j] = a[i-1][j-1] + a[i-1][j];
    }

    a[i] = row;
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<=i; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
}

// Type 2:
// Given n and i, print the ith element in nth row
void pascalTriangle2 (int n, int r) {
  // It is same as calculating (n-1)C(r-1)

  r--;
  n--;

  if (r == 0) {
    cout << "1";
    return;
  }

  int res = 1;

  // O(n)
  for (int i=1; i<=r; i++) {
    res *= n--;
  }

  // O(n)
  for (int i=1; i<=r; i++) {
    res /= i;
  }

  cout << res;
}

// Type 3:
// Given n, print the nth row
void pascalTriangle3 (int n) {
  // We wanna calculate for all values of r
  // (n-1)Cr

  n--;

  // first element is always 1

  cout << 1 << " ";

  int res = 1;
  for (int i=0; i<n; i++) {
    res *= (n-i);
    res /= (i+1);

    cout << res << " ";
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

  // pascalTriangle1(5);
  // pascalTriangle2(4, 3);
  pascalTriangle3(2);

  return 0;
}