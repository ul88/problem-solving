#include<iostream>
#include<vector>
#define MAX 1000000
using namespace std;
vector <int> v[MAX+1];
int dp[2][MAX+1]={0,},visit[MAX+1]={0,}; 
//0 : 얼리아답터가 아닐 때 
//1 : 얼리아답터가 맞을 때 
void dfs(int n){
	visit[n]=1;
	dp[1][n]=1;
	for(int i=0;i<v[n].size();i++){
		if(visit[v[n][i]]==1) continue;
		visit[v[n][i]]=1;
		dfs(v[n][i]);
		dp[0][n]+=dp[1][v[n][i]];
		dp[1][n]+=min(dp[1][v[n][i]],dp[0][v[n][i]]);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	int N;
	cin>>N;
	for(int i=0,a,b;i<N-1;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout<<min(dp[0][1],dp[1][1]);
	return 0;
}
