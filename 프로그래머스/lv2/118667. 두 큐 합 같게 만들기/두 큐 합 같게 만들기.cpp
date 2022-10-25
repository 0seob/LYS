#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll solution(vector<int> queue1, vector<int> queue2) {
    ll answer = 0, sum1 = 0, sum2 = 0, cnt = 0, temp;
    queue<int> q1; queue<int> q2;
    ll sz = queue1.size() + queue2.size();
    for(int i = 0; i < queue1.size(); i++){
        q1.push(queue1[i]);
        sum1 += queue1[i];
    }
    for(int i = 0; i < queue2.size(); i++){
        q2.push(queue2[i]);
        sum2 += queue2[i];
    }
    if((sum1 + sum2) % 2 == 1) return -1;
    while(!(sum1 == sum2)){
        if(sum1 > sum2){
            temp = q1.front();
            q1.pop();
            sum1 -= temp;
            q2.push(temp);
            sum2 += temp;
            answer++;
        }
        else{
            temp = q2.front();
            q2.pop();
            sum2 -= temp;
            q1.push(temp);
            sum1 += temp;
            answer++;
        }
        cnt++;
        if(cnt == sz * 10) break;
    }
    if(sum1 != sum2) answer = -1;
    return answer;
}