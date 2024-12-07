#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector <int> ans;
    int N;
    cin>>N;
    for(int i=N;i>=0;i--){
        vector <int> v;
        v.push_back(N);
        v.push_back(i);
        while(v[v.size()-2]-v.back() >= 0){
            v.push_back(v[v.size()-2]-v.back());
        }
        if(ans.empty()) ans = v;
        if(ans.size() < v.size()) ans = v;
    }

    cout<<ans.size()<<"\n";
    for(auto iter : ans){
        cout<<iter<<" ";
    }
    return 0;
}