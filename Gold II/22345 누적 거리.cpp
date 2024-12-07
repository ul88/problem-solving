#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 200000
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
vector <pll> v;
vector <int> temp;
pll prevSum[MAX+1]={};
bool com(pll a, pll b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,Q;
    cin>>N>>Q;
    for(int i=0;i<N;i++){
        ll a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end(),com);

    for(int i=0;i<N;i++){
        prevSum[i+1].first = prevSum[i].first + v[i].first*v[i].second;
        prevSum[i+1].second = prevSum[i].second - v[i].first; 
        temp.push_back(v[i].second);
    }

    for(int i=0;i<Q;i++){
        ll a;
        cin>>a;
        
        int idx = lower_bound(temp.begin(),temp.end(),a)-temp.begin(); 
        // a보다 작은 가장 큰 인덱스 -> 누적합 배열로가면 +1이므로 -1을 하지않고 사용

        cout<<-(ll)(prevSum[idx].first+(ll)(a*prevSum[idx].second)) 
        + (ll)prevSum[N].first - prevSum[idx].first+(ll)a*(prevSum[N].second - prevSum[idx].second)<<"\n";
    }

    return 0;
}