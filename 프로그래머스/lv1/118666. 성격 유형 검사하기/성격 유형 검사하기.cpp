#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    m.insert(make_pair('R', 0));
    m.insert(make_pair('T', 0));
    m.insert(make_pair('F', 0));
    m.insert(make_pair('C', 0));
    m.insert(make_pair('M', 0));
    m.insert(make_pair('J', 0));
    m.insert(make_pair('A', 0));
    m.insert(make_pair('N', 0));
    for(int i = 0; i < choices.size(); i++){
        if(choices[i] > 4){
            int weight = choices[i] - 4;
            m[survey[i][1]] += weight;
        }
        else if(choices[i] < 4){
            int weight = 4 - choices[i];
            m[survey[i][0]] += weight;
        }
    }
    if(m['R'] >= m['T']) answer += "R";
    else answer += "T";
    if(m['C'] >= m['F']) answer += "C";
    else answer += "F";
    if(m['J'] >= m['M']) answer += "J";
    else answer += "M";
    if(m['A'] >= m['N']) answer += "A";
    else answer += "N";
    return answer;
}