#include <bits/stdc++.h>
#include <list>
#include <tuple>
#define quot 1000000000
#define FASTIO() ios::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
typedef long long ll;

using namespace std;

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int main(int argc, char const *argv[]) {
    FASTIO();
    while(1){
        char board[35][35][35] = {};
        int vis[35][35][35] = {};
        int L, R, C, print = 0, in;
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) return 0;
        for(int k = 0; k < L; k++)
            for(int i = 0; i < R; i++)
                for(int j = 0; j < C; j++)
                    cin >> board[i][j][k];
        queue<tuple<int, int, int> > q;
        for(int k = 0; k < L; k++){
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    if(board[i][j][k] == 'S'){
                        vis[i][j][k] = 1;
                        q.push(make_tuple(i, j, k));
                    }
                }
            }
        }
        while(!q.empty()){
            tuple<int, int, int> cur = q.front(); q.pop();
            for(int dir = 0; dir < 6; dir++){
                int nx = get<0>(cur) + dx[dir];
                int ny = get<1>(cur) + dy[dir];
                int nz = get<2>(cur) + dz[dir];
                if(nx < 0 || ny < 0 || nz < 0 || nx >= R || ny >= C || nz >= L) continue;
                if(board[nx][ny][nz] == '#' || vis[nx][ny][nz] > 0) continue;
                if(board[nx][ny][nz] == 'E'){
                    cout << "Escaped in " << vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] << " minute(s).\n";
                    print = 1;
                    break;
                }
                q.push(make_tuple(nx, ny, nz));
                vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            }
            if(print == 1) break;
        }
        if(print != 1) cout << "Trapped!\n";
    }
}