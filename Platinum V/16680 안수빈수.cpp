#include<iostream>
#include<vector>
#include<stack>
#define MAX 1000000000
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        ll N;
        cin>>N;     
        cout<<N*(MAX-1)<<"\n";
    }
    return 0;
}