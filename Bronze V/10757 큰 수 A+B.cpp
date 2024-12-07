#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class lll{
public:
    lll() : num {} {}
    lll(string str){
        for(auto iter = str.crbegin();iter!=str.crend();iter++){
            num.push_back(*iter-'0');
        }
    }
    vector<int> get_num() { return num; };
    void set_num(vector<int> v) { num = v; };
    lll operator+(lll& operand){
        lll res;
        vector<int> temp = operand.get_num();
        if(num.size() < temp.size()){
            swap(num,temp);
        }

        for(int i=0;i<num.size();i++){
            if(i < temp.size()) num[i] += temp[i];
            if(num[i] >= 10){
                if(i == num.size()-1){
                    num.push_back(1);
                }else{
                    num[i+1]++;
                }
            }
            num[i] %= 10;
        }
        
        res.set_num(num);
        return res;
    }

    void print(){
        for(auto iter = num.crbegin();iter != num.crend();iter++){
            cout<<*iter;
        }
    }
private:
    vector<int> num;
};

int main()
{
    string str1,str2;
    cin>>str1>>str2;

    lll a(str1), b(str2);
    a=a+b;
    a.print();
    return 0;
}