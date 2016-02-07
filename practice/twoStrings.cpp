#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <climits>

#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL cout<<endl
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c,i) for(auto i = (c).begin(); i!=(c).end(); i++)
#define present(c,x) ((c).find(x)!=(c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

bool check_substring(int k, string &str1, string &str2){
    
    for(int i=0;i<str1.size();i++){
        if(i+k>str1.size()){
            return false;
        }
        for(int j=0;j<str2.size();j++){
            if(j+k>str2.size()){
                break;
            }
            int ret = true;
            for(int temp=0;temp<k;temp++){
                if(str1[i+temp]!=str2[j+temp]){
                    ret = false;
                    break;
                }
            }
            if(ret){
                return ret;
            }
        }
    }  
}

int main(){
    int T;
    cin>>T;
    string str1, str2;
    while(T--){
        cin>>str1>>str2;
        bool status = false;
        FOR(i, 1, str1.size()){
            if(check_substring(i,str1, str2)){
                status = true;
                cout<<"YES"<<endl;
                break;
            }
        }
        if(!status){
            cout<<"NO"<<endl;
        }
    }
}