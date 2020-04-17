// https://codeforces.com/problemset/problem/584/D
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

map<int, bool> dp_prime;

bool isPrime(int t)
{
  if (dp_prime[t])
  {
    return true;
  }
  else if (t == 1)
  {
    return false;
  }
  else if (t % 2 == 0)
  {
    return false;
  }
  else
  {
    for (int j = 3; j <= sqrt(t); j++)
    {
      if (t % j == 0)
      {
        dp_prime[t] = false;
        return false;
      }
    }
    dp_prime[t] = true;
    return true;
  }
}

bool prime_possible(int t)
{
  int temp = t;
  while (--t)
  {
    if (isPrime(t) && isPrime(temp - t))
    {
      cout << 3 << endl;
      cout << t << " " << temp - t << " ";
      return true;
    }
  }
  return false;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); // Fast input
#ifdef LOCAL_PROJECT
  freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
#endif

  dp_prime[2] = true;
  dp_prime[1] = false;

  int n, copy, tmp;
  cin >> n;
  // n = 27;
  copy = n++;
  while (n-- >= copy / 2)
  {
    if (n % 2 != 0)
    {
      int flag = 1;
      for (int j = 2; j <= sqrt(n); j++)
      {
        if (n % j == 0)
        {
          flag = 0;
          dp_prime[n] = false;
          break;
        }
      }
      if (flag)
      {
        dp_prime[n] = true;
        if (copy == n)
        {
          cout << 1 << endl;
          cout << n << endl;
          return 0;
        }
        else if (isPrime(copy - n))
        {
          cout << 2 << endl;
          cout << copy - n << " " << n << endl;
          return 0;
        }
        else if (prime_possible(copy - n))
        {
          cout << n << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
