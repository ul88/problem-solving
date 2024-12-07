#include<iostream>
using namespace std;
int dp[41]={0,1};
int fibonacci(int n) {
    if(dp[n]!=0){
        return dp[n];
    } else if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return dp[n]=fibonacci(n-1) + fibonacci(n-2);
    }
}
int main()
{
    int T,N;
    cin>>T;
    while(T--){
        cin>>N;
        if(N==0){
            cout<<"1 0"<<"\n";
        }else{
            fibonacci(N);
            cout<<dp[N-1]<<" "<<dp[N]<<"\n";
        }
    }
    return 0;
}