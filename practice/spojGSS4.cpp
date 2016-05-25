#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int arr[100001];
long segTree[400004];

long build(int left, int right, int sidx){
    
    if(left == right){
        segTree[sidx] = arr[left];
    }   
    else if(left<right){
        int mid = (left+right)/2;
        segTree[sidx] = build(left, mid, 2*sidx) + build(mid+1, right, 2*sidx+1);
    }
    return segTree[sidx];
}

long query(int x, int y, int left, int right, int sidx){
    int mid = (left+right)/2;
    if(x == left && y == right){
        return segTree[sidx];
    }
    else if(y<=mid){
        return query(x, y, left, mid, 2*sidx);
    }
    else if(x>mid){
        return query(x, y, mid+1, right, 2*sidx+1);
    }
    else{
        return query(x, mid, left, mid, 2*sidx) + query(mid+1, y, mid+1, right, 2*sidx+1);
    }
}

void update(int x, int y, int left, int right, int sidx){
    if(left == right){
        arr[left] = (int) sqrt(arr[left]);
    }    
    
    mid = (x+y)/2;
}

void update(int left, int right, int pos, int val, int sidx){
    if(left == right && right == pos){
        segTree[sidx] = val;
        arr[left] = val;
        return;
    }    
    int mid = (left+right)/2;
    if(pos<=mid){
        update(left, mid, pos, val, 2*sidx);
    }
    else if(pos>mid){
        update(mid+1, right, pos, val, 2*sidx+1);
    }
    segTree[sidx] = segTree[2*sidx]+segTree[2*sidx+1];
    return;
}

int main(){
    int N, M, test=1;
    while(scanf("%d", &N) != EOF){
        printf("Case #%d:\n", test);
        int i, x, y, temp1, temp2;
        for(i=1;i<=N;i++){
            scanf("%d", &arr[i]);
        }
        cin>>M;
        build(1, N, 1);
        while(M--){
            cin>>i>>temp1>>temp2;
            x = min(temp1, temp2);
            y = max(temp1, temp2);
            if(i==0){
                for(int j=x;j<=y;j++){
                    if(arr[j] !=1 ){
                        update(1, N, j,(int) sqrt(arr[j]), 1);       
                    }
                }
            }
            else{
                cout<<query(x, y, 1, N, 1)<<endl;
            }
        }
        cout<<"\n";
        test++;
    }
    return 0;
}