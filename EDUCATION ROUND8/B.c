#include<stdio.h>
#include<string.h>
#define MAX 300009
using namespace std;
int main() {
	char ch[MAX];
	scanf("%s", ch);
	int n = strlen(ch);
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		int num ;
		num =  (ch[i] - '0');
		if (num % 4 == 0)
			cnt++;
	}
	for (int i = 1; i < n; i++) {
		int num = 0;
		num = num * 10 + (ch[i - 1] - '0');
		num = num * 10 + (ch[i] - '0');
		if (num % 4 == 0)
			cnt+=i;
	}
	printf("%lld\n", cnt);
	return 0;
}
