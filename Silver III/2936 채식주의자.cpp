#include<iostream>
#define AREA 15625
using namespace std;
int main()
{//15625
    
    int a,b;
    cin>>a>>b;
    cout<<fixed;
    cout.precision(2);
    if(a==0){
        if(b>125){
            cout<<(double)AREA/b*2<<" 0.00";
        }else{
            cout<<(double)AREA/(250-b)*2<<" "<<(double)250-(double)AREA/(250-b)*2;
        }
    }
    else if(b==0){
        if(a > 125){
            cout<<"0.00 "<<(double)AREA/a*2;
        }else{
            cout<<(double)250-(double)AREA/(250-a)*2<<" "<<(double)AREA/(250-a)*2;
        }
    }
    else{
        if(a>b){
            cout<<"0.00 "<<(double)250-(double)AREA/a*2;
        }else{
            cout<<(double)250-(double)AREA/b*2<<" 0.00";
        }
    }
    return 0;
}