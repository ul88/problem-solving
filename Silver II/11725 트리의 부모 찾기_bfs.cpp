#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector <int> v[100001];
int visit[100001]={0,};
int parent[100001]={0,};
void bfs(){
	queue <int> q;
	q.push(1);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i=0;i<v[now].size();i++){
			int next = v[now][i];
			if(visit[next]==1) continue;
			visit[next]=1;
			parent[next] = now;
			q.push(next);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int N;
	cin>>N;
	for(int i=0,a,b;i<N-1;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	for(int i=2;i<=N;i++){
		cout<<parent[i]<<"\n";
	}
	return 0;
}
