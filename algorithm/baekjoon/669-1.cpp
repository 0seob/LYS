#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int t, n, a;
  scanf("%d",&t);
  for(int i = 0; i < t; i++){
    scanf("%d",&n);
    vector<int> v1, v2;
    for(int j = 0; j < n; j++){
      scanf("%d",&a);
      if(a == 1) v1.push_back(a);
      else v2.push_back(a);
    }

    int len1 = v1.size();
    int len2 = v2.size();

    if(len1 % 2 == 0){
      if(len1 <= n/2) {
        printf("%d\n",len2);
        for(int k = 0; k < len2; k++){
          if(k == len2 - 1) printf("%d\n",v2[k]);
          else printf("%d ",v2[k]);
        }
      }
      else {
        printf("%d\n",len1);
        for(int k = 0; k < len1; k++){
          if(k == len1 - 1) printf("%d\n",v1[k]);
          else printf("%d ",v1[k]);
        }
      }
    }
    else{
      if(v1.size() <= n/2) {
        printf("%d\n",len2);
        for(int k = 0; k < len2; k++){
          if(k == len2 - 1) printf("%d\n",v2[k]);
          else printf("%d ",v2[k]);
        }
      }
      else {
        printf("%d\n",len1 - 1);
        for(int k = 1; k < len1; k++){
          if(k == len1 - 1) printf("%d\n",v1[k]);
          else printf("%d ",v1[k]);
        }
      }
    }
  }
  return 0;
}
