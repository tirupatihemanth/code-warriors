#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,b,p;
	cin>>n>>b>>p;
	int towels=0;
	int bottles=0;
	towels=n*p;
	while(n>1)
	{
		bottles+=(2*b+1)*(n/2);
		n=(n+1)/2;
	}
	cout<<bottles<<" "<<towels<<endl;
	return 0;
}
