#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> temp;
    int sz = operations.size();
    for(int i = 0; i < sz; i++){
        if(operations[i][0] == 'I'){
            string str = operations[i].substr(2);
            temp.push_back(stoi(str));
        }
        else if(operations[i][0] == 'D' && temp.size() > 0){
            if(operations[i][2] == '-'){
                temp.pop_front();
            }
            else temp.pop_back();
        }
        sort(temp.begin(), temp.end());
    }
    if(temp.size() == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(temp[temp.size()-1]);
        answer.push_back(temp[0]);
    }
    return answer;
}