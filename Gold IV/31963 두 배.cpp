#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;
ll func(ll n){
    ll cnt = 0;
    ll temp = 1;
    while(temp*2 <= n){
        temp*=2;
        cnt++;
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<ll> v;
    int N;
    ll ans=0;
    cin>>N;
    for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        v.push_back(a);
    }
    ll temp = 0;
    for(int i=1;i<N;i++){
        ll lg = 0;
        if(temp == 0 && v[i-1] <= v[i]) continue;
        if(v[i-1] > v[i]){
            lg = func(v[i-1]/v[i]);
            ll p = pow(2,lg);
            if(p*v[i] >= v[i-1]){
                temp += lg;
            }else{
                temp += lg+1;
            }
        }else if(v[i-1] < v[i]){
            lg = func(v[i]/v[i-1]);
            temp -= lg;
        }
        if(temp < 0) temp = 0;
        ans += temp;
    }

    cout<<ans;
    return 0;
}