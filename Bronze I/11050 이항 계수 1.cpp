#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector <pii> v;
    int N;
    cin>>N;
    v.reserve(N);
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());

    for(int i=0;i<N;i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    return 0;
}