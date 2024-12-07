#include<iostream>
#include<queue>
#include<vector>
#define INF 0xFFFFFFF
using namespace std;
vector <pair<int,int> > v[1001];
vector <int> route_v;
int route[1001]={0,};
int dist[1001]={0,};
void dijkstra(int start,int end){
	priority_queue <pair<int,int> > pq;
	dist[start] = 0;
	pq.push(make_pair(0,start));
	while(!pq.empty()){
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if(cost > dist[now]) continue;
		for(int i=0;i<v[now].size();i++){
			int next = v[now][i].first;
			int nCost = v[now][i].second + cost;
			if(dist[next] > nCost){
				dist[next] = nCost;
				route[next] = now;
				pq.push(make_pair(-nCost,next));
			}
		}	
	}
}
int main()
{
	int n,m,bus_start,bus_end;
	cin>>n>>m;
	for(int i=0,a,b,c;i<m;i++){
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
	}
	for(int i=1;i<=n;i++) dist[i]=INF;
	cin>>bus_start>>bus_end;
	dijkstra(bus_start,bus_end);
	cout<<dist[bus_end]<<'\n';
	int tmp=bus_end;
	while(tmp){
		route_v.push_back(tmp);
		tmp=route[tmp];
	}
	cout<<route_v.size()<<"\n";
	for(int i=route_v.size()-1;i>=0;i--) cout<<route_v[i]<<" ";
	return 0;
}
