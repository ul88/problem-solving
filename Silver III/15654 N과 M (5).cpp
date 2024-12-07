#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
queue <int> q;
int N,M;
int visit[10001]={0,},arr[10]={0,},save[10]={0,};
void dfs(int cnt){
	if(cnt==M){
		for(int i=0;i<M;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}else{
		for(int i=0;i<N;i++){
			if(visit[save[i]]==1) continue;
			visit[save[i]]=1;
			arr[cnt]=save[i];
			dfs(cnt+1);
			visit[save[i]]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++) cin>>save[i];
	sort(save,save+N);
	dfs(0);
	return 0;
}
