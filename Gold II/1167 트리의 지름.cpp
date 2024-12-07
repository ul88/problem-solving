#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector <pair<int,int> > v[100001];
int visit[100001]={0,},ans=0,idx=0;
void dfs(int n,int cnt){
	if(visit[n]==1) return;
	visit[n]=1;
	if(cnt>ans){
		ans=cnt;
		idx=n;
	}
	for(int i=0;i<v[n].size();i++){
		dfs(v[n][i].first, cnt+v[n][i].second);
	}
	visit[n]=0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int a=0,b=0,c=0;
		cin>>a;
		while(b!=-1){
			cin>>b;
			if(b!=-1){
				cin>>c;
				v[a].push_back(make_pair(b,c));
			}
		}
	}
	dfs(1,0);
	dfs(idx,0);
	cout<<ans;
	return 0;
}
