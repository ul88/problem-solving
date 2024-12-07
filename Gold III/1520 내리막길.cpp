#include<iostream>
using namespace std;
int N,M;
int map[501][501]={0,},dp[501][501]={0,},visit[501][501]={0,};
int x[4]={1,0,-1,0}, y[4]={0,1,0,-1};
int cnt=0;
int dfs(int n,int m){
	if(dp[n][m]!=-1) return dp[n][m];
	if(n==N-1 && m==M-1){
		return 1;
	}
	else{
		dp[n][m]=0;
		for(int i=0;i<4;i++){
			if(n+x[i]<0 || m+y[i]<0 || n+x[i]>=N || m+y[i]>=M) continue;
			if(map[n][m] > map[n+x[i]][m+y[i]]){
				dp[n][m]+=dfs(n+x[i],m+y[i]);
			}
		}
	}
	return dp[n][m];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
			dp[i][j]=-1;
		}	
	}
	cout<<dfs(0,0);	
	return 0;
}
