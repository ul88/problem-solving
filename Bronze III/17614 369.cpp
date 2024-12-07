#include<iostream>
using namespace std;
int tsn(int n){
    int cnt = 0;
    while(n != 0){
        if(n%10 != 0 && n%10%3 == 0){
            cnt++;
        }
        n/=10;
    }
    return cnt;
}
int main()
{
    int N,ans = 0;
    cin>>N;
    for(int i=1;i<=N;i++){
        ans += tsn(i);
    }
    cout<<ans;
    return 0;
}