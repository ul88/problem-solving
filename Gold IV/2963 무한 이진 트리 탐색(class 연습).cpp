#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Big_Operator{
public:
    Big_Operator() : num{1}, cnt{1} {}
    void add();
    void mul(vector<int>& v ,int n);
    void print();
    
    vector<int>& get_num(){
        return num;
    }
    vector<int>& get_cnt(){
        return cnt;
    }
private:
    vector <int> num;
    vector <int> cnt;
};
void Big_Operator::add(){
    for(int i=0;i<num.size();i++){
        if(i< cnt.size())
            num[i] += cnt[i];
        if(num[i] >= 10){
            if(i == num.size()-1){
                num.push_back(1);
            }else{
                num[i+1]++;
            }
        }
        num[i] %= 10;
    }
}
void Big_Operator:: mul(vector<int>& v,int n){
    for(int i=0;i<v.size();i++){
        v[i] *= n;
    }
    
    for(int i=0;i<v.size()-1;i++){
        v[i+1] += v[i]/10;
        v[i] %= 10;
    }
    if(v[v.size()-1] >= 10){
        v.push_back(v[v.size()-1]/10);
        v[v.size()-2] %= 10;
    }
}
void Big_Operator::print(){
    for(int i=num.size()-1;i>=0;i--){
        cout<<num[i];
    }
}
int main()
{
    string str;
    Big_Operator ans;
    cin>>str;
    
    for(auto iter : str){
        if(iter == 'L'){
            ans.mul(ans.get_num(),2);
            // mul(ans,2);
        }else if(iter == 'R'){
            ans.mul(ans.get_num(),2);
            ans.add();
            // mul(ans,2);
            // add(ans,cnt);
        }else if(iter == '*'){
            ans.mul(ans.get_num(),5);
            ans.add();
            ans.mul(ans.get_cnt(),3);
            // mul(ans,5);
            // add(ans,cnt);
            // mul(cnt,3);
        }
    }

    ans.print();
    
    return 0;
}