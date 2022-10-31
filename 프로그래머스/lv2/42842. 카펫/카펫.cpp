#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> v;
    for(int i = 1; i <= yellow; i++){
        if(yellow % i == 0) v.push_back(i);
    }
    for(int i = 0; i < v.size()/2+1; i++){
        if(brown - 4 == (yellow/v[i] + v[i])*2){
            answer.push_back(yellow/v[i] + 2);
            answer.push_back(v[i] + 2);
            break;
        }
    }
    return answer;
}