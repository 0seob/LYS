#include <bits/stdc++.h>

using namespace std;

int main(){
	int T, N;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%d", &N);
		vector<pair<int, int>> v;
		v.push_back(make_pair(1, 0));
		v.push_back(make_pair(0, 1));
		if(N == 0) printf("1 0\n");
		else if(N == 1) printf("0 1\n");
		else{
			for(int j = 2; j <= N; j++){
				v.push_back(make_pair(v[j-1].first + v[j-2].first, v[j-1].second + v[j-2].second));
			}
			printf("%d %d\n", v[N].first, v[N].second);
		}
	}
}