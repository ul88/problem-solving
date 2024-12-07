#include<iostream>
#include<vector>
#include<algorithm> 
#include<queue>
#define INF 0xFFFFFFF
using namespace std;
vector <pair<int,int> > v[51];
long long dist[51]={0,},earnCost[51]={0,};
queue <int> q; // BFS로 간선이 연결되어있는지를 확인 
int visit[51]={0,};
int N,M,start,last;
void bell(){ //BFS를 제외하곤 전형적인 벨만포드 
	dist[start]=earnCost[start];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(dist[j]==-INF) continue;
			for(int k=0;k<v[j].size();k++){
				int To = v[j][k].first;
				long long cost = dist[j]-v[j][k].second+earnCost[To];
				if(dist[To]<cost){
					dist[To]=cost;
					if(i==N-1){ //계속해서 증가하는 정점들을 모아둠 
						visit[j]=1;
						q.push(j);
					}
				}
			}
		}
	}
	
	if(dist[last]==-INF) cout<<"gg";
	else{
		while(!q.empty()){ //계속 해서 증가하는 정점들을 이어봤을 때 도착지점에 도달할 수 있는지 확인 
			int From=q.front();
			q.pop();
			for(int i=0;i<v[From].size();i++){
				int To=v[From][i].first;
				if(visit[To]==1) continue;
				visit[To]=1;
				q.push(To);
			}
		}
		if(visit[last]) cout<<"Gee";
		else cout<<dist[last];
	}
}
int main()
{
	cin>>N>>start>>last>>M;
	for(int i=0,a,b,c;i<M;i++){
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
	}
	for(int i=0;i<N;i++){
		cin>>earnCost[i];
		dist[i]=-INF;
	}
	bell();
	return 0;
}
