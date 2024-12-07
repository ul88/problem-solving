#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector <pair<int,int> > wall[3];
int arr[9][9]={0,};
int N,M,ans=0;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
void bfs(){
	int visit[10][10]={0,},wall=0,virus=0;
	queue <pair<int,int> > q;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j]==1) wall++;
			if(arr[i][j]==2){
				q.push(make_pair(i,j));
				virus++;
			}
		}
	}
	while(!q.empty()){
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			if(nowX+dx[i] >= 0 && nowX+dx[i] < N && nowY+dy[i] >= 0 && nowY+dy[i] < M){
				if(arr[nowX+dx[i]][nowY+dy[i]] == 0 && visit[nowX+dx[i]][nowY+dy[i]]==0){
					visit[nowX+dx[i]][nowY+dy[i]]=1;
					q.push(make_pair(nowX+dx[i],nowY+dy[i]));
					virus++;
				}
			}
		}
	}
	ans=max(ans,N*M-wall-virus);
}
void wall_check(int cnt){
	if(cnt==3){
		bfs();
		return;
	}else{
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(arr[i][j]==0){
					arr[i][j]=1;
					wall_check(cnt+1);
					arr[i][j]=0;
				}
			}
		}
	}
}
int main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>arr[i][j];
		}
	}
	wall_check(0);
	cout<<ans;
	return 0;
}
