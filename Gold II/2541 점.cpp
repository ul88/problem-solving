#include<iostream>
#include<cmath>
#define MAX 100000
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int temp = abs(a-b);
    while(temp > 0 && temp%2==0) temp/=2;
    for(int i=0;i<5;i++){
        int p,q;
        cin>>p>>q;
        
        bool flag = false;
        if(a==b && p == q) flag = true;
        else{
            if(a<b && p<q){
                if((q-p)%temp == 0) flag = true;
            }
            else if(a>b && p>q){
                if((p-q)%temp == 0) flag = true;
            }
        }

        if(flag) cout<<"Y\n";
        else cout<<"N\n";
    }
    return 0;
}