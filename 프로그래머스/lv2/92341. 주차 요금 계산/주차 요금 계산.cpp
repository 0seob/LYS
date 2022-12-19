#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iterator>
#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;

vector<string> split(string input, char delimeter){
    vector<string> answer;
    stringstream ss(input);
    string temp;
    
    while(getline(ss, temp, delimeter)){
        answer.push_back(temp);
    }
    
    return answer;
}

int time_to_fee(int time, vector<int> fees){
    if(time <= fees[0]){
        return fees[1];
    }
    else{
        time -= fees[0];
        if(time % fees[2] == 0) time /= fees[2];
        else time = time / fees[2] + 1;
        return fees[1] + time * fees[3];
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<int, int> >record;
    for(int i = 0; i < records.size(); i++){
        vector<string> temp;
        vector<string> time;
        temp = split(records[i], ' ');
        time = split(temp[0], ':');
        int int_time = stoi(time[0]) * 60 + stoi(time[1]);
        record.push_back(make_pair(stoi(temp[1]), int_time));
    }
    sort(record.begin(), record.end());
    for(int i = 0; i < record.size(); i++){
        cout << record[i].X << ' ' << record[i].Y << '\n';
    }
    int cnt = 1;
    int value = 0, last_time = 23*60+59, money = 0;
    for(int i = 0; i < record.size() - 1; i++){
        if(record[i].X == record[i+1].X && cnt == 1){
            value += record[i+1].Y - record[i].Y;
            cnt = 0;
            if(i == record.size() - 2){
                money = time_to_fee(value, fees);
                answer.push_back(money);
            }
        }
        else if(record[i].X == record[i+1].X && cnt == 0){
            cnt = 1;
        }
        else if(record[i].X != record[i+1].X && cnt == 1){
            value += last_time - record[i].Y;
            money = time_to_fee(value, fees);
            answer.push_back(money);
            value = 0;
        }
        else{
            money = time_to_fee(value, fees);
            answer.push_back(money);
            value = 0;
            cnt = 1;
        }
        cout << money << '\n';
    }
    if(cnt == 1){
        value += last_time - record[record.size() - 1].Y;
        money = time_to_fee(value, fees);
        answer.push_back(money);
    }
    return answer;
}