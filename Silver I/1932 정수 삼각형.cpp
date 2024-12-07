#include<iostream>
using namespace std;
int main()
{
	int N,arr[501][501]={0,},dp[501][501]={0,};
	cin>>N;
	//초기화 
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) arr[i][j]=-1;
	}
	//삼각형 형태로 입력 
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			cin>>arr[i][j];
		}
	}
	dp[0][0]=arr[0][0];
	int ans=dp[0][0];
	for(int i=1;i<N;i++){
		for(int j=0;j<=i;j++){
			dp[i][j] = arr[i][j] + max((j-1<0 ? 0:dp[i-1][j-1]),(j<i ? dp[i-1][j] : 0));
			ans=max(ans,dp[i][j]);
		}
	}
	
	cout<<ans;
	return 0;
}