#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int t, k, n, m;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    printf("\n");
    int a[300] = {}, b[300] = {};
    vector<int> v;
    scanf("%d %d %d", &k, &n, &m);
    for(int j = 0; j < n; j++){
      scanf("%d", &a[j]);
    }
    for(int j = 0; j < m; j++){
      scanf("%d", &b[j]);
    }

    int seqa = 0, seqb = 0, cnta = 0, cntb = 0;
    while(1){
      if(seqa < n){
        if(a[seqa] == 0) {
          k++;
          v.push_back(a[seqa]);
          seqa++;
        }
        else if(a[seqa] <= k) {
          v.push_back(a[seqa]);
          seqa++;
          cnta = 0;
        }
        else {
          cnta++;
        }
      }

      if(seqb < m){
        if(b[seqb] == 0) {
          k++;
          v.push_back(b[seqb]);
          seqb++;
        }
        else if(b[seqb] <= k) {
          v.push_back(b[seqb]);
          seqb++;
          cntb = 0;
        }
        else {
          cntb++;
        }
      }

      if(cnta > 0 && cntb > 0) {
        printf("-1\n");
        cnta = 0; cntb = 0;
        break;
      }
      else if(cnta > 0 && seqb == m){
        printf("-1\n");
        cnta = 0; cntb = 0;
        break;
      }
      else if(cntb > 0 && seqa == n){
        printf("-1\n");
        cnta = 0; cntb = 0;
        break;
      }
      else if(seqa == n && seqb == m){
        for(int j = 0; j < m + n; j++){
          printf("%d ", v[j]);
        }
        printf("\n");
        cnta = 0; cntb = 0;
        break;
      }
    }
  }
  return 0;
}
