#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int t, no;
  char alp[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char str[26] = {};
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    scanf("%s", str);
    int len = strlen(str);
    vector<char> v;
    for(int j = 0; j < len; j++){
      v.push_back(str[j]);
    }
    for(int j = len-1; j >= 0; j--){
      if(alp[j] == v[0]) v.erase(v.begin(), v.begin()+1);
      else if(alp[j] == v[j]) v.pop_back();
      else {
        printf("NO\n");
        no = 1;
        break;
      }
      //for(int k = 0; k < len; k++) printf("%c", v[k]);
    }
    if(no == 1) {
      no = 0;
      continue;
    }
    printf("YES\n");
  }

  return 0;
}
