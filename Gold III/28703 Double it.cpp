#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF INT64_MAX
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    ll ans=INF,m=0;
    cin>>N;
    priority_queue<ll,vector<ll>, greater<ll>> pq;

    for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        m=max(m,a);
        pq.push(a);
    }

    for(ll i=0;i<30*N;i++){
        ll now = pq.top();
        pq.pop();
        ans = min(ans,m-now);
        now*=2;
        m=max(m,now);
        pq.push(now);
    }

    cout<<ans;
    return 0;
}