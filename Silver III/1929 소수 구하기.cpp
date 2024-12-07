#include<iostream>
#define MAX 1000000
using namespace std;
bool isNotPrime[MAX+1]={0,}; // true : 합성수
int main()
{
    int M,N;
    cin>>M>>N;
    isNotPrime[1] = true;
    for(int i=2;i<=N;i++){
        if(isNotPrime[i]) continue;
        for(int j=i+i;j<=N;j+=i){
            isNotPrime[j] = true;
        }
    }

    for(int i=M;i<=N;i++){
        if(isNotPrime[i]) continue;
        cout<<i<<"\n";
    }

    return 0;
}