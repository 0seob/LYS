#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int board[105][105];
int vis[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char const *argv[]) {
    FASTIO();
    int N, in, max = 0, min = 100, cnt, ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> in;
            board[i][j] = in;
            if(in > max) max = in;
            else if(in < min) min = in;
        }
    }
    for(int k = min; k <= max; k++){
        int vis[105][105] = {};
        queue<pair<int, int> > q;
        cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] > k && vis[i][j] == 0){
                    q.push(make_pair(i, j));
                    vis[i][j] = 1;
                    cnt++;
                    while(!q.empty()){
                        pair<int, int> cur = q.front(); q.pop();
                        for(int dir = 0; dir < 4; dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                            if(vis[nx][ny] == 1 || board[nx][ny] <= k) continue;
                            q.push(make_pair(nx, ny));
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        if(cnt > ans) ans = cnt;
    }
    if(ans == 0) cout << 1;
    else cout << ans;
}