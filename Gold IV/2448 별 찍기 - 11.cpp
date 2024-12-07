#include<iostream>
#include<string>
#include<cmath>
#define MAX 3072
using namespace std;
string str[MAX+1] = {"*", "* *", "*****"};
string gap(int n){
    string temp = "";
    for(int i=0;i<str[n].length();i++){
        temp+=" ";
    }
    return temp;
}
void triangle(int n, int s, int g, int N){
    if(n >= N) return;
    str[n] = str[s] + gap(g) + str[s];
    if(g == 0){
        triangle(n+1, 0, n, N);
    }
    else triangle(n+1, s+1, g-1, N);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin>>N;
    
    triangle(3, 0, 2, N);

    for(int i=N-1;i>=0;i--){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<str[N-i-1];
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}