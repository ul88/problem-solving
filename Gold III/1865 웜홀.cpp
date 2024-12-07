#include<iostream>
#include<vector>
#define INF 0xFFFFFFF
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--){
		vector <pair<int, int> > v[2501];
		int dist[2501]={0,};
		int N,M,W;
		cin>>N>>M>>W;
		for(int i=1;i<=N;i++) dist[i]=INF;
		for(int i=0,a,b,c;i<M;i++){
			cin>>a>>b>>c;
			v[a].push_back(make_pair(b,c));
			v[b].push_back(make_pair(a,c));
		}
		for(int i=0,a,b,c;i<W;i++){
			cin>>a>>b>>c;
			v[a].push_back(make_pair(b,-c));
		}
		bool flag=false;
		for(int i=1;i<=N;i++){
			flag=false;
			for(int j=1;j<=N;j++){
				for(int k=0;k<v[j].size();k++){
					int From=v[j][k].first;
					int cost=dist[j]+v[j][k].second;
					if(dist[From]>cost){
						dist[From]=cost;
						flag=true;
					}
				}
			}
			if(!flag) break;
		}
		if(flag) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
	return 0;
}
