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

using ll=long long;
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector <si> vsi;
typedef vector <ii> vii;
typedef vector <int> vi;
typedef vector <char> vc;
typedef vector <string> vs;
typedef map <string,vs> msvs;
typedef map <string,int> msi;
typedef map <char,int> mci;
typedef map <int,int> mii;
typedef map <string,string> mss;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define endl '\n' // Normal `cout << endl` flushes the output every time wich hit performance badly
#define INF 1000000000
#define deb(x) cout<<#x<<": "<<x<<endl;
#define printArray(arr) for(auto x: arr) { cout<<x<<", "; }
#define printMatrix(mat) for(auto x: mat) { cout<<" "; printArray(x); cout<<endl; }
#define printMap(mmap) for(auto p: mmap) { cout<< p.first<<": "<<p.second<<endl; }


vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<vector<string>> result(strs.size());
  int index = 0, y;
  for (int i = 0; i < strs.size() ; i++)
  {
    /* code */
    if(result[index].size()==0){
      result[index].push_back(strs[i]);
    }else{
      bool flag = true;
      string temp,temp2 = strs[i];
      y = 0;
      for(auto x : result)
      {
        if(x.size()!=0){
          temp = x[0];
        sort(x[0].begin(),x[0].end());
        sort(strs[i].begin(),strs[i].end());
        if(x[0]==strs[i])
        {
          result[y].push_back(temp2);
          flag = false;
          break;
        }
        y++;
        }else{
          break;
        }
      }
      if(flag){
        result[++index].push_back(temp2);
      }

    }  
  }
  y = 0;
  for(auto x : result)
  {
    if(x.size()!=0) y++;
  } 
  
  result.resize(y);
  return result;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast input
  #ifdef LOCAL_PROJECT
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
  #endif

  vector<string> arr = {"","b",""};

  groupAnagrams(arr);
  
  
  return 0;
}
