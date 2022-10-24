#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int>helper(string str, int start, int end){
    vector<int> res, left, right;
    for(int i=start; i< end; i++ ){
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'){
            left=helper(str, start, i);
            right=helper(str, i+1, end);
            for(auto & l :left)
                for(auto & r: right){
                    if(str[i]=='+')res.push_back(l+r);
                    else if(str[i]=='-')res.push_back(l-r);
                    else res.push_back(l*r);
                }
        }
    }
    if(res.empty())res.push_back(stoi(str.substr(start, end-start+1)));

    return res;
}

vector<int> diffWaysToCompute(string input) {
    if(input.length()==0)return {};
    return helper(input, 0, input.length());
}

int main(){

    string input;
    cin >> input;

    diffWaysToCompute(input);

    return 0;
}