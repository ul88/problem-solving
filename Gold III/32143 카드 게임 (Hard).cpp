#include<iostream>
#include<queue>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    int H,N,Q;
    long long sum = 0;
    cin>>H;
    cin>>N>>Q;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        sum+=a;
        pq.push(a);
    }

    if(sum < H) cout<<"-1\n";
    else{
        while(sum - pq.top() >= H && !pq.empty()){
            sum -= pq.top();
            pq.pop();
        }
        cout<<pq.size()<<"\n";
    }

    for(int i=0;i<Q;i++){
        int a;
        cin>>a;
        sum+=a;
        pq.push(a);
        if(sum < H) cout<<"-1\n";
        else{
            while(sum - pq.top() >= H && !pq.empty()){
                sum -= pq.top();
                pq.pop();
            }
            cout<<pq.size()<<"\n";
        }
    }
    return 0;
}