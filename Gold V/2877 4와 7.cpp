#include<iostream>
using namespace std;
void func(int n){
    if(n==0) return;
    if(n%2==1){
        func(n/2);
        cout<<"4";
    }else{
        func(n/2-1);
        cout<<"7";
    }
}

int main()
{
    int K;
    cin>>K;
    func(K);
    return 0;
}