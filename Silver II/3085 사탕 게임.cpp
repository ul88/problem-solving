#include<iostream>
#include<string>
#include<algorithm>
#define MAX 50
using namespace std;
string str[MAX+1]={};
int N,ans = 0;
void check(int n,int m){
    bool flag = false;
    int cnt = 1;
    for(int i=0;i<N-1;i++){
        if(str[n][i] == str[n][i+1]){
            cnt++;
        }else{
            ans = max(ans,cnt);
            cnt = 1;
        }
    }

    ans = max(cnt,ans);
    cnt = 1;
    
    for(int i=0;i<N-1;i++){
        if(str[i][m] == str[i+1][m]){
            cnt++;
        }else{
            ans = max(ans,cnt);
            cnt = 1;
        }
    }
    ans = max(cnt,ans);
}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>str[i];
    }

    for(int i=0;i<N;i++){
        check(i,0);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i+1 < N && str[i][j] != str[i+1][j]){
                char temp = str[i][j];
                str[i][j] = str[i+1][j];
                str[i+1][j] = temp;
                check(i,j);
                check(i+1,j);
                temp = str[i][j];
                str[i][j] = str[i+1][j];
                str[i+1][j] = temp;
            }
            if(j+1 < N && str[i][j] != str[i][j+1]){
                char temp = str[i][j];
                str[i][j] = str[i][j+1];
                str[i][j+1] = temp;
                check(i,j);
                check(i,j+1);
                temp = str[i][j];
                str[i][j] = str[i][j+1];
                str[i][j+1] = temp;
            }
        }
    }

    cout<<ans;
    return 0;
}