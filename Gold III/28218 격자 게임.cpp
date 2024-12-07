#include<iostream>
#include<string>
#define MAX 300
using namespace std;
string str[MAX+1];
int dp[MAX+1][MAX+1]={0,};
int N,M,K,Q;
int main()
{
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        cin>>str[i];
    }

    for(int i=N-1;i>=0;i--){
        for(int j=M-1;j>=0;j--){
            
            if(str[i][j] == '#' || dp[i][j]) continue;
            if(i-1 >= 0) dp[i-1][j] = 1;
            if(j-1 >= 0) dp[i][j-1] = 1;

            for(int k=1;k<=K;k++){
                if(i-k < 0 || j-k < 0) continue;
                dp[i-k][j-k] = 1;
            }
        }
    }

    cin>>Q;
    for(int i=0;i<Q;i++){
        int a,b;
        cin>>a>>b;
        cout<<(dp[a-1][b-1] == 1 ? "First" : "Second")<<"\n";
    }

    return 0;
}