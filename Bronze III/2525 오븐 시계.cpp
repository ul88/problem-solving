#include<iostream>
using namespace std;
int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    cout<<(A+(B+C)/60)%24<<" "<<(B+C)%60;
    return 0;
}