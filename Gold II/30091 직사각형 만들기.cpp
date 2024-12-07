#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define MAX 2000
using namespace std;
typedef long long ll;

vector <ll> v;
map <ll,ll> m;
map <ll,int> cnt;
bool com(ll a,ll b){
    return a>b;
}

int main()
{
    int N;
    ll ans = 0;
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        if(cnt.find(a) == cnt.end()){
            v.push_back(a);
            cnt.insert({a,1});
        }else{
            cnt[a]++;
        }
    }

    sort(v.begin(),v.end(),com);

    for(int i=0;i<v.size();i++){
        if(cnt[v[i]]>=2){
            if(m.find(v[i]*2) == m.end()){
                m.insert({v[i]*2, v[i]*v[i]*cnt[v[i]]/2});
            }else{
                m[v[i]*2] += v[i]*v[i]*cnt[v[i]]/2;
            }
            ans = max(m[v[i]*2],ans);
        }

        for(int j=i+1;j<v.size();j++){
            if(m.find(v[i]+v[j]) == m.end()){
                m.insert({v[i]+v[j], v[i]*v[j]*min(cnt[v[i]],cnt[v[j]])});
            }else{
                m[v[i]+v[j]] += v[i]*v[j]*min(cnt[v[i]],cnt[v[j]]);
            }
            ans = max(m[v[i]+v[j]],ans);
        }
    }

    cout<<ans;
    return 0;
}