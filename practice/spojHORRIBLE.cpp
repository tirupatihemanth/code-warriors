#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long segTree[400004]={0};
long long lazyTree[400004]={0};


void update(int x, int y, int left, int right, long long val, int sidx){
    if(lazyTree[sidx]){
        segTree[sidx]+=(right-left+1)*lazyTree[sidx];
        if(left!=right){
            lazyTree[2*sidx]+=lazyTree[sidx];
            lazyTree[2*sidx+1]+=lazyTree[sidx];     
        }
        lazyTree[sidx]=0;
    }
    
    if(y<left || x>right){
        return;
    }
    
    if(left == right){
        segTree[sidx]+=val;
        return;
    }
    if(left>=x && right <=y){
        lazyTree[2*sidx]+=val;
        lazyTree[2*sidx+1]+=val;
        segTree[sidx]+= (right-left+1)*val;
        return;
    }
    else{
        int mid = (left+right)/2;
        update(x, y, left, mid, val, 2*sidx);
        update(x, y, mid+1, right, val, 2*sidx+1);
    }
    segTree[sidx] = segTree[2*sidx]+segTree[2*sidx+1];
}


long long query(int x, int y, int left, int right, int sidx){
    if(lazyTree[sidx]){
        segTree[sidx]+=(right-left+1)*lazyTree[sidx];
        if(left!=right){
            lazyTree[2*sidx]+=lazyTree[sidx];
            lazyTree[2*sidx+1]+=lazyTree[sidx];     
        }
        lazyTree[sidx]=0;
    }
    
    if(y<left || x > right){
        return 0;
    }
    if(left>=x && right<=y){
        return segTree[sidx];
    }
    else{
        int mid = (left+right)/2;
        return (query(x, y, left, mid, 2*sidx) + query(x, y, mid+1, right, 2*sidx+1));
    }
}

int main(){
    int T, N, Q;
    cin>>T;
    while(T--){
        scanf("%d%d", &N, &Q);
        memset(segTree, 0, sizeof(segTree));
        memset(lazyTree, 0, sizeof(lazyTree));
        while(Q--){
           int z, x, y;
           long long v ; 
           scanf("%d%d%d", &z, &x, &y);
           if(!z){
               scanf("%lld", &v);
                update(x, y, 1, N, v, 1);
           }
           else{
               printf("%lld\n", query(x, y, 1, N, 1));
           }
           
        }   
        
    }
    return 0;
}