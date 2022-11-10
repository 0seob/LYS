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
int vis[1005][1005][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, char const *argv[]) {
    FASTIO();
    int N, M;
    char in;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    queue<tuple<int, int, int> > q;
    q.push(make_tuple(0, 0, 1));
    vis[0][0][1] = 1;
    while(!q.empty()){
        tuple<int, int, int> cur = q.front(); q.pop();
        // cout << get<0>(cur) << " " << get<1>(cur) << " " << get<2>(cur) << " " << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] << '\n';
        for(int dir = 0; dir < 4; dir++){
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] == '1'){
              if(get<2>(cur) == 0) continue;
              else{
                q.push(make_tuple(nx, ny, 0));
                vis[nx][ny][0] = vis[get<0>(cur)][get<1>(cur)][1] + 1;
              }
            }
            else{
              if(vis[nx][ny][get<2>(cur)] > 0) continue;
              else{
                q.push(make_tuple(nx, ny, get<2>(cur)));
                vis[nx][ny][get<2>(cur)] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
              }
            }
        }
    }
    if(vis[N-1][M-1][0] == 0 && vis[N-1][M-1][1] == 0) cout << "-1";
    else if(vis[N-1][M-1][0] == 0)  cout << vis[N-1][M-1][1];
    else if(vis[N-1][M-1][1] == 0)  cout << vis[N-1][M-1][0];
    else{
      vis[N-1][M-1][0] < vis[N-1][M-1][1] ? cout << vis[N-1][M-1][0] : cout << vis[N-1][M-1][1];
    }
}
