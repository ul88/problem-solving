#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector <int> graph[32001];
vector <int> v;
int N,M,visit[32001]={0,};
void dfs(int n){
	visit[n]=1;
	for(int i=0;i<graph[n].size();i++){
		if(!visit[graph[n][i]]){
			dfs(graph[n][i]);
		}
	}
	v.push_back(n);
}
int main()
{
	cin>>N>>M;
	for(int i=0,a,b;i<M;i++){
		cin>>a>>b;
		graph[b].push_back(a);
	}
	for(int i=1;i<=N;i++){
		if(!visit[i]) dfs(i);
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
