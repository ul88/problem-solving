#include<iostream>
#include<queue>
#define MAX 50
using namespace std;
struct car{
    int dir;
    int n;
    int m;
    int cost;
    int k;
};
int arr[MAX+1][MAX+1]={0,}; // 0: 위 -> 1, 3, 5
                            // 0: 왼쪽 -> 2, 3, 4
                            // 1: 아래 -> 2, 3, 4
                            // 1: 오른쪽 -> 0, 2, 5
                            // 2: 아래 -> 1, 3, 5
                            // 2: 왼쪽 -> 0, 1, 4
                            // 3: 오른쪽 -> 0, 1, 4
                            // 3: 아래 -> 0, 2, 5
                            // 4: 위 -> 0, 1, 4
                            // 4: 아래 -> 2, 3, 4
                            // 5: 오른쪽 -> 1, 3, 5
                            // 5: 왼쪽 -> 0, 2, 5
int dy[] = {1,-1,0,0}, dx[] = {0,0,-1,1};
int visit[MAX+1][MAX+1]={0,};
// dir 
// 0 : 아래
// 1: 위 
// 2: 왼
// 3: 오
bool check(int dir, int now, int next){
    if(now == 0){
        if(dir == 1) return next == 1 || next == 3 || next == 5;
        else if(dir == 2) return next == 2 || next == 3 || next == 4;
    }
    else if(now == 1){
        if(dir == 0) return next == 2 || next == 3 || next == 4;
        else if(dir == 3) return next == 0 || next == 2 || next == 5;
    }
    else if(now == 2){
        if(dir == 0) return next == 1 || next == 3 || next == 5;
        else if(dir == 2) return next == 0 || next == 1 || next == 4;
    }
    else if(now == 3){
        if(dir == 3) return next == 0 || next == 1 || next == 4;
        else if(dir == 0) return next == 0 || next == 2 || next == 5;
    }
    else if(now == 4){
        if(dir == 1) return next == 0 || next == 1 || next == 4;
        else if(dir == 0) return next == 2 || next == 3 || next == 4;
    }
    else{
        if(dir == 3) return next == 1 || next == 3 || next == 5;
        else if(dir == 2) return next == 0 || next == 2 || next == 5;
    }
    return false;
}
// dir 
// 0 : 아래
// 1: 위 
// 2: 왼
// 3: 오
int returnDir(int dir, int now){
    if(now == 0){
        if(dir == 2) return 0;
        else if(dir == 1) return 3;
    }
    else if(now == 1){
        if(dir == 3) return 0;
        else if(dir == 1) return 2;
    }
    else if(now == 2){
        if(dir == 0) return 3;
        else if(dir == 2) return 1;
    }
    else if(now == 3){
        if(dir == 0) return 2;
        else if(dir == 3) return 1;
    }
    else if(now == 4){
        if(dir == 0) return 0;
        else if(dir == 1) return 1;
    }
    else{
        if(dir == 2) return 2;
        else if(dir == 3) return 3;
    }
    return 0;
}

int bfs(int N, int k){
    queue <car> q;
    q.push({3,0,0,0,k});
    q.push({0,0,0,0,k});
    while(!q.empty()){
        car now = q.front();
        q.pop();
        if(now.n == N-1 && now.m == N-1){
            return now.cost;
        }
        cout<<now.n<<" "<<now.m<<"\n";
        for(int i=0;i<4;i++){
            int nextY = now.n + dy[i];
            int nextX = now.m + dx[i];
            if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N) continue;
            if(check(now.dir, arr[now.n][now.m], arr[nextY][nextX])){
                if(visit[nextY][nextX]) continue;
                visit[nextY][nextX] = 1;
                q.push({returnDir(now.dir,arr[nextY][nextX]), nextY, nextX, now.cost+1, now.k});    
            }else{
                if(now.k == 0) continue;
                for(int i=0;i<=5;i++){
                    if(check(now.dir,arr[now.n][now.m],i)){
                        nextY += dy[returnDir(now.dir,i)];
                        nextX += dx[returnDir(now.dir,i)];
                        if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N) continue;
                        if(visit[nextY][nextX]) continue;
                        visit[nextY][nextX] = 1;
                        q.push({returnDir(now.dir,i), nextY, nextX, now.cost+1, 0});
                    }
                }
            }
        }

    }

    return -1;
}

int main()
{
    int N,k;
    cin>>N>>k;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    cout<<bfs(N,k);
    return 0;
}