#include <iostream>

using namespace std;

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int n;
		cin >> n;
		char buildings[n];
		cin >> buildings;

		int count = 0;
		for(int i=0; i<n; i++){
			int destroyed = 0;
			if(buildings[i] == '1') destroyed = 1;
			if(i > 0 && buildings[i-1] == '1') destroyed = 1;
			if(i < n && buildings[i+1] == '1') destroyed = 1;
			if(!destroyed) count++;
		}
		cout << count <<endl;
	}
	return 0;
}
