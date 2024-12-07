#include<iostream>
#include<queue>
#include<vector>
#define INF 0xFFFFFFF
using namespace std;
int dist[200001]={0,};
int N,K,ans=INF;
void dijkstra(){
	priority_queue <pair<int,int> > pq;
	dist[N]=0;
	pq.push(make_pair(0,N));
	while(!pq.empty()){
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if(dist[now*2] > cost){
			dist[now*2]=cost;
			pq.push(make_pair(-dist[now*2],now*2));
		}
		if(dist[now+1] > cost+1 && now+1 <= K+1){
			dist[now+1] = cost+1;
			pq.push(make_pair(-dist[now+1],now+1));
		}
		if(dist[now-1] > cost+1 && now-1 >= 0){
			dist[now-1] = cost+1;
			pq.push(make_pair(-dist[now-1],now-1));
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>N>>K;
	for(int i=0;i<=100000;i++){
		dist[i]=INF;
	}
	dijkstra();
	cout<<dist[K];
	return 0;
}
