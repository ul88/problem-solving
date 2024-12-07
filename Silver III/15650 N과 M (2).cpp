#include<iostream>
#include<queue>
using namespace std;
queue <int> q;
int N,M;
int visit[10]={0,},arr[10]={0,};
void dfs(int n,int cnt){
	if(cnt==M){
		for(int i=0;i<M;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}else{
		for(int i=n;i<=N;i++){
			if(visit[i]==1) continue;
			visit[i]=1;
			arr[cnt]=i;
			dfs(i,cnt+1);
			visit[i]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>N>>M;
	dfs(1,0);
	return 0;
}
