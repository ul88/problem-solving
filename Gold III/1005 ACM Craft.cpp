#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1001
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int N,K,W,D[MAX]={0,},degree[MAX]={0,},ans[MAX]={0,};
        vector <int> graph[MAX];
        queue <int> q;

        cin>>N>>K;
        for(int i=1;i<=N;i++){
            cin>>D[i];
        }
        for(int i=0,a,b;i<K;i++){
            cin>>a>>b;
            graph[a].push_back(b);
            degree[b]++;
        }
        cin>>W;

        for(int i=1;i<=N;i++){
            if(!degree[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int now = q.front();
            q.pop();
            if(now == W) break;
            for(int i=0;i<graph[now].size();i++){
                int next=graph[now][i];
                degree[next]--;
                ans[next] = max(ans[next],ans[now]+D[now]);
                if(!degree[next]){
                    q.push(next);
                }
            }
        }
        cout<<ans[W]+D[W]<<"\n";
    }
    return 0;
}