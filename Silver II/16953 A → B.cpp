#include<iostream>
#include<algorithm>
#define INF INT32_MAX
using namespace std;
typedef long long ll;
int A,B,ans=INF;
void dfs(ll n,int cnt){
    if(n==B){
        ans = min(ans,cnt+1);
        return;
    }
    if(n > B) return;
    dfs(n*2,cnt+1);
    dfs(n*10+1,cnt+1);
}
int main()
{
    cin>>A>>B;

    dfs(A,0);

    if(ans == INF) ans = -1;

    cout<<ans;
    return 0;
}