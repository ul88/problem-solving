#include<iostream>
#include<vector>
#include<queue>
#define MAX 200000
#define INF 1e17
using namespace std;
typedef long long ll;
vector <int> v[MAX+1];
ll cost[MAX+1]={0,};
ll dp[MAX+1] = {0,};
ll dp1[MAX+1] = {0,};
ll dp2[MAX+1] = {0,};
int visit[MAX+1]={0,};
ll dfs(int n){
    dp[n] = cost[n];
    for(auto iter : v[n]){
        dp[n] += max(0LL, dfs(iter));
    }
    return dp[n];
}

ll dfs1(int n){
    dp1[n] = dp[n];
    for(auto iter : v[n]){
        dp1[n] = max(dp1[n], dfs1(iter));
    }
    return dp1[n];
}

ll dfs2(int n){
    for(auto iter : v[n]){
        ll next = dfs2(iter);
        if(dp[iter] <= 0){
            dp2[n] = max(dp2[n], dp1[iter]);
        }else{
            dp2[n] = max(dp2[n], next);
        }
    }
    return dp2[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll ans = -INF;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        ll a;
        int b;
        cin>>a>>b;
        cost[i+1] = a;
        if(b==-1) continue;
        v[b].push_back(i+1);
    }

    for(int i=1;i<=N;i++){
        dp2[i] = -INF;
    }

    dfs(1);
    dfs1(1);
    dfs2(1);

    for(int i=1;i<=N;i++){
        ans = max(ans, dp[i] + dp2[i]);
        if(v[i].size() >= 2){
            priority_queue <ll> pq;
            for(auto iter : v[i]){
                pq.push(dp1[iter]);
            }
            ll now = pq.top();
            pq.pop();
            ans = max(ans, now+pq.top());
        }
    }

    cout<<ans;
    return 0;
}
/*
12
3 -1
-1 1
2 1
-2 1
4 2
4 3
3 3
2 3
4 4
2 4
-1 6
-2 6
*/