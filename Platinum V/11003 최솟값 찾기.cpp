#include<iostream>
#   include<queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<pair<int,int>> pq;
    int N,L;
    cin>>N>>L;
    for(int i=0,a;i<N;i++){
        cin>>a;
        pq.push({-a,i});
        while(pq.top().second < i+1-L) pq.pop();
        
        cout<<-pq.top().first<<" ";
    }
    return 0;
}

//힙 구현
// #include<iostream>
// #define MAX 5000000
// using namespace std;
// using pii = pair<int,int>;
// struct Heap{
//     int size;
//     pii data[MAX+1];
// };
// Heap heap = {0,{}};
// void insertHeap(int n,int idx){
//     heap.data[++heap.size] = {n, idx};
//     int i = heap.size;
//     while(i > 1 && heap.data[i].first < heap.data[i/2].first){
//         pii temp = heap.data[i];
//         heap.data[i] = heap.data[i/2];
//         heap.data[i/2] = temp;
//         i/=2;
//     }
// }
// void deleteHeap(){
//     heap.data[1] = heap.data[heap.size--];
//     int parent=1;
//     int child = 2;
//     while(heap.size >= child){
//         if(heap.data[child] > heap.data[child+1]){
//             child++;
//         }
//         if(child > heap.size) break;

//         if(heap.data[parent] > heap.data[child]){
//             pii temp = heap.data[parent];
//             heap.data[parent] = heap.data[child];
//             heap.data[child] = temp;
//         }
//         parent = child;
//         child*=2;
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int N,L;
//     cin>>N>>L;
//     for(int i=0,a;i<N;i++){
//         cin>>a;
//         insertHeap(a,i);
//         while(heap.data[1].second < i+1-L) deleteHeap();
//         cout<<heap.data[1].first<< " ";
//     }
//     return 0;
// }