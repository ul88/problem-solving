#include<iostream>
#include<vector>
#include<queue>
#define INF 0xFFFFFFF
using namespace std;
vector <pair<int,int> > v[1001];
int dist[1001]={0,},dp[1001]={0,};
void dijkstra(){
	priority_queue <pair<int,int> > pq;
	dist[2]=0;
	dp[2]=1;
	pq.push(make_pair(0,2));
	while(!pq.empty()){
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if(dist[now] < cost) continue;
		for(int i=0;i<v[now].size();i++){
			int next = v[now][i].first;
			int nCost = cost + v[now][i].second;
			if(dist[next] > nCost){
				dist[next] = nCost;
				pq.push(make_pair(-nCost,next));
			}
			if(dist[next] < cost) dp[now] += dp[next];
		}
	}
}
int main()
{
	//1에서 2로 가는 합리적인 이동경로의 개수 
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;i++) dist[i]=INF;
	for(int i=0,a,b,c;i<M;i++){
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	dijkstra();
	cout<<dp[1];
	return 0;
}
