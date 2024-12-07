#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    vector <int> v;
    ll ans = 0;
    int N;
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());
    
    for(int i=0;i<v.size();i++){
        ans += abs(v[i]-(i+1));
    }

    cout<<ans;
    return 0;
}