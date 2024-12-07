#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Swap(int left, int right, vector<int>& v){
    while(left<=right){
        int temp = v[left];
        v[left] = v[right];
        v[right] = temp;
        left++,right--;
    }
}

bool solve(vector<int> v){
    vector<pair<int,int> > ans;
    for(int i=0;i<v.size();i++){
        pair<int,int> temp;
        if(v[i] != i+1){
            temp.first = i;
            for(int j=i+1;j<v.size();j++){
                if(v[j] == i+1){
                    temp.second = j;
                    break;
                }
            }
            Swap(temp.first,temp.second,v);
            ans.push_back(temp);
            if(ans.size() >= 3) return false;
            i=0;
        }
    }

    if(ans.size() == 2){
        cout<<ans[0].first+1<<" "<<ans[0].second+1<<"\n";
        cout<<ans[1].first+1<<" "<<ans[1].second+1<<"\n";
    }else if(ans.size() == 1){
        cout<<ans[0].first+1<<" "<<ans[0].second+1<<"\n";
        cout<<"1 1";
    }else{
        cout<<"1 1\n1 1";
    }
    return true;
}

bool solve1(vector <int> v){
    vector<pair<int,int> > ans;
    for(int i=v.size()-1;i>=0;i--){
        pair<int,int> temp;
        if(v[i] != i+1){
            temp.second = i;
            for(int j=i;j>=0;j--){
                if(v[j] == i+1){
                    temp.first = j;
                    break;
                }
            }

            Swap(temp.first,temp.second,v);
            ans.push_back(temp);
            if(ans.size() >= 3) return false;
            i=v.size()-1;
        }
    }

    if(ans.size() == 2){
        cout<<ans[0].first+1<<" "<<ans[0].second+1<<"\n";
        cout<<ans[1].first+1<<" "<<ans[1].second+1<<"\n";
    }else if(ans.size() == 1){
        cout<<ans[0].first+1<<" "<<ans[0].second+1<<"\n";
        cout<<"1 1";
    }else{
        cout<<"1 1\n1 1";
    }
    return true;
}

int main()
{
    int N;
    vector<int> v;
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        v.push_back(a);
    }

    if(!solve(v)){
        solve1(v);
    }

    return 0;
}