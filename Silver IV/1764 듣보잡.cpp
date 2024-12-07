#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<string> v;
    set<string> s;
    int N,M;
    cin>>N>>M;
    v.reserve(M);
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        s.insert(str);
    }

    for(int i=0;i<M;i++){
        string str;
        cin>>str;
        if(s.find(str) != s.end()){
            v.push_back(str);
        }
    }

    sort(v.begin(),v.end());

    cout<<v.size()<<"\n";
    for(auto iter : v){
        cout<<iter<<"\n";
    }
    return 0;
}