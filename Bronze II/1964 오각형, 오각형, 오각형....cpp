#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    int N;
    ll ans = 0;
    cin>>N;

    ans = N*5;
    int temp = N*2-1;
    for(int i=1;i<N;i++){
        ans = (ans + (N-i)*5)%45678;
        ans= (ans - temp)%45678;
        temp-=2;
    }

    cout<<ans%45678;
    return 0;
}