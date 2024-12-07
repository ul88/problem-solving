// 나중에 다시 공부하기
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define MAX 40000
#define LOG_MAX 16
using namespace std;
using pii = pair<int,int>;

vector <pii> tree[MAX+1];
int parent[MAX+1][LOG_MAX+1] = {0,};
int cost[MAX+1][LOG_MAX+1] = {0,};
int depth[MAX+1] = {0,};
bool visit[MAX+1] = {0,};
int N,M;

void dfs(int n,int d){
    visit[n] = 1;
    depth[n] = d;
    for(int i=0;i<tree[n].size();i++){
        int next = tree[n][i].first;
        int nCost = tree[n][i].second;
        if(visit[next]) continue;
        parent[next][0] = n;
        cost[next][0] = nCost;
        dfs(next,d+1);
    }
}

void findAncestor(){
    for(int i=1;i<LOG_MAX;i++){
        for(int j=1;j<=N;j++){
            int prevParent = parent[j][i-1];
            parent[j][i] = parent[prevParent][i-1];

            if(parent[prevParent][i-1] == 0) continue;

            int prevLength = cost[j][i-1];
            cost[j][i] = prevLength + cost[prevParent][i-1];
        }
    }
}

int LCA(int n,int m){
    if(depth[n] > depth[m]){
        swap(n,m);
    }

    int len=0;

    for(int i=LOG_MAX-1;i>=0;i--){
        int jump = 1 << i;
        if(depth[m] - depth[n] >= jump){
            len += cost[m][i];
            m = parent[m][i];
        }
    }

    if(n == m) return len;

    for(int i=LOG_MAX-1;i>=0;i--){
        if(parent[n][i] == parent[m][i]) continue;

        len += cost[n][i] + cost[m][i];
        n = parent[n][i];
        m = parent[m][i];
    }

    len += cost[n][0] + cost[m][0];
    return len;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    for(int i=0,a,b,c;i<N-1;i++){
        cin>>a>>b>>c;    
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }

    dfs(1,0);
    findAncestor();

    cin>>M;
    for(int i=0,a,b;i<M;i++){
        cin>>a>>b;
        cout<<LCA(a,b)<<"\n";
    }

    return 0;
}