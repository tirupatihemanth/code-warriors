#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int arr[100001];
pair<int, int> segTree[400004];

pair<int, int> build(int left, int right, int sidx){
    if(left == right){
        segTree[sidx].first = arr[left];
        segTree[sidx].second = 0;
    }
    else if(left<right){
        pair<int, int> p1 = build(left, (left+right)/2, 2*sidx);
        pair<int, int> p2 = build((left+right)/2+1, right, 2*sidx+1);
        segTree[sidx].first = max(p1.first, p2.first);
        if(segTree[sidx].first!=p1.first){
            if(p1.first>=max(p1.second, p2.second)){
                segTree[sidx].second = p1.first; 
            }
            else{
                segTree[sidx].second = max(p1.second, p2.second);
            }
        }
        else if(p2.first>=max(p1.second, p2.second)){
            segTree[sidx].second = p2.first;
        }
        else{
            segTree[sidx].second = max(p1.second, p2.second);
        }
    }    
    return segTree[sidx];
}

pair<int, int> query(int x, int y, int left, int right, int sidx){
    int mid = (left+right)/2;
    if(x == left && y == right){
        return segTree[sidx];
    }
    if(y<=mid){
        return query(x, y, left, mid, 2*sidx);
    }
    else if(x>mid){
        return query(x, y, mid+1, right, 2*sidx+1);
    }
    else{
        pair<int, int> p;
        pair<int, int> p1 = query(x, mid, left, mid, 2*sidx);
        pair<int, int> p2 = query(mid+1, y, mid+1, right, 2*sidx+1);
        p.first = max(p1.first, p2.first);
        if(p.first!=p1.first){
            if(p1.first>=max(p1.second, p2.second)){
                p.second = p1.first; 
            }
            else{
                p.second = max(p1.second, p2.second);
            }
        }
        else if(p2.first>=max(p1.second, p2.second)){
            p.second = p2.first;
        }
        else{
            p.second = max(p1.second, p2.second);
        }
        return p;
    }
}

pair<int, int> update(int left, int right, int pos, int val, int sidx){
    if(left == right && (right == pos)){
        segTree[sidx].first = val;
        return segTree[sidx];
    }
    int mid = (left + right)/2;
    if(pos<=mid){
        update(left, mid, pos, val, 2*sidx);
    }
    else if(pos>mid){
        update(mid+1, right, pos, val, 2*sidx+1);
    }
    pair<int, int> p1 = segTree[2*sidx];
    pair<int, int> p2 = segTree[2*sidx+1];
    segTree[sidx].first = max(p1.first, p2.first);
    if(segTree[sidx].first!=p1.first){
        if(p1.first>=max(p1.second, p2.second)){
            segTree[sidx].second = p1.first; 
        }
        else{
            segTree[sidx].second = max(p1.second, p2.second);
        }
    }
    else if(p2.first>=max(p1.second, p2.second)){
        segTree[sidx].second = p2.first;
    }
    else{
        segTree[sidx].second = max(p1.second, p2.second);
    }
    return segTree[sidx];
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d", arr+i);
    }
    build(1, n, 1);
    int m, x, y;
    char c;
    cin>>m;
    while(m--){
        cin>>c>>x>>y;
        if(c == 'Q'){
            pair<int, int> p = query(x, y, 1, n, 1);
            cout<<p.first+p.second<<endl;
        }
        else{
            update(1, n, x, y, 1);
        }
    }
    return 0;
}