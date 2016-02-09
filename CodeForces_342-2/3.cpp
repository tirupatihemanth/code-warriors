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
	std:: string s =""; std :: string s1  = "" ; 
	char c ; 
    while (true){
        scanf("%c",&c); 
        if (c == '\n')
            break ; 
        s.append(1,c) ; 
    }
    while (true){
        scanf("%c",&c); 
        if (c == '\n')
            break ; 
        s1.append(1,c) ; 
    }
    //cout << s << el ;
    //cout << s1 << el ; 
	int cnt = 0 ; 
	int found = -1  ; 
	vi v ; 
	while (true){
		found = s.find(s1,found+1) ; 
		if (found == std:: string :: npos){
			break ; 
		}
		else{
			v.pb(found) ; 
		} 
	}
	int i = 0 ; 
	int a = -1 ; 
	while (i < v.size()){
		a = v[i] ; 
		cnt++ ; 
		i++ ; 
		while (v[i] < a+s1.size()){
			i++ ;
            if (i >= v.size())
                break ;  
		}
	}



	cout << cnt << el ; 

	return 0 ; 

}


 