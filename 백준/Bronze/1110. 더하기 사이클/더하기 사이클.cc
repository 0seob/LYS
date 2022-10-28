#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int a, a1, a2, b, c, ans, cnt = 0;
	cin >> a;
	ans = a;
	while(1){
		a1 = a / 10;
		a2 = a % 10;
		b = (a1 + a2) % 10;
		c = a2 * 10 + b;
		cnt++;
		if(c == ans) break;
		a = c;
	}
	cout << cnt;	
	return 0;
}