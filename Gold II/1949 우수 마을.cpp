#include<iostream>
#include<vector>
using namespace std;
int N,visit[10001]={0,},dp[2][10001]={0,},cost[10001]={0,};
vector <int> v[10001];
void dfs(int n){
	visit[n]=1;
	dp[0][n]=0;
	dp[1][n]=cost[n];
	for(int i=0;i<v[n].size();i++){
		if(visit[v[n][i]]==0){
			dfs(v[n][i]);
			dp[0][n]+=max(dp[0][v[n][i]],dp[1][v[n][i]]);
			dp[1][n]+=dp[0][v[n][i]];
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>N;
	for(int i=1;i<=N;i++) cin>>cost[i];
	for(int i=0,a,b;i<N-1;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout<<max(dp[0][1],dp[1][1])<<endl;
	return 0;
}
