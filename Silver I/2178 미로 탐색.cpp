#include<iostream>
#include<queue>
#include<vector>
#include<string>
#define MAX 100
#define INF INT32_MAX
using namespace std;
int main()
{
    int N,M;
    int arr[MAX+1][MAX+1]={0,},visit[MAX+1][MAX+1]={0,};
    int dy[4]={0,1,-1,0},dx[4]={1,0,0,-1};
    string str;
    queue <pair<pair<int,int> ,int> > q;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>str;
        int cnt = 0;
        for(auto iter:str){
            arr[i][cnt++] = iter-'0';
        }
    }

    int ans = INF;
    q.push({{0,0},0});
    while(!q.empty()){
        int nowY = q.front().first.first;
        int nowX = q.front().first.second;
        int nowCost = q.front().second;
        q.pop();
        if(nowY == N-1 && nowX == M-1){
            ans = min(ans,nowCost);
        }
        if(nowY < 0 || nowY >= N || nowX < 0 || nowX >= M) continue;
        if (arr[nowY][nowX]==0) continue; 
        if(visit[nowY][nowX]) continue;
        visit[nowY][nowX] = 1;

        for(int i=0;i<4;i++){
            q.push({{nowY+dy[i],nowX+dx[i]},nowCost+1});
        }
    }

    cout<<ans+1;
    return 0;
}