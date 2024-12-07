#include<iostream>
#include<queue>
using namespace std;
struct st{
	int breakCount;
	int x;
	int y;
	int distance;
};
int arr[1001][1001]={0,},visit[2][1001][1001]={0,};
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int N,M;
int bfs(){
	queue <st> q;
	q.push({1,0,0,1});
	while(!q.empty()){
		int flag = q.front().breakCount;
		int n = q.front().x;
		int m = q.front().y;
		int dis = q.front().distance;
		q.pop();
		if(n==N-1 && m==M-1) return dis;
		if(visit[flag][n][m]==1) continue;
		visit[flag][n][m]=1;
		for(int i=0;i<4;i++){
			if(n+dx[i] < 0 || m+dy[i] < 0 || n+dx[i] >= N || m+dy[i] >= M) continue;
			if(arr[n+dx[i]][m+dy[i]] == 0){
				q.push({flag,n+dx[i],m+dy[i],dis+1});
			}else{
				if(flag==1){
					q.push({0,n+dx[i],m+dy[i],dis+1});
				}
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	printf("%d",bfs());
	return 0;
}
