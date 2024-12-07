//조금더 빠른 코드 
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 0xFFFFFFF
using namespace std;
vector <pair<int,int> > v[10001];
vector <pair<int,int> > v_re[10001]; 
long long dist[10001]={0,};
long long out[10001]={0,};
int N,M,X;
void dijkstra(int n){
	//X에서 해당 정점으로 가는 다익스트라 
	priority_queue <pair<int,int> > pq;
	pq.push(make_pair(0,n));
	while(!pq.empty()){
		int From=pq.top().second;
		int cost=pq.top().first;
		pq.pop();
		if(cost>dist[From]) continue;
		for(int i=0;i<v[From].size();i++){
			int To=v[From][i].first;
			if(dist[To] > dist[From]+v[From][i].second){
				dist[To]=dist[From]+v[From][i].second;
				pq.push(make_pair(-dist[To],To));
			}
		}
	}
	//해당 정점에서 X로 돌아가는 역방향 그래프 
	pq.push(make_pair(0,n));
	while(!pq.empty()){
		int From=pq.top().second;
		int cost=pq.top().first;
		pq.pop();
		if(cost>dist[From]) continue;
		for(int i=0;i<v_re[From].size();i++){
			int To=v_re[From][i].first;
			if(out[To] > out[From]+v_re[From][i].second){
				out[To]=out[From]+v_re[From][i].second;
				pq.push(make_pair(-out[To],To));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long ans=0;
	cin>>N>>M>>X;
	for(int i=0,a,b,c;i<M;i++){
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
		v_re[b].push_back(make_pair(a,c));
	}
	for(int j=1;j<=N;j++){
		dist[j]=INF;
		out[j]=INF;
	}
	dist[X]=0;
	out[X]=0;
	dijkstra(X);
	for(int i=1;i<=N;i++) ans=max(ans,dist[i]+out[i]);
	cout<<ans;
	return 0;
} 
