#include <iostream>

using namespace std;

int main(){
    long long int n,a,b,c;
    cin>>n>>a>>b>>c;
    long long int ans1=0, ans2=0;
    //As many a's as possible
    ans1 = n/a;
    long long int temp = n%a;
    if(temp>=b){
        ans1+=((temp-b)/(b-c))+1;
    }
    if(n>=b){
        ans2+=((n-b)/(b-c))+1;
    }
    temp = n-(ans2*(b-c));
    ans2+=temp/a;
    cout<<max(ans1,ans2);
    return 0;
}