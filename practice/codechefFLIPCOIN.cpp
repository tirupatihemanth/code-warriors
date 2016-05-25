#include <iostream>
#include <cstdio>

using namespace std;

int segTree[400004]={0};
int lazyTree[400004]={0};

void update(int x, int y, int left, int right, int sidx){
    
    if(lazyTree[sidx]){
        segTree[sidx] = (right-left+1)-segTree[sidx];
        if(left!=right){
            lazyTree[2*sidx]^=1;
            lazyTree[2*sidx+1]^=1;    
        }
        lazyTree[sidx]=0;
    }
    if(y<left||x>right){
        return;
    }
    if(left == right){
        segTree[sidx]^=1;
        return;
    }
    if(left>=x && right<=y){
        lazyTree[2*sidx]^=1;
        lazyTree[2*sidx+1]^=1;
        segTree[sidx] = (right-left+1)-segTree[sidx];
        return;
    }
    else{
        int mid = (left+right)/2;
        update(x, y, left, mid, 2*sidx);
        update(x, y, mid+1, right, 2*sidx+1);
    }
    segTree[sidx] = segTree[2*sidx]+segTree[2*sidx+1];
}

int query(int x, int y, int left, int right, int sidx){
    if(lazyTree[sidx]){
        segTree[sidx] = (right-left+1)-segTree[sidx];
        if(left!=right){
            lazyTree[2*sidx]^=1;
            lazyTree[2*sidx+1]^=1;    
        }
        lazyTree[sidx]=0;
    }
    if(y<left||x>right){
        return 0;
    }    
    if(left>=x && right<=y){
        return segTree[sidx];
    }
    else{
        int mid = (left+right)/2;
        return query(x, y, left, mid, 2*sidx) + query(x, y, mid+1, right, 2*sidx+1);
    }
}

int main(){
    int N, Q;
    cin>>N>>Q;
    while (Q--)
    {
        int z, x, y;
        scanf("%d%d%d", &z, &x, &y);
        x++;
        y++;
        if(z){
            printf("%d\n", query(x, y, 1, N, 1));        
        }   
        else{
            update(x, y, 1, N, 1);
        }     
    }
    return 0;    
}