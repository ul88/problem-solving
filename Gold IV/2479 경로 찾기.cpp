#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
queue <int> q;
string S[1001];
string s[1001];
int visit[1001]={0,},N,K,a,b;
int arr[1001]={0,};
int bfs(){
	while(!q.empty()){
		int ans=q.front();
		q.pop();
		if(ans==b){
			return 0;
		}
		for(int i=1;i<=N;i++){
			int tmp=0;
			if(visit[i]==1 || i==ans) continue;
			for(int j=0;j<K;j++){
				if(S[i][j]!=S[ans][j]) tmp++;
			}
			if(tmp==1){
				visit[i]=1;
				arr[i]=ans;
				q.push(i);
			}
		}
	}
	return -1;
}
void printTrace(int n){
	if(n==0) return;
	printTrace(arr[n]);
	printf("%d ",n);
}
int main()
{
	cin>>N>>K;
	for(int i=1;i<=N;i++){
		cin>>S[i];
	}
	cin>>a>>b;
	visit[a]=1;
	q.push(a);
	int idx=bfs();
	if(idx==0){
		printTrace(b);
	}else cout<<-1;
	return 0;
}
