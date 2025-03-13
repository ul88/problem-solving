#include<iostream>
using namespace std;
int main()
{
    int N,C;
    cin>>N>>C;
    int x = N, y = N;
    for(int i=0;i<C;i++){
        int a,b;
        cin>>a>>b;
        if(x <= a || y <= b) continue;
        // 세로로 자를 때 y가 b로 바뀜
        // 가로로 자를 때 x가 a로 바뀜
        int temp1 = a*y; //가로로 자를 때
        int temp2 = x*b; // 세로로 자를 때
        if(temp1 >= temp2){
            x = a;
        }
        else{
            y = b;
        }
    }
    cout<<x*y;
    return 0;
}