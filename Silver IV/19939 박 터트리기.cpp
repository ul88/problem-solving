#include<iostream>
using namespace std;
int main()
{
    int N,K,hap=0;
    cin>>N>>K;
    for(int i=1;i<=K;i++){
        hap+=i;
    }

    if(hap > N){
        cout<<"-1";
    }
    else{
        if((N-hap) % K == 0){
            cout<<K-1;
        }else{
            cout<<K;
        }
    }
}