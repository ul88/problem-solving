#include<iostream>
#include<string>
#define MAX 1001
using namespace std;
string str[MAX];
int visit[MAX][MAX]={0,};
int N,M,cnt=0;
void dfs(int n,int m){
	if(visit[n][m]==1) cnt++;
	else if(visit[n][m]==0){
		visit[n][m]=1;
		if(str[n][m]=='U'){
			dfs(n-1,m);
		}else if(str[n][m]=='D'){
			dfs(n+1,m);
		}else if(str[n][m]=='L'){
			dfs(n,m-1);
		}else{
			dfs(n,m+1);
		}
		visit[n][m]=2;
	}
}
int main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>str[i];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(visit[i][j]==0) dfs(i,j);
		}
	}
	cout<<cnt;
	return 0;
}
