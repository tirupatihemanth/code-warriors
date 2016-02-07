#include <iostream>

using namespace std;

int arr[501][501];
int main(){
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans += (n*n - (n-k+1)*i+1);
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        arr[i][k] = n*n - (n-k+1)*i+1;
        for(int j=k+1;j<=n;j++){
            arr[i][j] = arr[i][k]+(j-k); 
        }
    }
    int num=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<k;j++){
            arr[i][j] = num++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}