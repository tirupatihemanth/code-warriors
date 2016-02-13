#include <iostream>
#include <cstdio>

using namespace std;

int arr[100001]={0};
int segTree[400004]={0};
int lazyTree[400004] = {0};

void update(int x, int y, int left, int right, int sidx){
    if(left == right){
        if(lazyTree[sidx]%2){
            segTree[sidx] = (segTree[sidx]+lazyTree[sidx])%2;
            lazyTree[sidx]=0;
        }
        if(segTree[sidx]%2){
            segTree[sidx]=0;
        }
        else{
            segTree[sidx]=1;
        }
        return;    
    }

    
    if(lazyTree[sidx]%2){
        segTree[sidx]=(right-left+1)-segTree[sidx];
        lazyTree[2*sidx]+=lazyTree[sidx];
        lazyTree[2*sidx+1]+=lazyTree[sidx];
        lazyTree[sidx]=0;
    }

    if(x == left && y == right){
        segTree[sidx] = (right-left+1)-segTree[sidx];
        lazyTree[2*sidx]+=1;
        lazyTree[2*sidx+1]+=1;
        return;
    }
    
    int mid = (left+right)/2;
   
    if (y<=mid)
    {
        update(x, y, left, mid, 2*sidx);
    }
    else if (x>mid)
    {   
        update(x, y, mid+1, right, 2*sidx+1);
    }
    else{
        update(x, mid, left, mid, 2*sidx);
        update(mid+1, y, mid+1, right, 2*sidx+1);
    }
    int var1 = 2*sidx;
    int var2 = 2*sidx+1;
    if(lazyTree[var1]%2){
        segTree[var1] = (mid-left+1)-segTree[var1];
        lazyTree[2*var1]+=lazyTree[var1];
        lazyTree[2*var1+1]+=lazyTree[var1]; 
        lazyTree[var1]=0;
    }
    if(lazyTree[var2]%2){
        segTree[var2] = (right-(mid+1)+1)-segTree[var2];
        lazyTree[2*var2]+=lazyTree[var2];
        lazyTree[2*var2+1]+=lazyTree[var2];
        lazyTree[var2]=0;
    }
    segTree[sidx] = segTree[2*sidx]+segTree[2*sidx+1];
    return;
}

int query(int x, int y, int left, int right, int sidx){
    if (left==right)
    {
        if(lazyTree[sidx]){
            segTree[sidx] =(segTree[sidx]+lazyTree[sidx])%2; 
            lazyTree[sidx]=0;
        }
        return segTree[sidx]; 
    }
    
    if(lazyTree[sidx]%2){
        segTree[sidx] = (right-left+1)-segTree[sidx];
        lazyTree[2*sidx]+=lazyTree[sidx];
        lazyTree[2*sidx+1]+=lazyTree[sidx];
        lazyTree[sidx]=0;
    }
    
    int mid = (left+right)/2;
    if(x==left && y == right){
        return segTree[sidx];
    }
    if(x>mid){
         return query(x, y, mid+1, right, 2*sidx+1);
    }   
    else if(y<=mid){
         return query(x, y, left, mid, 2*sidx);
    }
    else{
         return (query(x, mid, left, mid, 2*sidx) + query(mid+1, y, mid+1, right, 2*sidx+1));
    }
     
}

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    while (M--)
    {
        int z, x, y;
        scanf("%d%d%d", &z, &x, &y);
        if(!z){
            update(x, y, 1, N, 1);
            
        }
        else{
            printf("%d\n", query(x, y, 1, N, 1));
            
        }
    }   
}