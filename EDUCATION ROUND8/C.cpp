#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	char ch1[n + 1], ch2[n + 1];
	scanf("%s", ch1);
	int len = strlen(ch1);
	for (int i = 0; i < len; i++) {
		int temp;
		if ((26 - (ch1[i] - 'a'+1)) >= (ch1[i] - 'a'))
			temp = (26 - (ch1[i] - 'a'+1));
		else
			temp =-1*(ch1[i] - 'a');
		if(temp>0)
		{
			temp = min(k, temp);
		}else
		{
			temp=max(-1*k,temp);
		}
		ch2[i] = ch1[i] + temp;
		if (temp > 0)
			k -= temp;
		else
			k += temp;
	}
	if (k == 0) {
		ch2[len] = '\0';
		printf("%s\n", ch2);
	} else
		printf("-1\n");
	return 0;
}
