#include <iostream>

using namespace std;

void rev_str(int k){
	char arr[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	if(k/25 >= 1){
		if(k%25 == 0) k+= (k/25 - 1);
		else k+=k/25;
	}
	for(int i=k; i >= 0; i--){
		int index = i%26;
		cout << arr[index];
	}
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int k;
		cin >> k;
		if(k) rev_str(k);
		else cout << 'a';
		cout << endl;
	}
	return 0;
}
