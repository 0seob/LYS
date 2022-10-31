#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool is_prime(ll n){
    if (n < 2) return false;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int solution(int n, int k) {
    int answer = 0;
    string prime = "";
    while(n != 0){
        prime = to_string(n%k) + prime;
        n /= k;
    }
    string temp = "";
    for(int i = 0; i < prime.length(); i++){
        if(prime[i] != '0') temp += prime[i];
        else{
            if(temp.length() == 0) continue;
            if(is_prime(stol(temp)) == true) answer++;
            temp = "";
        }
    }
    if(temp.length() != 0){
        if(is_prime(stol(temp)) == true) answer++;
    }
    return answer;
}