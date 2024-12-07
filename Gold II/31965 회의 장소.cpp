#include<iostream>
#include<vector>
#include<algorithm>
#define INF INT64_MAX
using namespace std;
using ll = long long;
vector<ll> v;
vector<ll> prevSum;

ll solve(int start ,int end){
    ll temp = (start == 0 ? 0 : prevSum[start - 1]);

    //최대값은 무조건 첫번째 또는 마지막
    //최솟값은 무조건 중앙값
    // ll now = prevSum[end] - temp - 2*(prevSum[i]-temp) + v[i]*(i-start+1) - v[i]*(end-start+1 - (i-start+1));
    ll maxData = max(prevSum[end] - temp - 2*(prevSum[start]-temp) + v[start] - v[start]*(end-start)
                , prevSum[end] - temp - 2*(prevSum[end]-temp) + v[end]*(end-start+1));
    ll minData = prevSum[end] - temp - 2*(prevSum[(start+end)/2]-temp) + v[(start+end)/2]*((start+end)/2-start+1) 
            - v[(start+end)/2]*(end-start+1 - ((start+end)/2-start+1));
    
    return maxData - minData;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, Q;
    cin>>N>>Q;
    v.reserve(N);
    prevSum.reserve(N);
    for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        v.push_back(a);
        if(prevSum.empty()) prevSum.push_back(a);
        else prevSum.push_back(prevSum.back() + a);
    }

    for(int i=0;i<Q;i++){
        int a,b, start, end;
        cin>>a>>b;
        start = lower_bound(v.begin(),v.end(), a) - v.begin();
        end = upper_bound(v.begin(),v.end(), b) - v.begin() - 1;
        if(end - start + 1 <= 2) cout<<"0\n";
        else cout<<solve(start,end)<<"\n";
    }
    return 0;
}