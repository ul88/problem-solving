#include<iostream>
#define MAX 100
using namespace std;
int main()
{
    int A[MAX+1][MAX+1]={0,};
    int N,M;
    cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int temp = 0;
            cin>>temp;
            cout<<A[i][j] + temp<<" ";
        }
        cout<<"\n";
    }
    return 0;
}