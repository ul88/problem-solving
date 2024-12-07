#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define INF INT32_MAX
using namespace std;
using pii = pair<int,int>;
int main()
{
    vector<pii> v;
    int N,cnt = 0;
    int start = INF, end = -INF;
    cin>>N;
    for(int i=0,a,b;i<N;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());
    
    int ans = max(v[N-1].first,v[N-1].second);
    
    for(int i=N-2;i>=0;i--){
        int dis = abs(v[i+1].first - v[i].first);
        ans = max(ans+dis,v[i].second);
    }

    cout<<ans+v[0].first;
    return 0;
}