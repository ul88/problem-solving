#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <pair<int,pair<int,int> > > graph;
vector <int> v;
int ans=0;
int parent[100001]={0,};
int Find(int n){
	if(n==parent[n]) return n;
	else return parent[n]=Find(parent[n]);
}
void Union(int x,int y){
	x=Find(x);
	y=Find(y);
	if(x == y) return;
	if(x<y){
		parent[y]=x;
	}
	else{
		parent[x]=y;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		parent[i]=i;
	}
	for(int i=0,a,b,c;i<M;i++){
		cin>>a>>b>>c;
		graph.push_back(make_pair(c,make_pair(a,b)));
	}
	sort(graph.begin(),graph.end());
	for(int i=0;i<M;i++){
		int a=graph[i].second.first,b=graph[i].second.second;
		if(Find(a)==Find(b)) continue;
		Union(a,b);
		v.push_back(graph[i].first);
	}
	for(int i=0;i<v.size()-1;i++){
		ans+=v[i];
	}
	cout<<ans;
	return 0;
}
