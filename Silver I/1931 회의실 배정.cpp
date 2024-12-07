#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using pii = pair<int,int>;
bool com(pii a, pii b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector <pii> v;
    int N,ans=1;
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end(),com);

    int end = v[0].second;
    for(int i=1;i<N;i++){
        if(end <= v[i].first){
            ans++;
            end = v[i].second;
        }
    }

    cout<<ans;
    return 0;
}