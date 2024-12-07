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
int N,M,ans=-1;
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
	while(!q.empty()){
		bool flag=false; // 파란색 구슬이 구멍에 들어갔을 떄를 확인하는 변수로 파란색 구슬이 구멍에 들어갔을 때는 q에 값을 넣으면 안됨 
		int Rx = q.front().Red_x;
		int Ry = q.front().Red_y;
		int Bx = q.front().Blue_x;
		int By = q.front().Blue_y;
		int cost = q.front().Cost;
		q.pop();
		if(cost >= 10){
			ans=-1;
			break;
		}
		//right
		int Ridx=Ry, Bidx=By;
		for(int i=Ry;i<M;i++){
			if(str[Rx][i] == 'O'){
				ans=cost+1;
				break;
			}
			if(str[Rx][i] == '#'){
				Ridx = i-1;
				break;
			}
		}
		for(int i=By;i<M;i++){
			if(str[Bx][i] == 'O'){
				ans=-1;
				flag=true;
				break;
			}
			if(str[Bx][i] == '#'){
				Bidx = i-1;
				break;
			}
		}
		if(Rx == Bx){
			if(Ridx==Bidx){
				if(Ry < By){
					Ridx--;
				}else{
					Bidx--;
				}
			}
		}
		if(ans>0) break;
		if(visit[Rx][Ridx][Bx][Bidx]==0 && Ridx>=0 && Ridx<M && Rx>=0 && Rx<N && Bidx>=0 && Bidx<M && Bx>=0 && Bx<N && flag==false){
			visit[Rx][Ridx][Bx][Bidx]=1;
			q.push({Rx,Ridx,Bx,Bidx,cost+1});
		} 
		
		//left
		flag=false;
		Ridx=Ry,Bidx=By;
		for(int i=Ry;i>=0;i--){
			if(str[Rx][i] == 'O'){
				ans=cost+1;
				break;
			}
			if(str[Rx][i] == '#'){
				Ridx = i+1;
				break;
			}
		}
		for(int i=By;i>=0;i--){
			if(str[Bx][i] =='O'){
				flag=true;
				ans=-1;
				break;
			}
			if(str[Bx][i] == '#'){
				Bidx = i+1;
				break;
			}
		}
		if(Rx == Bx){
			if(Ridx==Bidx){
				if(Ry < By){
					Bidx++;
				}else{
					Ridx++;
				}
			}
		}
		if(ans>0) break;
		if(visit[Rx][Ridx][Bx][Bidx]==0 && Ridx>=0 && Ridx<M && Rx>=0 && Rx<N && Bidx>=0 && Bidx<M && Bx>=0 && Bx<N && flag==false){
			visit[Rx][Ridx][Bx][Bidx]=1;
			q.push({Rx,Ridx,Bx,Bidx,cost+1});
		}
		
		//up
		flag=false;
		Ridx=Rx,Bidx=Bx;
		for(int i=Rx;i>=0;i--){
			if(str[i][Ry] =='O'){
				ans=cost+1;
				break;
			}
			if(str[i][Ry] == '#'){
				Ridx = i+1;
				break;
			}
		}
		for(int i=Bx;i>=0;i--){
			if(str[i][By]=='O'){
				flag=true;
				ans=-1;
				break;
			}
			if(str[i][By] == '#'){
				Bidx = i+1;
				break;
			}
		}
		if(Ry == By){
			if(Ridx==Bidx){
				if(Rx < Bx){
					Bidx++;
				}else{
					Ridx++;
				}
			}
		}
		if(ans>0) break;
		if(visit[Ridx][Ry][Bidx][By]==0 && Ridx>=0 && Ridx<N && Ry>=0 && Ry<M && Bidx>=0 && Bidx<N && By>=0 && By<M && flag==false){
			visit[Ridx][Ry][Bidx][By]=1;
			q.push({Ridx,Ry,Bidx,By,cost+1});
		}
		
		//down
		flag=false;
		Ridx=Rx, Bidx=Bx;
		for(int i=Rx;i<N;i++){
			if(str[i][Ry]=='O'){
				ans=cost+1;
				break;
			}
			if(str[i][Ry] == '#'){
				Ridx = i-1;
				break;
			}
		}
		for(int i=Bx;i<N;i++){
			if(str[i][By]=='O'){
				flag=true;
				ans=-1;
				break;
			}
			if(str[i][By] == '#'){
				Bidx = i-1;
				break;
			}
		}
		if(Ry == By){
			if(Ridx==Bidx){
				if(Rx < Bx){
					Ridx--;
				}else{
					Bidx--;
				}
			}
		}
		if(ans>0) break; //ans의 값이 양수로 바뀌면 값이 나온 것이므로 빼냄 
		if(visit[Ridx][Ry][Bidx][By]==0 && Ridx>=0 && Ridx<N && Ry>=0 && Ry<M && Bidx>=0 && Bidx<N && By>=0 && By<M && flag==false){
			visit[Ridx][Ry][Bidx][By]=1;
			q.push({Ridx,Ry,Bidx,By,cost+1});
		}
	}
	cout<<ans;
	return 0;
}
