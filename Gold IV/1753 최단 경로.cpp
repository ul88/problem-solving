#include<iostream>
#include<vector>
#include<queue>
#define INF 0xFFFFFFF
using namespace std;
vector <pair<int,int> > v[20001];
int dist[20001]={0,};
void dijkstra(int n){
	dist[n]=0;
	priority_queue <pair<int,int> > pq;
	pq.push(make_pair(0,n));
	while(!pq.empty()){
		int now = pq.top().second;
		int Cost = -pq.top().first;
		pq.pop();
		if(dist[now] < Cost) continue;
		for(int i=0;i<v[now].size();i++){
			int next = v[now][i].first;
			int nCost = dist[now] + v[now][i].second;
			if(dist[next] > nCost){
				dist[next] = nCost;
				pq.push(make_pair(-dist[next],next));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N,M,start=0;
	cin>>N>>M>>start;
	for(int i=1;i<=N;i++){
		dist[i]=INF;
	}
	for(int i=0,a,b,c;i<M;i++){
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
	}
	dijkstra(start);
	for(int i=1;i<=N;i++){
		if(dist[i]==INF) cout<<"INF"<<'\n';
		else cout<<dist[i]<<'\n';
	}
	return 0;
}
