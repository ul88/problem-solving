#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll A,B,V;
    cin>>A>>B>>V;
    cout<<(V-A)/(A-B) + 1 + ((V-A)%(A-B) != 0);
    return 0;
}