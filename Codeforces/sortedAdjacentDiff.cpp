//https://codeforces.com/problemset/problem/1339/B
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

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); // Fast input
                 // #ifdef LOCAL_PROJECT
                 //   freopen("in.in", "r", stdin);
                 //   // freopen("out.out", "w", stdout);
                 // #endif

  int T, n;
  cin >> T;
  while (T--)
  {
    cin >> n;
    int arr[n];
    rep(i, 0, n)
    {
      cin >> arr[i];
    }
    sort(arr, arr + n);

    int diff = 1;
    bool diffToggler = true;
    int i = (n - 1) / 2;
    while (i >= 0 && i < n)
    {
      cout << arr[i] << " ";
      if (diffToggler)
      {
        i += diff;
      }
      else
      {
        i -= diff;
      }
      diff++;
      diffToggler = !diffToggler;
    }
    cout << "\n";
  }
  return 0;
}
