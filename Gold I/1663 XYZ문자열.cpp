#include<iostream>
#include<vector>
#include<string>
#define MAX 100
using namespace std;
typedef long long ll;
string str[4];
ll dp[MAX+1][4]={0,};
int T=0,N;
ll k;
char c;

char check(ll idx,int depth){
    if(depth <= 2){
        return str[depth][idx-1];
    }

    if(dp[depth-3][3] >= idx){
        return check(idx,depth-3);
    }else{
        return check(idx-dp[depth-3][3],depth-2);
    }
}

int main()
{
    cin>>T>>N;

    str[0]="X";
    str[1]="YZ";
    str[2]="ZX";

    dp[0][0]=1;
    dp[0][3]=1;
    for(int i=1;i<N;i++){
        dp[i][0] = dp[i-1][2];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][0]+dp[i-1][1];
        dp[i][3] = dp[i][0]+dp[i][1]+dp[i][2];
    }

    if(T==1){
        cout<<dp[N-1][3];
    }else if(T==2){
        cin>>k;
        cout<<check(k,N-1);
    }else{
        cin>>c;
        cout<<dp[N-1][c-'X'];
    }
    return 0;
}