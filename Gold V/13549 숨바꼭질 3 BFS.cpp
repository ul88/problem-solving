#include<iostream>
#include<queue>
#include<vector>
#define MAX 100001
using namespace std;
int visit[100001]={0,};
int N,K;
int bfs(){
	priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
	visit[N]=1;
	pq.push(make_pair(0,N));
	while(!pq.empty()){
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if(now==K) return cost;
		
		if(now*2 < MAX && visit[now*2]==0 ){
			visit[now*2]=1;
			pq.push(make_pair(cost,now*2));
		}
		if(now+1 < MAX && visit[now+1]==0){
			visit[now+1] = 1;
			pq.push(make_pair(cost+1,now+1));
		}
		if(now-1 >=0 && visit[now-1]==0){
			visit[now-1]=1;
			pq.push(make_pair(cost+1,now-1));
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>N>>K;
	cout<<bfs();
	return 0;
}
