#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
char str[30002];
int segTree[120004];

int build(int left, int right, int sidx){
    if(left == right){
        if(str[left] == '('){
            segTree[sidx] = 1;    
        }
        else if(str[left] == ')'){
            segTree[sidx] = -1;
        }
    }
    else if(left < right){
        segTree[sidx] = build(left, (left+right)/2, 2*sidx)+build((left+right)/2+1, right, 2*sidx+1);
    }    
    return segTree[sidx];
}

int update(int left, int right, int pos, int sidx){
    
    
    if((left == right) && (right == pos)){
        if(segTree[sidx] == 1){
            segTree[sidx] = -1;
        }
        else{
            segTree[sidx] = 1;
        }
        return segTree[sidx];
    }
    
    int mid = (left+right)/2;
    if(pos<=mid){
        update(left, mid, pos, 2*sidx);
    }
    else{
        update(mid+1, right, pos, 2*sidx+1);
    }
    segTree[sidx] = segTree[2*sidx]+segTree[2*sidx+1];
    return segTree[sidx];
}

int main(){
    int n, m;
    for(int z=1;z<=10;z++){
        cout<<"Test "<<z<<":"<<endl;
        cin>>n;
        scanf("%s", &str[1]);
        cin>>m;
        int func;
        build(1, n, 1);
        for(int i=1;i<=m;i++){
            cin>>func;
            if(!func){
                if(segTree[1]==0){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
            else{
                update(1, n, func,1 );
            }
        }
    }

    return 0;
}