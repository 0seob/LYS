#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

char board[1005][1005];
int vis[1005][1005];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char const *argv[]) {
    FASTIO();
    int t;
    cin >> t;
    while(t--){
        int n;
        long in, max = 0, min = 1000000000;
        vector<int> v;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> in;
            if(in > max) max = in;
            if(in < min) min = in;
        }
        cout << max - min << '\n';
    }
}