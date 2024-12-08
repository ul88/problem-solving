#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using pii = pair<int,int>;
vector<vector<char>> v;
vector<vector<int>> visit;
int R,C;
pii bfs(int n, int m){
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, -1, 0, 1};
    pii animal = {0, 0};
    queue<pii> q;
    q.push({n,m});
    while(!q.empty()){
        pii now = q.front();
        q.pop();
        if(now.first < 0 || now.first >= R || now.second < 0 || now.second >= C) continue;
        if(visit[now.first][now.second]) continue;
        visit[now.first][now.second] = 1;
        if(v[now.first][now.second] == '#') continue;
        if(v[now.first][now.second] == 'o') animal.first++;
        if(v[now.first][now.second] == 'v') animal.second++;

        for(int i=0;i<4;i++){
            pii next = {now.first+dy[i], now.second+dx[i]};
            q.push(next);
        }
    }

    return animal;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>R>>C;
    v.resize(R, vector<char>());
    visit.resize(R, vector<int>(C));
    for(int i=0;i<R;i++){
        string a;
        cin>>a;
        
        for(auto j : a){
            v[i].push_back(j);
        }
    }

    pii ans;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(visit[i][j]) continue;
            pair<int,int> temp = bfs(i,j);
            if(temp.first > temp.second){
                ans.first += temp.first;
            }else{
                ans.second += temp.second;
            }
        }
    }

    cout<<ans.first<<" "<<ans.second<<"\n";
    return 0;
}