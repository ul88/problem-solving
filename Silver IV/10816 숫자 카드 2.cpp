#include<iostream>
#include<map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<int,int> m;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        if(m.find(a) == m.end()) m[a] = 1;
        else m[a]++;
    }
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        int a;
        cin>>a;
        if(m.find(a) == m.end()) cout<<"0 ";
        else cout<<m[a]<<" ";
    }
    return 0;
}