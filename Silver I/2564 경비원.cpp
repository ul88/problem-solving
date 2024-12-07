#include<iostream>
#include<vector>
#define MAX 100
using namespace std;
int main()
{
    pair<int,int> my,startL,startR,flag;
    int arr[MAX+1][MAX+1]={0,};
    int N,M,T,ans=0;
    cin>>M>>N;
    cin>>T;
    for(int i=0,a,b;i<T;i++){
        cin>>a>>b;
        if(a==1){
            arr[0][b]=1;
        }else if(a==2){
            arr[N][b]=1;
        }else if(a==3){
            arr[b][0]=1;
        }else{
            arr[b][M]=1;
        }
    }
    cin>>my.first>>my.second;
    if(my.first == 1){
        startL = {0,my.second};
        flag.first = 0;
        flag.second = 0;
    }
    else if(my.first == 2){
        startL = {N,my.second};
        flag.first = 2;
        flag.second = 2;
    }
    else if(my.first == 3){
        startL = {my.second,0};
        flag.first = 1;
        flag.second = 3;
    }
    else{
        startL = {my.second,M};
        flag.first = 3;
        flag.second = 1;
    }

    startR = startL;
    int cnt = 0;
    while(T>0 && cnt < N*M){
        if(arr[startL.first][startL.second]){
            ans+=cnt;
            arr[startL.first][startL.second]=0;
            T--;
        }
        if(arr[startR.first][startR.second]){
            ans+=cnt;
            arr[startR.first][startR.second] = 0;
            T--;
        }
        if(flag.first == 0){
            if(startL.second-1 == 0){
                flag.first++;    
            }
            startL.second--;
        }
        else if(flag.first == 1){
            if(startL.first+1 == N){
                flag.first++;
            }
            startL.first++;
        }
        else if(flag.first == 2){
            if(startL.second+1 == M){
                flag.first++;
            }
            startL.second++;
        }else{
            if(startL.first-1 == 0){
                flag.first++;
            }
            startL.first--;
        }

        if(flag.second == 0){
            if(startR.second+1 == M){
                flag.second++;    
            }
            startR.second++;
        }
        else if(flag.second == 1){
            if(startR.first+1 == N){
                flag.second++;
            }
            startR.first++;
        }
        else if(flag.second == 2){
            if(startR.second-1 == 0){
                flag.second++;
            }
            startR.second--;
        }else{
            if(startR.first-1 == 0){
                flag.second++;
            }
            startR.first--;
        }
        flag.first %= 4;
        flag.second %= 4;
        // cout<<"L: "<<startL.first<<" "<<startL.second<<"\n";
        // cout<<"R: "<<startR.first<<" "<<startR.second<<"\n";
        cnt++;
    }

    cout<<ans;

    return 0;
}