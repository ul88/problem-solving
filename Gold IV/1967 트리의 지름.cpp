#include<iostream>
#include<vector>
using namespace std;
vector <pair<int,int> > v[10001];
int visit[10001]={0,},ans=0,idx=0;
void dfs(int n,int cnt){
	if(visit[n]==1) return;
	visit[n]=1;
	if(ans < cnt){
		ans=cnt;
		idx=n;
	}
	for(int i=0;i<v[n].size();i++){
		dfs(v[n][i].first,cnt+v[n][i].second);
	}
	visit[n]=0;
}
int main()
{
	ios::sync_with_stdio(0);
	int N;
	cin>>N;
	for(int i=0,a,b,c;i<N-1;i++){
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	dfs(1,0);
	dfs(idx,0);
	cout<<ans;
	return 0;
}
