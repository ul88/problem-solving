#include<iostream>
#include<algorithm>
#define MAX 10
using namespace std;
int A[MAX+1][MAX+1]={0,}, B[MAX+1][MAX+1]={0,};
int N,ans=0;

int check(){
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            if(A[i][j] != B[i][j]) cnt++;
        }
    }
    return cnt;
}

void spin(){
    int copy[MAX+1][MAX+1]={0,};

    for(int i=0;i<N;i++){
        int copyRow[MAX+1]={0,};   
        int len = 0;
        for(int j=i;j<N;j++){
            copyRow[len++] = A[j][i];
        }

        int row = i;
        int col = 0;
        for(int j=len-1;j>=0;j--){
            copy[row++][col++] = copyRow[j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            A[i][j] = copy[i][j];
        }
    }

    ans = min(ans,check());
}

void symmetry(){
    int copy[MAX+1][MAX+1]={0,};

    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            copy[i][j] = A[i][i-j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            A[i][j] = copy[i][j];
        }
    }

    ans = min(ans,check());

}
int main()
{
    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            cin>>A[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            cin>>B[i][j];
        }
    }

    ans = check();
    symmetry();
    symmetry();
    spin();
    symmetry();
    symmetry();
    spin();
    symmetry();

    cout<<ans;

    return 0;
}