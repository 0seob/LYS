#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int len = numbers.size(), lstate, rstate, state, lval = 3, rval = 3 , val = 0, l_v, r_v, l_on = 0, r_on = 0;
    int arr[4][4] = {{1, 2, 3, 4}, {2, 1, 2, 3}, {3, 2, 1, 2}, {4, 3, 2, 1}};
    for(int i = 0; i < len; i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            lstate = numbers[i];
            lval = (lstate + 1) / 3;
            answer += "L";
            l_on = 0;
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            rstate = numbers[i];
            rval = (rstate - 1) / 3;
            answer += "R";
            r_on = 0;
        }
        else{
            state = numbers[i];
            val = state / 3;
            if(state == 0) val = 3;
            l_v = arr[lval][val];
            r_v = arr[rval][val];
            if(l_on == 1) l_v -= 1;
            if(r_on == 1) r_v -= 1;
            if(l_v > r_v){
                answer += "R";
                r_on = 1;
                rval = val;
            }
            else if(l_v < r_v){
                answer += "L";
                l_on = 1;
                lval = val;
            }
            else{
                if(hand == "right"){
                    answer += "R";
                    r_on = 1;
                    rval = val;
                }
                else{
                    answer += "L";
                    l_on = 1;
                    lval = val;
                }
            }
        }
    }
    return answer;
}