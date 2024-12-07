#include<iostream>
using namespace std;
int f(int n){
	int hap=n;
	while(n!=0){
		hap+=n%10;
		n/=10;
	}
	return hap;
}
int main()
{
	int dp[10001]={0,};
	for(int i=1;i<=10000;i++){
		int p=f(i);
		if(p<=10000) dp[p]=1;
	}
	for(int i=1;i<10000;i++){
		if(dp[i]==0){
			cout<<i<<endl;
		}
	}
	return 0;
}
