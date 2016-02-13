#include <iostream>
#include <cstdio>

using namespace std;

int arr[50001];

typedef struct Node_{
    int maxSub;
    int maxPrefixSub;
    int maxSuffixSub;
    void merge(Node child1, Node child2){
        
    }
} Node;

Node segTree[200004]

int main(){
    int N, M;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    cin>>M;
    build(1, N, 1);
    while(M--){
        
    }
    return 0;
}