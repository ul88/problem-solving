#include<iostream>
#include<vector>
#define INF 0xFFFFFFF
using namespace std;
int dist[101][101]={0,};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j) continue;
			dist[i][j]=INF;
		}
	}
	for(int i=0,a,b,c;i<M;i++){
		cin>>a>>b>>c;
		dist[a][b]=min(dist[a][b],c);
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				dist[j][k] = min(dist[j][i] + dist[i][k],dist[j][k]);
			}
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(dist[i][j] == INF) cout<<0<<" ";
			else cout<<dist[i][j]<<" ";
		}cout<<"\n";
	}
	return 0;
}
