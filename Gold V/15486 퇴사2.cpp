#include<iostream>
#include<vector>
#define INF 0xFFFFFFF
using namespace std;
vector <pair<int,int> > v;
int memo[1500002]={0,};
int N,ans=0;
int dfs(int n){
	if(n==N+1) return 0;
	else if(n>N+1) return -INF;
	else if(memo[n]!=0);
	else{
		memo[n] = max(dfs(n+1),dfs(n+v[n-1].first)+v[n-1].second);
	}
	return memo[n];
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>N;
	for(int i=0,a,b;i<N;i++){
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	cout<<dfs(1);
	return 0;
}
