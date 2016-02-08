#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        string str1, str2;
        cin>>str1>>str2;
        int arr[26] = {0};
        for(int i=0;i<str1.size();i++){
            arr[str1[i]-'a']=1;
        }
        bool found = false;
        for(int j=0;j<str2.size();j++){
            if(arr[str2[j]-'a']){
                cout<<"YES"<<endl;
                found = true;
                break;
            }
        }
        if(!found){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}