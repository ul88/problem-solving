/*
    오일러 피 함수 설명:
        https://m.blog.naver.com/hongjg3229/221795417061
*/
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll N,ans;
    cin>>N;

    ans = N;

    for(ll i=2;i*i<=N;i++){
        if(N%i == 0){
            ans -= ans/i;
            while(N%i==0) N/=i;
        }
    }

    if(N>1) ans -= ans/N;
    cout<<ans;

    return 0;
}