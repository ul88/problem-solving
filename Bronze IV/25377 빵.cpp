#include<iostream>
#define INF INT32_MAX
using namespace std;
int main()
{
    int N,m=INF;
    cin>>N;
    for(int i=0,A,B;i<N;i++){
        cin>>A>>B;
        if(A<=B){
            m = min(m,B);
        }
    }

    if(m==INF){
        cout<<-1;
    }else{
        cout<<m;
    }
    return 0;
}