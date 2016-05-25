#include <iostream>
#include <cstdio>

using namespace std;

int arr[50001];

typedef struct Node_ Node;

struct Node_{
    int maxSub;
    int maxPrefix;
    int maxSuffix;
    int sum;
    void init(int val){
        maxSub = val;
        maxPrefix = val;
        maxSuffix = val;
        sum = val;
    }
    void merge(Node child1, Node child2){
        maxPrefix = max(child1.maxPrefix, child1.sum+child2.maxPrefix);
        maxSuffix = max(child2.maxSuffix, child1.maxSuffix+child2.sum);
        maxSub = max(max(child1.maxSub, child2.maxSub), child1.maxSuffix+child2.maxPrefix);
        sum = child1.sum+child2.sum;
    }
};

Node segTree[200004];

Node update(int left, int right, int pos, int val, int sidx){
        if(left == right && right == pos){
            segTree[sidx].init(val);
            return segTree[sidx];
        }
        int mid = (left+right)/2;
        if(pos>mid){
            update(mid+1, right, pos, val, 2*sidx+1);
        }
        else if(pos<=mid){
            update(left, mid, pos, val, 2*sidx);
        }
        segTree[sidx].merge(segTree[2*sidx], segTree[2*sidx+1]);
        return segTree[sidx];
}

Node build(int left, int right, int sidx){
    if(left == right){
        segTree[sidx].init(arr[left]);
    }
    else if(left<right){
        int mid = (left+right)/2;
        Node node1 = build(left, mid, 2*sidx);
        Node node2 = build(mid+1, right, 2*sidx+1);
        segTree[sidx].merge(node1, node2);
    }
    return segTree[sidx];
}

Node query(int x, int y, int left, int right, int sidx){
    if(x == left && y == right){
        return segTree[sidx];
    }
    int mid = (left+right)/2;
    if(x > mid){
        return query(x, y, mid+1, right, 2*sidx+1);
    }
    else if(y<=mid){
        return query(x, y, left, mid, 2*sidx);
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
    int N, M;
    cin>>N;
    for(int i=1;i<=N;i++){
        scanf("%d", &arr[i]);
    }
    cin>>M;
    build(1, N, 1);
    while(M--){
        int z, x, y;
        scanf("%d%d%d", &z, &x, &y);
        if(z){
            printf("%d\n", query(x, y, 1, N, 1).maxSub);    
        }
        else{
            update(1, N, x, y, 1);
        }
        
    }
    return 0;
}