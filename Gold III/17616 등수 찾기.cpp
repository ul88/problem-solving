#include<iostream>
#include<vector>
#include<queue>
#define MAX 100000
using namespace std;
using pii = pair<int,int>;
vector <int> v1[MAX+1],v2[MAX+1];
int bfs(vector<int> v[], int n){
    int visit[MAX+1]={0,};
    int ans = 0;
    queue <int> q;
    q.push(n);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(visit[now]) continue;
        visit[now] = 1;
        ans++;
        for(int i=0;i<v[now].size();i++){
            int next = v[now][i];
            q.push(next);
        }
    }

    return ans-1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M,X;
    cin>>N>>M>>X;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        v1[a].push_back(b);
        v2[b].push_back(a);
    }

    cout<<bfs(v2,X)+1<<" "<<N-bfs(v1,X);
    return 0;
}