#include<iostream>
#include<vector>
using namespace std;
vector <pair<int,int> > v;
int N,ans=0;
void dfs(int n,int hap){
	if(n==N+1){
		ans=max(ans,hap);
		return;
	}
	else if(n>N+1) return;
	else{
		dfs(n+1,hap);
		dfs(n+v[n-1].first,hap+v[n-1].second);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>N;
	for(int i=0,a,b;i<N;i++){
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
