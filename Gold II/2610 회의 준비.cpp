#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0xFFFFFFF
using namespace std;
vector <int> v[100];
priority_queue <int, vector<int>, greater<int> > pq;
int dist[101][101]={0,},visit[101]={0,},hap[101]={0,};
void bfs(int n){
	queue <int> q;
	queue <int> save;
	int mingap=INF,idx=0;
	q.push(n);
	save.push(n);
	visit[n]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<v[now].size();i++){
			if(visit[v[now][i]]==1) continue;
			q.push(v[now][i]);
			save.push(v[now][i]);
			visit[v[now][i]]=1;
		}
	}
	while(!save.empty()){
		if(mingap>hap[save.front()]){
			mingap=hap[save.front()];
			idx=save.front();
		}
		save.pop();
	}
	pq.push(idx);
}
int main()
{
	ios_base::sync_with_stdio(0);
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j) continue;
			dist[i][j]=INF;
		}
	}
	for(int i=0,a,b;i<M;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
		dist[a][b]=1;
		dist[b][a]=1;
	}
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(dist[i][j]==INF) continue;
			hap[i]=max(hap[i],dist[i][j]);
		}
	}
	for(int i=1;i<=N;i++){
		if(visit[i]==1) continue;
		bfs(i);
	}
	cout<<pq.size()<<endl;
	while(!pq.empty()){
		cout<<pq.top()<<endl;
		pq.pop();
	}
	return 0;
}
