#include <iostream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std ;
#include <bits/stdc++.h> 
typedef vector<int> vi ; 
typedef vector<char> vc ;
typedef vector<pair<int,int> > vp ; 
typedef vector<pair<int,pair<int,int> > > vpp ; 
typedef vector<bool> vb ;
typedef set<int> si ; 
typedef map<int,int> mi ; 
typedef map<int,vector<int> > miv ; 
typedef unsigned long long ull ; 


#define forn(i,n) for(int i = 0; i < n ; i++)
#define vvi vector<vector<int> > 
#define pi pair<int,int> 
#define pp pair<int,pair<int,int> >
#define sii set<pair<int,int> >  
#define INF 1000000
#define LIM 1000000000
#define sp " " 
#define el "\n"
#define ll long long 
#define rsz(n) resize(n)
#define all(v) v.begin(),v.end()
#define xx first 
#define yy second 
#define pb push_back
#define mp make_pair
#define sci(x) scanf("%d",&x)


int main(){
	int n , k ; cin >> n >> k ; 
    int pref = 0 ; int mid = n*n-(n-k) ; int en = n*n ; 
    int sum = 0 ; int a = mid ; 
    for (int i = 0 ; i < n ; i++){
        sum += a-(n-k+1)*i ; 
    }
    cout << sum << el ; 
    for (int i = 0 ; i < n ; i++){
        for (int j = 1 ; j <= k-1 ; j++){
            pref++ ; cout << pref << sp ; 
        }
        for(int j = mid ; j <= en ; j++){
            cout << j << sp ; 
        }
        cout << el ; 
        mid -= (n-k+1) ; en -= (n-k+1) ; 
    }
}


 