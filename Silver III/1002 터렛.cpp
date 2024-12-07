#include<iostream>
using namespace std;

struct st{
    int x;
    int y;
    int r;
};
int main(){
    int N;
    
    cin>>N;
    
    while(N--){
        st a,b;
        cin>>a.x>>a.y>>a.r>>b.x>>b.y>>b.r;

        int d = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);

        int r = (a.r - b.r) * (a.r - b.r);
        int r1 = (a.r + b.r) * (a.r + b.r);

        if(d == 0){
            if(r == 0){
                cout<<-1<<"\n";
            }else{
                cout<<0<<"\n";
            }
        }else if(d == r || d == r1){
            cout<<1<<"\n";
        }else if(r<d&&d<r1){
            cout<<2<<"\n";
        }else{
            cout<<0<<"\n";
        }
    }
    return 0;
}