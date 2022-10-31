#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> rep, cnt, ans;
    int arr[1001][1001] = {};
    for(int i = 0; i < id_list.size(); i++){
        rep[id_list[i]] = i; //id 리스트 번호
        cnt[id_list[i]] = 0; //몇 번 리포트 되었는지
        ans[id_list[i]] = 0; //몇 번 메일 받는지
    }
    for(int i = 0; i < report.size(); i++){
        string str = report[i];
        vector<string> words;
        size_t pos = 0;
        while((pos = str.find(" ")) != string::npos){
            words.push_back(str.substr(0, pos));
            str.erase(0, pos + 1);
        }
        string reported = str;
        string reporter = words[0];
        if(arr[rep[reporter]][rep[reported]] == 0){
            arr[rep[reporter]][rep[reported]] = 1;
            cnt[reported]++;
        }
    }
    for(const auto &iter : cnt){
        if(iter.second >= k){
            for(int i = 0; i < id_list.size(); i++){
                if(arr[i][rep[iter.first]] == 1) ans[id_list[i]]++;
            }
        }
    }
    for(int i = 0; i < id_list.size(); i++){
        answer.push_back(ans[id_list[i]]);
    }
    return answer;
}