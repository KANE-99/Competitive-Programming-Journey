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
// #define int ll

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


int arraySum(int a[], int n)  
{ 
    int initial_sum  = 0;  
    return accumulate(a, a+n, initial_sum); 
} 

class Person {
	string name;
	int age;
	public:
	static int cur_id;
	virtual void getdata() {
        cin >> name >> age;
    }
    virtual void putdata() {
        cout << name << " " << age << endl;
    }
    friend class Professor;
    friend class Student;
};

class Professor : public Person {
	int publications;
	public:
	static int cur_id;
	Professor() {
		cur_id++;
	}
	void getdata(){
		cin >> name;
		cin >> age;
		cin >> publications;
	}
	void putdata(){
		cout << name << " " << age << " " << publications << " " << cur_id << "\n" ;
	}
};
int Professor::cur_id = 0;

class Student : public Person {
	int marks[6];
	public:
	static int cur_id;
	Student(){
		cur_id++;
	}
	void getdata(){
		cin >> name >> age;
		rep(i,0,6) {
			cin >> marks[i];
		}
	}
	void putdata(){
		cout << name << " " << age << " " << arraySum(marks, 6) << " " << cur_id << "\n"; 
	}
};
int Student::cur_id = 0;

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast input
  #ifdef LOCAL_PROJECT
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
  #endif
int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

  return 0;
}
