#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int> > tree(30);

void preorder(int root){
  if(root<0) return ;
  printf("%c",root+'A');
  preorder(tree[root].first);
  preorder(tree[root].second);
}

void inorder(int root){
  if(root<0) return ;
  inorder(tree[root].first);
  printf("%c",root+'A');
  inorder(tree[root].second);
}

void postorder(int root){
  if(root<0) return ;
  postorder(tree[root].first);
  postorder(tree[root].second);
  printf("%c",root+'A');
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    char a,b,c;
    scanf(" %c %c %c",&a,&b,&c);
    tree[a-'A'].first = b-'A';
    tree[a-'A'].second = c-'A';
  }
  preorder(0);
  printf("\n");
  inorder(0);
  printf("\n");
  postorder(0);
  printf("\n");
}
