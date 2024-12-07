#include<iostream>
#include<vector>
#include<algorithm>
#define INF INT32_MAX
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector <int> v;
    int K,N;
    ll ans=0;
    cin>>K>>N;
    for(int i=0,a;i<K;i++){
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    ll left = 1, right = v[K-1];
    ll mid = 0;
    while(left <= right){
        mid = (left+right)/2;
        ll cnt = 0;
        for(auto iter : v){
            cnt += iter/mid;
        }
        if(cnt < N){
            right = mid-1;
        }else{
            left = mid+1;
            ans = max(ans,mid);
        }
    }

    cout<<ans;

    return 0;
}