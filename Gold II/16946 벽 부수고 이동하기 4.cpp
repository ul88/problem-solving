#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#define MAX 1001
using namespace std;
int N,M,idx=0;
int map[MAX][MAX]={0,},visit[MAX][MAX]={0,};
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int bfs(int n,int m){
	int cnt=0;
	queue <pair<int,int> > q;
	q.push(make_pair(n,m));
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			if(x+dx[i]<0 || x+dx[i]>=N || y+dy[i]<0 || y+dy[i]>=M) continue;
			if(map[x+dx[i]][y+dy[i]]==0 && visit[x+dx[i]][y+dy[i]]==0){
				visit[x+dx[i]][y+dy[i]]=idx;
				cnt++;
				q.push(make_pair(x+dx[i],y+dy[i]));
			}
		}
	}
	return cnt+1;
}
int main()
{
	vector <int> zero_count;
	zero_count.push_back(0);
	string str[1001];
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>str[i];
		for(int j=0;j<M;j++){
			map[i][j]=str[i][j]-48;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==0 && visit[i][j]==0){
				visit[i][j]=++idx;
				int cnt=bfs(i,j);
				zero_count.push_back(cnt);
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==1){
				vector <int> v;
				for(int k=0;k<4;k++){
					int nx=i+dx[k], ny=j+dy[k];
					if(nx<0 || nx>=N || ny<0 || ny>=M) continue; 
					v.push_back(visit[nx][ny]);
				}
				sort(v.begin(),v.end());
				v.push_back(0);
				for(int t=0;t<v.size();t++){
					if(v[t] == v[t+1] || v[t]==0) continue;
					map[i][j]+=zero_count[v[t]];
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<map[i][j]%10;
		} cout<<'\n';
	}
	return 0;
}
