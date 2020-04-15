#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <tuple>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

using ll = long long;
#define int ll

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef pair<int, ii> iii;
typedef vector<si> vsi;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef map<string, vs> msvs;
typedef map<string, int> msi;
typedef map<char, int> mci;
typedef map<int, int> mii;
typedef map<string, string> mss;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout << #x << ": " << x << endl;
#define printArray(arr) \
  for (auto x : arr)    \
  {                     \
    cout << x << ", ";  \
  }
#define printMatrix(mat) \
  for (auto x : mat)     \
  {                      \
    cout << " ";         \
    printArray(x);       \
    cout << endl;        \
  }
#define printMap(mmap)                           \
  for (auto p : mmap)                            \
  {                                              \
    cout << p.first << ": " << p.second << endl; \
  }

class Box
{
private:
  int l;
  int b;
  int h;

public:
  Box()
  {
    l = b = h = 0;
  }
  Box(int length, int breadth, int height)
  {
    l = length;
    b = breadth;
    h = height;
  }
  Box(const Box &boxy)
  {
    l = boxy.l;
    b = boxy.b;
    h = boxy.h;
  }

  int getLength()
  {
    return l;
  }
  int getBreadth()
  {
    return b;
  }
  int getHeight()
  {
    return h;
  }
  ll CalculateVolume()
  {
    return l * b * h;
  }

  bool operator<(const Box &B)
  {
    int res = 0;
    if (l < B.l)
    {
      res = 1;
    }
    else if (b < B.b && l == B.l)
    {
      res = 1;
    }
    else if (h < B.h && h == B.h && b == B.b)
    {
      res = 1;
    }
    return res;
  }
  friend ostream &operator<<(ostream &out, const Box &B);
};
ostream &operator<<(ostream &out, const Box &B)
{
  out << B.l << " " << B.b << " " << B.h;
  return out;
}

void check2()
{
  int n;
  cin >> n;
  Box temp;
  for (int i = 0; i < n; i++)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      cout << temp << endl;
    }
    if (type == 2)
    {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      temp = NewBox;
      cout << temp << endl;
    }
    if (type == 3)
    {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      if (NewBox < temp)
      {
        cout << "Lesser\n";
      }
      else
      {
        cout << "Greater\n";
      }
    }
    if (type == 4)
    {
      cout << temp.CalculateVolume() << endl;
    }
    if (type == 5)
    {
      Box NewBox(temp);
      cout << NewBox << endl;
    }
  }
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); // Fast input
#ifdef LOCAL_PROJECT
  freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
#endif

  check2();
  return 0;
}