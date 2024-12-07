#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1000
using namespace std;
int visit[MAX+1]={0,};
vector<int> v[MAX+1];
void dfs(int n){
    if(visit[n]) return;
    visit[n] = 1;
    cout<<n<<" ";
    for(int i=0;i<v[n].size();i++){
        dfs(v[n][i]);
    }
}

void bfs(int n){
    queue <int> q;
    q.push(n);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(visit[now]) continue;
        visit[now] = 1;
        cout<<now<<" ";
        for(int i=0;i<v[now].size();i++){
            q.push(v[now][i]);
        }
    }
}

int main()
{
    int N,M,V;
    cin>>N>>M>>V;
    for(int i=0,a,b;i<M;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=N;i++){
        sort(v[i].begin(),v[i].end());
    }
    dfs(V);
    cout<<"\n";
    for(int i=1;i<=N;i++) visit[i] = 0;
    bfs(V);
    return 0;
}