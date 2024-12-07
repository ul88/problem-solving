#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
vector <int> v;
map <int,int> m;
int N,S;
ll ans=0;
void dfs(int start,int end,ll cnt,int d){
    if(start>=end){
        if(d){
            m[cnt]++;
        }else{
            ans+=m[S-cnt];
        }
        return;
    }
    else{
        dfs(start+1,end,cnt+v[start],d);
        dfs(start+1,end,cnt,d);
    }
}
int main()
{
    cin>>N>>S;
    for(int i=0,a;i<N;i++){
        cin>>a;
        v.push_back(a);
    }
    dfs(N/2,N,0,1);
    dfs(0,N/2,0,0);

    if(S==0) ans--;
    cout<<ans;
    return 0;
}