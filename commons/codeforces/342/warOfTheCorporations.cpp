#include <iostream>

using namespace std;

int main(){
    string str1, str2;
    cin>>str1>>str2;
    int ans=0;
    int pos;
    while((pos = str1.find(str2))!=string::npos){
        ans++;
        if(pos+str2.size()>=str1.size()){
            break;   
        }
        str1 = str1.substr(pos+str2.size(), str1.size()-(pos+str2.size()));
    }
    cout<<ans;
    return 0;
}