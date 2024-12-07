#include<iostream>
#include<vector>
using namespace std;
vector<int> v;

void boy(int n){
    for(int i=n;i<=v.size();i+=n){
        v[i-1] = !v[i-1];
    }
}

void girl(int n){
    int left = n;
    int right = n;
    v[n] = !v[n];
    while(left >= 0 && right < v.size()){
        if(v[left] != v[right]) break;
        v[left] = !v[left];
        v[right] = !v[right];
        left--;
        right++;
    }
}

int main()
{
    int N,M;
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        v.push_back(a);
    }

    cin>>M;
    for(int i=0,a,b;i<M;i++){
        cin>>a>>b;
        if(a==1){
            boy(b);
        }else{
            girl(b-1);
        }
    }

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
        if(i%20 == 19){
            cout<<"\n";
        }
    }

    return 0;
}