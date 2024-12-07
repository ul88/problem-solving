#include<iostream>
#include<queue>
#include<vector>
#define MAX 20
using namespace std;
struct shark{
    int row;
    int col;
    int eatFishCnt;
    int size;
    int cnt;

    bool operator < (const shark &s) const{
        if(cnt == s.cnt){
            if(row == s.row){
                return col > s.col;
            }
            return row > s.row;
        }
        return cnt > s.cnt;
    }
};
int fish[7]={0,},fishCnt=0;
int N,ans=0;
int arr[MAX+1][MAX+1]={0,},visit[MAX+1][MAX+1]={0,};
int dy[4] = {-1,0,0,1}, dx[4]={0,-1,1,0};
shark bfs(shark s){
    queue <shark> q;
    priority_queue <shark> pq;
    q.push(s);
    while(!q.empty()){
        shark now = q.front();
        q.pop();
        if(now.row < 0 || now.row >= N || now.col < 0 || now.col >= N) continue;
        if(visit[now.row][now.col]) continue;
        visit[now.row][now.col] = 1;
        if(arr[now.row][now.col] > now.size) continue;
        if(arr[now.row][now.col] != 0 && arr[now.row][now.col] < now.size){
            pq.push(now);
        }

        for(int i=0;i<4;i++){
            shark next = now;
            next.row += dy[i];
            next.col += dx[i];
            next.cnt++;
            q.push(next);
        }
    }

    if(pq.empty()) return s;
    s=pq.top();

    arr[s.row][s.col] = 0;
    
    s.eatFishCnt++;
    if(s.eatFishCnt >= s.size){
        s.size++;
        s.eatFishCnt = 0;
    }
    
    ans = s.cnt;
    return s;
}

int main()
{
    shark s;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0,a;j<N;j++){
            cin>>a;
            if(a == 9){
                s={i,j,0,2,0};
            }else if(a != 0){
                fish[a]++;
                fishCnt++;
                arr[i][j]=a;
            }
        }
    }

    for(int i=0;i<fishCnt;i++){
        s = bfs(s);
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++) visit[j][k] = 0;
        }
    }

    cout<<ans;
    return 0;
}