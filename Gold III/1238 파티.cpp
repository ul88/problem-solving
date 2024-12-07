//기본 풀이 
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 0xFFFFFFF
using namespace std;
vector <pair<int,int> > v[10001];
long long dist[10001]={0,};
long long out[10001]={0,};
int N,M,X;
void dijkstra(int n){
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
	}
	for(int i=1;i<=N;i++) dist[i]=INF;
	dist[X]=0;
	dijkstra(X);
	for(int i=1;i<=N;i++) out[i]=dist[i]; 
	//X칸에서 시작하면 X칸에서 i칸들로 들어가는 값들을 알려준다.
	//그 값들을 out이라는 새로운 배열안에 넣어둔다. 
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++) dist[j]=INF;
		if(i!=X){
			dist[i]=0;
			dijkstra(i);
			//X칸은 구해뒀으므로 X칸을 제외하고 i칸들에서 다익스트라 사용 
			ans=max(ans,dist[X]+out[i]); //i값에서 X값으로 가는 거리+out배열에서 i값으로 가는 거리 
		}
	}
	cout<<ans;
	return 0;
}

