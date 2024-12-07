#include<iostream>
#include<algorithm>
#define INF INT32_MAX
using namespace std;
int main()
{
    int N,ans=INF;
    cin>>N;
    
    for(int i=0;i<N/3;i++){
        for(int j=0;j<N/5;j++){
            if(i*3 + j*5 == N){
                ans = min(ans, i+j);
            }
        }
    }

    if(ans == INF){
        cout<<-1;
    }else{
        cout<<ans;
    }
    return 0;
}