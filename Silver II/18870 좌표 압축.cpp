#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    vector<int> copy;
    map<int,int> m;
    int N;
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        v.push_back(a);
     }

    copy = v;

    sort(v.begin(),v.end());

    int cnt = 0;
    for(int i=0;i<N;i++){
        if(m.find(v[i]) == m.end()){
            m.insert({v[i],cnt++});
        }
    }

    for(int i=0;i<N;i++){
        cout<<m[copy[i]]<<" ";
    }

    return 0;
}