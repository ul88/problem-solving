#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    ll ans = 0;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    for(int i=0;i<N;i++){
        if(v[i] == 0) continue;
        int cnt = v[i];
        ans += 3*cnt;
        if(i > N-2) continue;
        cnt = min(cnt, v[i+1]);
        ans += 2*cnt;
        v[i+1] -= cnt;
        if(i > N-3) continue;
        cnt = min(cnt, v[i+2] - min(v[i+2],v[i+1]));
        ans += 2*cnt;
        v[i+2] -= cnt;
    }

    cout<<ans;
    return 0;
}