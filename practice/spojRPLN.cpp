#include <iostream>
#include <stdlib>
#include <cstdio>

using namespace std;

int arr[100001];
int segTree[400004];

int build(int left, int right, int sidx){
    if(left == right){
       segTree[sidx] = arr[left];
    }        
    else if(left<right){
        segTree[sidx] = min(build(left, (left+right)/2, 2*sidx), build((left+right)/2+1, right, 2*sidx+1));
    }
    return segTree[sidx];
}

int query(int x, int y, int left, int right, int s){
    int mid = (left+right)/2;
    if(x == left && y == right){
        return segTree[s];
    }
    if(x>=left && y<=mid){
        return query(x, y, left, mid, 2*s);
    }
    else if(x>mid && y<=right){
        return query(x, y, mid+1, right, 2*s+1);
    }
    else{
        return min(query(x, mid, left, mid, 2*s), query(mid+1, y, mid+1, right, 2*s+1));
    } 
}

int main(){
    int T, N, Q;
    cin>>T;
    for(int z=1;z<=T;z++){
        scanf("%d%d", &N, &Q);
        int i;
        for(i=1;i<=N;i++){
            scanf("%d", arr+i);
        }
        build(1, N, 1);
        cout<<"Scenario #"<<z<<":"<<"\n\n";
        for(i=0;i<Q;i++){
            int x, y;
            scanf("%d%d", &x, &y);
            cout<<query(x, y, 1, N, 1)<<"\n\n";
        }
    }
    return 0;
}