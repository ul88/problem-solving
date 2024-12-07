#include<iostream>
#include<queue>
#define MAX 100
using namespace std;
using pii = pair<int,int>;
int arr[MAX+1][MAX+1]={0,};
int N,M,cnt=0;
int dy[] = {-1,0,1,0}, dx[] = {0,-1,0,1};
void bfs(){
    queue <pii> q;
    q.push({0,0});
    int visit[MAX+1][MAX+1]={0,};
    int temp[MAX+1][MAX+1] = {0,};
    while(!q.empty()){
        int nowN = q.front().first;
        int nowM = q.front().second;
        q.pop();
        if(nowN < 0 || nowN >= N || nowM < 0 || nowM >= M) continue;
        if(arr[nowN][nowM] == 1){
            temp[nowN][nowM]++;
            continue;
        }
        if(visit[nowN][nowM]) continue;
        visit[nowN][nowM] = 1;
        int cnt = 0;
        for(int i=0;i<4;i++){
            int nextN = nowN + dy[i];
            int nextM = nowM + dx[i];
            q.push({nextN,nextM});
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(temp[i][j] >= 2){
                arr[i][j] = 0;
                cnt--;
            }
        }
    }
}
int main()
{
    int ans=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
            if(arr[i][j] == 1) cnt++;
        }
    }

    while(cnt > 0){
        bfs();
        ans++;
    }

    cout<<ans;
    return 0;
}