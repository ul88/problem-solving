#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>
#define INF INT32_MAX
using namespace std;
typedef long long ll;
int main()
{
    stack <pair<int,int>> s;
    map <int,int> m;
    int N;
    ll ans=0;
    cin>>N;
    vector <int> v(N+1,0);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }   

    s.push({0,v[0]});
    ans = v[0];
    for(int i=1;i<=N;i++){
        while(!s.empty() && s.top().second > v[i]){
            int nowIdx = s.top().first;
            int now = s.top().second;
            s.pop();
            if(s.empty()){
                ans = max(ans,(ll)(i-1)*now);
            }
            else ans = max(ans,(ll)(i-s.top().first-1)*now);
        }
        s.push({i,v[i]});
    }

    cout<<ans;

    return 0;
}
