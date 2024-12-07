#include<iostream>
#include<vector>
#define INF 0xFFFFFFF
using namespace std;
vector <pair<int,int> > v[501];
long long dist[501]={0,},N,M;
bool flag =false;
void bell(int n){
	for(int i=1;i<=N;i++){
		flag=false;
		for(int j=1;j<=N;j++){
			if(dist[j]==INF) continue;
			for(int k=0;k<v[j].size();k++){
				int From=v[j][k].first;
				if(dist[From]>dist[j]+v[j][k].second){
					dist[From]=dist[j]+v[j][k].second;
					flag=true;
				}
			}
		}
		if(!flag) break;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N>>M;
	for(int i=2;i<=N;i++){
		dist[i]=INF;
	}
	for(int i=0,a,b,c;i<M;i++){
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
	}
	dist[1]=0;
	bell(1);
	if(flag==true) cout<<-1<<"\n";
	else{
		for(int i=2;i<=N;i++){
			if(dist[i]==INF) cout<<-1<<"\n";
			else cout<<dist[i]<<"\n";
		}
	}
	return 0;
}
