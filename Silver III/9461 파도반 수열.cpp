#include<iostream>
using namespace std;
long long dp[101]={0,};
long long P(long long n){
	if(dp[n]!=0) return dp[n];
	if(n<=3) return 1;
	else if(n<=5) return 2;
	else{
		return dp[n] = P(n-1)+P(n-5);
	} 
}
int main()
{
	int N;
	cin>>N;
	for(int i=0,a;i<N;i++){
		cin>>a;
		cout<<P((long long)a)<<endl;
	}
	return 0;
}
