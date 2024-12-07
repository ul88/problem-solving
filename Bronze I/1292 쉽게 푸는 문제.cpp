#include<iostream>
using namespace std;
int main()
{
	int N,M,hap=0;
	int a[1001]={0,},tmp=1,last=0;
	for(int i=1;i<=1000;i++){
		a[i]=tmp;
		if(last+tmp==i){
			last=i;
			tmp++;
		}
	}
	cin>>N>>M;
	for(int i=N;i<=M;i++){
		hap+=a[i];
	}
	cout<<hap;
	return 0;
}
