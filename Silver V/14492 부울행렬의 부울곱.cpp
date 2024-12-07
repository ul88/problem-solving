#include<iostream>
#define MAX 300
using namespace std;
int main()
{
    int matrixA[MAX+1][MAX+1]={0,},matrixB[MAX+1][MAX+1]={0,};
    int ans=0;
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>matrixA[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>matrixB[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int temp = 0;
            for(int k=0;k<N;k++){
                temp = temp|(matrixA[i][k]&matrixB[k][j]);
            }
            if(temp == 1) ans++;
        }
    }

    cout<<ans;
    return 0;
}