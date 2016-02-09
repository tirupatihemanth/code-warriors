// All tests passed.

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

int fl = 0 ; 
void split(vi& v){
   vi a(v.size(),0) ; 
    
   for (int i = 0 ; i < v.size() ; i++){
       int t = v[i] ; 
       if (t > 18 || t < 0){
       		fl = 1 ; 
       		return ; 
       }
       //cout << t << el ; 
       for (int j = 9 ; j >= 0 ; j--){
           for (int k = 9 ; k >= 0 ; k--){
               if (j+k == t){
                   a[i] = j ; a[v.size()-i-1] = k ; 
                  // cout << j << sp << k << el ; 
                    
               }
           }
           
       }
   }
   forn(i,a.size()){
   		cout << a[i]  ; 
   }
   cout << el ; 
   
}



bool solve(vi& v){
    int st = 0 ; int en = v.size()-1  ; 
    
    while (st <= en){
    	//cout << st << sp << en << el ; 
    	if (st == en){
    		if (v[st]%2 == 0){
    			v[st]/= 2 ; 
    			return true ; 
    		}
    		return false  ; 
    	}
    	else if (st+1 == en){
    		if (v[st] == v[en]){
    			return true ; 
    		}
    		if (v[st] == 11+v[en]){
    			v[st]-= 1 ; v[en] += 10 ; 
    			return true ; 
    		}
    		return false ; 
    	}
    	//cout << v[st] << sp << v[en] << el ; 
    	else if (v[st] == v[en]){
    		st++ ; en-- ; 
    		continue ; 
    	}
    	else if (v[st] == 10+v[en]){
    		v[en] += 10 ; v[en-1] -= 1 ; 
    		en-- ; st++ ; 
    		continue ; 
    	}
    	else if (v[st] == 11+v[en]){
    		v[en]+= 10 ; 
    		v[en-1] -= 1 ; 
    		v[st] -= 1 ; v[st+1] += 10 ; 
    		st++ ; en--  ; 
    		continue ;   
    	}
    	else if (v[st] == v[en]+1){
    		//cout << "came here" << el ; 
    		v[st] -= 1 ; v[st+1] += 10 ; 
    		st++ ; en-- ; 
    		continue ; 
    	}
    	else {
    		return false ; 
    	}
    	
    }
    return true ; 
}


int main(){
    string s ; cin >> s ; 
    vi v ; 
    forn(i,s.size()){
        v.pb(s[i]-'0') ; 
    }
    vi v2 ; int flag = 0 ; 
     if (v[0] == 1 && v[1] <= 9 && v.size() >= 2){
        flag = 1 ; 
        v2.pb(v[0]*10+v[1]) ;
        for (int k = 2 ; k < v.size() ; k++){
            v2.pb(v[k]) ; 
        }
     }
    
    if (solve(v)){
         
        if (v[0] != 0){
            split(v) ;
            if (fl == 1){
            	cout << "0" << el ; 
            	return 0  ; 
            } 
            return 0 ;    
        }  
          
    }
    //cout << "Hamma" << el ; 
    if (flag == 1 && solve(v2)){
        if (v2[0] != 0){
            split(v2) ; 
            if (fl == 1){
            	cout << "0" << el ; 
            	return 0  ; 
            }
            return 0 ;    
        }
         
    }
    cout << "0" << el ; 
    return 0 ; 
}
