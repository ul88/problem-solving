#include<iostream>
using namespace std;
int dp[1000001]={0,};
int fibo(int n){
	if(n<=1) return 1;
	else if(dp[n]!=0) return dp[n];
	else{
		return dp[n]=(fibo(n-1) + fibo(n-2))%15746;
	}
}
int main()
{
	int N;
	cin>>N;
	cout<<fibo(N);
	return 0;
}
