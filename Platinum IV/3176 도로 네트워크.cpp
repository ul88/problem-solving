#include<iostream>
#include<vector>
#include<cmath>
#define MAX 100000
#define LOG_MAX (int)log2(MAX)
using namespace std;
using pii = pair<int,int>;

vector<pii> graph[MAX+1];
vector<vector<int> > parent(MAX+1, vector<int>(LOG_MAX+1));
vector<int> depth(MAX+1, -1);

void dfs(int n){
    for(auto next : graph[n]){
        if(depth[next.first] == -1){
            parent[next.first][0] = next.second;
            depth[next.first] = depth[n] + 1;
            dfs(next.first);
        }
    }
}

void connection(int size){
    for(int k=1;k<=(int)log2(size);k++){
        for(int i = 1;i<=size;i++){
            parent[i][k] = parent[parent[i][k-1]][k-1];
        }
    }
}

int LCA(int u, int v, int size){
    if(depth[u] < depth[v]){
        swap(u,v);
    }

    int diff = depth[u] - depth[v];

    for(int i=0;diff!=0;i++){
        if(diff%2 == 1) u = parent[u][i];
        diff/=2;
    }

    if(u!=v){
        for(int i=(int)log2(size);i>=0;i--){
            if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        u = parent[u][0];
    }

    return u;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    dfs(1);
    connection(N);

    int K;
    cin>>K;
    for(int i=0;i<K;i++){
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b,N)<<"\n";
    }
    return 0;
}