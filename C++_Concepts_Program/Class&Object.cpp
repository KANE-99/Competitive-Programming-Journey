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
#define FOR(i, a, n) for (int i = a; i < n; i++)
#define FORR(i, a, n) for (int i = n - 1; i >= a; i--)
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

class Student
{
private:
  int scores[5];

public:
  void input()
  {
    FOR(i, 0, 5)
    {
      cin >> scores[i];
    }
  }
  int calculateTotalScore()
  {
    int sum = 0;
    FOR(i, 0, 5)
    {
      sum += scores[i];
    }
    return sum;
  }
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); // Fast input
#ifdef LOCAL_PROJECT
  // freopen("in.in", "r", stdin);
  // freopen("out.out", "w", stdout);
#endif

  int n; // number of students
  cin >> n;
  Student *s = new Student[n]; // an array of n students

  for (int i = 0; i < n; i++)
  {
    s[i].input();
  }

  // calculate kristen's score
  int kristen_score = s[0].calculateTotalScore();

  // determine how many students scored higher than kristen
  int count = 0;
  for (int i = 1; i < n; i++)
  {
    int total = s[i].calculateTotalScore();
    if (total > kristen_score)
    {
      count++;
    }
  }

  // print result
  cout << count;
  return 0;
}