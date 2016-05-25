#include <iostream>
#include <cstdio>

using namespace std;

typedef struct Node_ Node;

struct Node_{
    int prefixCount;
    int suffixCount;
    int prefixElem;
    int suffixElem;
    int maxCount;
    void init(int val){
        prefixCount = 1;
        prefixElem = val;
        suffixElem = val;
        maxCount = 1;
        suffixCount = 1;
    }
    
    void merge(Node child1, Node child2){
        prefixElem = child1.prefixElem;
        suffixElem = child2.suffixElem;
        if(child1.prefixElem != child1.suffixElem){
            prefixCount = child1.prefixCount;        
        }
        else if(child1.suffixElem == child2.prefixElem){
            prefixCount = child1.prefixCount+child2.prefixCount;
        }
        else{
            prefixCount = child1.prefixCount;
        }
        if(child2.suffixElem != child2.prefixElem){
            suffixCount = child2.suffixCount;
        }
        else if(child1.suffixElem == child2.prefixElem){
            suffixCount = child2.suffixCount+child1.suffixCount;
        }
        else{
            suffixCount = child2.suffixCount;
        }
        maxCount = max(max(child1.maxCount, child2.maxCount), child1.suffixElem == child2.prefixElem?child1.suffixCount+child2.prefixCount:0);
    }
};

int arr[100001];
Node segTree[400004];

Node build(int left, int right, int sidx){
    if(left == right){
       segTree[sidx].init(arr[left]);
    }
    else if(left<right){
        int mid = (left+right)/2;
        segTree[sidx].merge(build(left, mid, 2*sidx), build(mid+1, right, 2*sidx+1));
    }
    return segTree[sidx];
}

Node query(int x, int y, int left, int right, int sidx){
    if(x == left && y == right){
        return segTree[sidx];
    }
    int mid = (left+right)/2;       
    if(y<=mid){
        return query(x, y, left, mid, 2*sidx);
    }
    else if(x>mid){
        return query(x, y, mid+1, right, 2*sidx+1);
    }
    else{
        Node node1 = query(x, mid, left, mid, 2*sidx);
        Node node2 = query(mid+1, y, mid+1, right, 2*sidx+1);
        Node node;
        node.merge(node1, node2);
        return node;
    }
}

int main(){
    int N, Q;
    while(true){
        cin>>N;
        if(!N){
            break;
        }
        cin>>Q;
        for(int i=1;i<=N;i++){
            scanf("%d", &arr[i]);
        }
        build(1, N, 1);
        while(Q--){
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%d\n", query(x, y, 1, N, 1).maxCount);
        }   
    }
    
    return 0;
}