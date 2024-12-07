#include<iostream>
#include<vector>
#include<queue>
#define MAX 100
using namespace std;
vector<int> v[MAX+1];
int visit[MAX+1][MAX+1]={0,};
int bfs(int start, int end){
    queue <pair<int,int> > q;
    q.push({start,0});
    while(!q.empty()){
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(now == end){
            return cnt;
        }
        for(int i=0;i<v[now].size();i++){
            int next = v[now][i];
            if(visit[now][next]) continue;
            visit[now][next] = 1;
            q.push({next,cnt+1});
        }
    }
    return -1;
}
int main()
{
    int N,M,start,end;
    cin>>N>>start>>end>>M;
    for(int i=0,a,b;i<M;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout<<bfs(start,end);
    return 0;
}