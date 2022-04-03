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
    ll a, b, c;
    char min;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(b - a == c - b){
            cout << "YES\n";
            continue;
        }
        a < c ? (a < b ? min = 'a' : min = 'b') : (c < b ? min = 'c' : min = 'b');
        if(min == 'a'){
            if((c - b) % a == 0){
                cout << "YES\n";
                continue;
            }
            else{
                cout << "NO\n";
                continue;
            }
        }
        else if(min == 'b'){
            if((c - a) % 2 != 0){
                cout << "NO\n";
                continue;
            }
            else{
                if(c > a){
                    if(((c - a)/2 + a) % b == 0){
                        cout << "YES\n";
                        continue;
                    }
                    else{
                        cout << "NO\n";
                        continue;
                    }
                }
                else{
                    if(((a - c)/2 + c) % b == 0){
                        cout << "YES\n";
                        continue;
                    }
                    else{
                        cout << "NO\n";
                        continue;
                    }
                }
            }
        }
        else{
            if((a - b) % c == 0){
                cout << "YES\n";
                continue;
            }
            else{
                cout << "NO\n";
                continue;
            }
        }
    }
}