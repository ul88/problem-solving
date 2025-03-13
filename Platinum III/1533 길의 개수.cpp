#include<iostream>
#include<vector>
#define MAX 10
using namespace std;
int adj[MAX+1][MAX+1];
int adj3[MAX+1][MAX+1][MAX+1];
int main()
{
    int N,S,E,T;
    cin>>N>>S>>E>>T;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        for(int j=0;j<str.length();j++){
            adj[i][j] = str[j] - '0';
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue;
            for(int k=0;k<N;k++){
                if(j==k) continue;
                adj3[i][j][k] = adj[i][j] + adj[j][k];
            }
        }
    }
    return 0;
}