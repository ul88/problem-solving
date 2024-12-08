#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<int,int>;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pii> v;
    int N,L;
    cin>>N>>L;
    v.reserve(N);
    for(int i=0;i<N;i++){
        int a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());

    int ans = 0;
    int end = 0;
    for(int i=0;i<N;i++){
        if(v[i].first < end) v[i].first = end;
        if(v[i].second < end) continue;
        int diff = v[i].second - v[i].first;
        ans += diff/L + (diff%L != 0);
        end = v[i].first + (diff/L+(diff%L != 0))*L;
    }

    cout<<ans;
    return 0;
}