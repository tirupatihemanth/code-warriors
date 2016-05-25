#include <iostream>
#include <string>

using namespace std;

int main(){

	int n;	
	cin>>n;
	string str;
	cin>>str;
	int a=0,c=0,t=0,g=0;
	for(int i=0;i<n;i++){
		switch(str[i]){
			case 'A':
				a++;
				break;
			case 'C':
				c++;
				break;
			case 'T':
				t++;
				break;
			case 'G':
				g++;
		}
	}

	int al=0, cl=0, tl=0, gl=0;
	al = a-n/4;
	cl = c-n/4;
	tl = t-n/4;
	gl = g-n/4;
	int sum=0;
	if(al>0){
		sum+=al;
	}
	if(cl>0){
		sum+=cl;
	}
	if(tl>0){
		sum+=tl;
	}
	if(gl>0){
		sum+=gl;
	}
	if(sum==0){
		cout<<0<<endl;
		return 0;
	}
	int aa=0, cc=0, tt=0, gg=0;


	int i=0;
	bool gotcha = true;
	while(true){	
		for(int i=0;i<sum;i++){
			switch(str[i]){
				case 'A':
					aa++;
					break;
				case 'C':
					cc++;
					break;
				case 'T':
					tt++;
					break;
				case 'G':
					gg++;
			}
		}
		i=0;	
		while(i<n-sum){
			
			if(al>0 && aa<al){
				gotcha = false;
			}
			
			if(cl>0 && cc<cl){
				gotcha = false;
			}
			
			if(tl>0 && tt<tl){
				gotcha = false;
			}
			
			if(gl>0 && gg<gl){
				gotcha = false;
			}
			
			if(gotcha == true){
				cout<<sum<<endl;
				return 0;
			}
			switch(str[i]){
				case 'A':
					aa--;
					break;
				case 'C':
					cc--;
					break;
				case 'T':
					tt--;
					break;
				case 'G':
					gg--;
			}
			
			switch(str[i+sum]){
				case 'A':
					aa++;
					break;
				case 'C':
					cc++;
					break;
				case 'T':
					tt++;
					break;
				case 'G':
					gg++;
			}
			i++;
			gotcha = true;	
		}
		aa=0, cc=0, tt=0, gg=0;
		sum++;
	}	
	return 0;

}
