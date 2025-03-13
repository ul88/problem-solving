#include<iostream>
using namespace std;
int main()
{
    int N,M;
    cin>>N>>M;
    for(int i=0;i<8;i++){
        int a;
        cin>>a;
    }
    
    if((N==2 && M==1) || (N==1 && M==2)) cout<<"ChongChong";
    else cout<<"GomGom";
    return 0;
}