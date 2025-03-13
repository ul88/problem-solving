#include<iostream>
using namespace std;
int main()
{
    int ans = -1;
    int N,X;
    cin>>N>>X;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        if(a+b > X) continue;
        ans = max(ans, a);
    }
    cout<<ans;
    return 0;
}