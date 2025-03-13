#include<iostream>
#include<string>
#define MAX 30
using namespace std;
string str[MAX + 1];
int N;

bool row(int n, int m){
    if(m+2 >= N) return false;
    for(int i=1;i<3;i++){
        if(str[n][m+i] != str[n][m]) return false;
    }
    return true;
}

bool col(int n, int m){
    if(n+2 >= N) return false;
    for(int i=1;i<3;i++){
        if(str[n+i][m] != str[n][m]) return false;
    }
    return true;
}

bool diagonal(int n,int m){
    if(n+2 >= N || m+2 >= N) return false;
    for(int i=1;i<3;i++){
        if(str[n+i][m+i] != str[n][m]) return false;
    }
    return true;
}

bool diagonal2(int n,int m){
    if(n+2 >= N || m-2 < 0) return false;
    for(int i=1;i<3;i++){
        if(str[n+i][m-i] != str[n][m]) return false;
    }
    return true;
}

bool check(int n, int m){
    return max(
        row(n,m), max(
            col(n,m), max(
                diagonal(n,m),
                diagonal2(n,m)
            )
        )
    );
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>str[i];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(str[i][j] == '.') continue;
            if(check(i,j)){
                cout<<str[i][j];
                return 0;
            }
        }
    }
    cout<<"ongoing";
    return 0;
}