#include<iostream>
#include<queue>
#include<map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        priority_queue<int> pq; // 최대힙
        priority_queue<int, vector<int>, greater<int>> reversePq; // 최소힙
        map<int,int> m;
        for(int i=0;i<N;i++){
            char a;
            int b;
            cin>>a>>b;
            if(a == 'I'){
                pq.push(b);
                reversePq.push(b);
                if(m.find(b) == m.end()){
                    m[b]=1;
                }else{
                    m[b]++;
                }
            }else{
                if(b > 0){
                    while(!pq.empty() && m[pq.top()] == 0) pq.pop();
                    if(pq.empty()) continue;
                    m[pq.top()]--;
                    pq.pop();
                }else{
                    while(!reversePq.empty() && m[reversePq.top()] == 0) reversePq.pop();
                    if(reversePq.empty()) continue;
                    m[reversePq.top()]--;
                    reversePq.pop();
                }
            }
        }

        while(!pq.empty() && m[pq.top()] == 0) pq.pop();
        while(!reversePq.empty() && m[reversePq.top()] == 0) reversePq.pop();
        if(pq.empty() || reversePq.empty()){
            cout<<"EMPTY\n";
        }else{
            cout<<pq.top()<<" "<<reversePq.top()<<"\n";
        }
    }
    return 0;
}