#include<iostream>
#include<queue>
#include<algorithm>
#define INF 0xFFFFFFF
using namespace std;
typedef struct busST{
	int start;
	int last;
	int cost;
}busst;
busst bus[100001]={0,};
int dist[1001]={0,};
int N,M,A,B;
void dtra(int n){
	priority_queue <pair<int,int> > pq;
	dist[n]=0;
	pq.push(make_pair(0,n));
	while(!pq.empty()){
		int To = pq.top().second;
		int cost= -pq.top().first;
		pq.pop();
		if(dist[To]<cost) continue;
		for(int i=0;i<M;i++){
			if(bus[i].start==To){
				int From=bus[i].last;
				if(dist[From]>dist[To]+bus[i].cost){
					dist[From]=dist[To]+bus[i].cost;
					pq.push(make_pair(-dist[From],From));
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		dist[i]=INF;
	}
	for(int i=0;i<M;i++){
		cin>>bus[i].start>>bus[i].last>>bus[i].cost;
	}
	cin>>A>>B;
	dtra(A);
	cout<<dist[B];
	return 0;
}
