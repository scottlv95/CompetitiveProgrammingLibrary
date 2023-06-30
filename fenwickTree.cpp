#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef vector<int> vi;
class FenwickTree {
private:
  vi ft;
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }
  int rsq(int j) {
    int sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
// the key operation
// index 0 is not used
// create empty FT
// returns RSQ(1, j)
   }
   int rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion
   // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
   void update(int i, int v) {
     for (; i < (int)ft.size(); i += LSOne(i))
       ft[i] += v;
} };