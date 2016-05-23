#include <iostream>

using namespace std;

int max(int a, int b){
  int ans = (a > b) ? a : b;
  return ans;
}
int min(int a, int b){
	int ans = (a > b) ? b : a;
	return ans;
}


int find_diff(int n, int m, int k){
	int max_num = max(n, m);
	int min_num = min(n, m);
	int diff = max_num - min_num;
	if(diff >= k) return diff - k; //coins finished in first buy
	//coins more than diff
	else return 0;
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int n, m, k;
		cin >> n >> m >> k;
		cout << find_diff(n, m, k) << endl;
	}
	return 0;
}
