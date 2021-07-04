#include <bits/stdc++.h>
using namespace std;

void nextPermutation (vector<int>& a) {
  int n = a.size();

  if (n < 2) return;

  int i = n-2;

  while (i >= 0 && a[i] >= a[i+1]) {
    i--;
  }

  // at this point either i == -1 or
  // a[i] < a[j]

  // it means the entire sequence
  // is sorted in decresing order
  // which is highest permutaion possible
  if (i < 0) {
    reverse(a.begin(), a.end());
    return;
  }

  int j = n-1;

  while (i < j && a[i] > a[j]) {
    j--;
  }

  swap(a[i], a[j]);

  reverse(a.begin()+i+1, a.end());
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

  // vector<int> a = {1, 2, 3, 4, 5};
  
  // while (next_permutation(a.begin(), a.end())) {
  //   for (int x : a) cout << x << " ";
  //   cout << "\n";
  // }

  // vector<int> a = {5, 1, 3, 4, 2};
  // vector<int> a = {1, 2, 3, 4, 5};
  vector<int> a = {5, 4, 3, 2, 1};
  
  nextPermutation(a);

  for (int x : a) cout << x << " ";

  return 0;
}