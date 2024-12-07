#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 250000
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ll> v;
    vector<ll> C;
    int N, start = 0;
    bool flag = false;
    ll ans = 0;
    cin>>N;
    for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        C.push_back(a);
        if(a > 0){
            start = i;
            flag = true;
        }
    }

    if(!flag){
        cout<<N/2;
        return 0;
    }
    while(v.size() < N){
        v.push_back(C[start]);
        start = (start+1)%N;
    }

    int cnt = 0;
    for(int i=0;i<N;i++){
        if(v[i] > 0){
            ans += v[i];
            if(cnt != 0){
                ans += (cnt+1)/2;
                cnt = 0;
            }
        }else{
            cnt++;
        }
    }

    cout<<ans + (cnt+1)/2;
    return 0;
}