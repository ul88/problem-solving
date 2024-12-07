// #include<iostream>
// #include<queue>
// #include<vector>
// #define MAX 99
// using namespace std;
// vector<int> v1[MAX+1];
// vector<int> v2[MAX+1];
// int bfs(vector<int> v[MAX+1],int n){
//     int visit[MAX+1]={0,};
//     queue <int> q;
//     q.push(n);
//     visit[n] = 1;
//     int cnt = 0;
//     while(!q.empty()){
//         int now = q.front();
//         q.pop();
//         for(int j=0;j<v[now].size();j++){
//             int next = v[now][j];
//             if(visit[next]) continue;
//             visit[next] = 1;
//             q.push(next);
//             cnt++;
//         }
//     }
//     return cnt;
// }

// int main()
// {
//     int N,M,ans=0;
//     cin>>N>>M;
//     for(int i=0,a,b;i<M;i++){
//         cin>>a>>b;
//         v1[b].push_back(a);
//         v2[a].push_back(b);
//     }

//     for(int i=1;i<=N;i++){
//         if(bfs(v1,i)>=(N+1)/2 || bfs(v2,i)>=(N+1)/2){
//             ans++;
//         }
//     }
//     cout<<ans;
//     return 0;
// }

//dfs
// #include<stdio.h>
// #define MAX 99
// int N,M;
// int arr1[MAX+1][MAX+1]={0,};
// int arr2[MAX+1][MAX+1]={0,};
// int visit[MAX+1]={0,}, cnt1=0,cnt2=0,ans=0;
// void dfs1(int n){
//     for(int i=1;i<=N;i++){
//         if(arr1[n][i] == 1){
//             if(visit[i]) continue;
//             visit[i] = 1;
//             cnt1++;
//             dfs1(i);
//         }
//     }
// }
// void dfs2(int n){
//     for(int i=1;i<=N;i++){
//         if(arr2[n][i] == 1){
//             if(visit[i]) continue;
//             visit[i] = 1;
//             cnt2++;
//             dfs2(i);
//         }
//     }
// }
// int main()
// {
//     scanf("%d %d",&N,&M);
//     for(int i=0,a,b;i<M;i++){
//         scanf("%d %d",&a,&b);
//         arr1[a][b] = 1;
//         arr2[b][a] = 1;
//     }

//     for(int i=1;i<=N;i++){
//         for(int j=1;j<=N;j++) visit[j] = 0;
//         dfs1(i);
//         for(int j=1;j<=N;j++) visit[j] = 0;
//         dfs2(i);
//         if(cnt1 >= (N+1)/2 || cnt2 >= (N+1)/2){
//             ans++;
//         }
//         cnt1=cnt2=0;
//     }

//     printf("%d",ans);

//     return 0;
// }

//floyd
#include<stdio.h>
#define MAX 99
int main()
{
    int N,M;
    int arr[MAX+1][MAX+1]={0,},ans=0;
    scanf("%d %d",&N,&M);
    for(int i=0,a,b;i<M;i++){
        scanf("%d %d",&a,&b);
        arr[a][b] = 1;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                if(arr[j][i] && arr[i][k]) arr[j][k] = 1;
            }
        }
    }

    for(int i=1;i<=N;i++){
        int cnt1 = 0, cnt2 = 0;
        for(int j=1;j<=N;j++){
            if(i==j) continue;
            if(arr[i][j]) cnt1++;
            if(arr[j][i]) cnt2++;
        }

        if(cnt1>=(N+1)/2 || cnt2>=(N+1)/2) ans++;
    }
    printf("%d",ans);
    return 0;
}