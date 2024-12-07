#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
struct color{
	int Red_x;
	int Red_y;
	int Blue_x;
	int Blue_y;
	int Cost;
};
pair<int,int> Red;
pair<int,int> Blue;
queue <color> q;
string str[10];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int visit[11][11][11][11]={0,};
int N,M;

int bfs(){
	while(!q.empty()){
		int rx = q.front().Red_x;
		int ry = q.front().Red_y;
		int bx = q.front().Blue_x;
		int by = q.front().Blue_y;
		int cost = q.front().Cost;
		q.pop();
		if(cost >= 10) return -1;
		for(int i=0;i<4;i++){
			int nrx = rx;
			int nry = ry;
			int nbx = bx;
			int nby = by;
			
			while(1){
				nrx += dx[i];
				nry += dy[i];
				if(nrx < 0 || nrx >= N || nry < 0 || nry >= M) continue;
				if(str[nrx][nry] == '#'){
					nrx -= dx[i];
					nry -= dy[i];
					break;
				}
				else if(str[nrx][nry] == 'O'){
					break;
				}
			}
			while(1){
				nbx += dx[i];
				nby += dy[i];
				if(nbx < 0 || nbx >= N || nby < 0 || nby >= M) continue;
				if(str[nbx][nby] == '#'){
					nbx -= dx[i];
					nby -= dy[i];
					break;
				}
				else if(str[nbx][nby] == 'O'){
					break;
				}
			}
			if(str[nbx][nby] == 'O') continue;
			if(str[nrx][nry] == 'O') return cost+1;
			
			if(nrx == nbx && nry == nby){
				if(abs(rx - nrx) + abs(ry - nry) < abs(bx - nbx) + abs(by - nby)){
					nbx -= dx[i];
                    nby -= dy[i];
				}else{
					nrx -= dx[i];
                    nry -= dy[i];
				}
			}
			
			if(visit[nrx][nry][nbx][nby] == 0){
				visit[nrx][nry][nbx][nby]=1;
				q.push({nrx,nry,nbx,nby,cost+1});
			}
		}
	}
	return -1;
}
int main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>str[i];
		for(int j=0;j<M;j++){
			if(str[i][j] == 'R'){
				Red = make_pair(i,j);
			}else if(str[i][j] == 'B'){
				Blue = make_pair(i,j);
			}
		}
	}
	q.push({Red.first,Red.second,Blue.first,Blue.second,0});
	cout<<bfs();
	return 0;
}
