#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> inorder;
    vector <int> postorder;
    int N;
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        inorder.push_back(a);
    }
    for(int i=0,a;i<N;i++){
        cin>>a;
        postorder.push_back(a);
    }

    

    return 0;
}