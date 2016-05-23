#include <iostream>

using namespace std;

int flag = 0;

int find_mod(int *a, int *b, int len){
	int tmp=0;
	// a is array
	int divisor = *b;
	//cout << "div "<<divisor<<endl;
	for(int i=0; i<len; i++){
		tmp = 10*tmp + a[i];
		if(divisor > tmp) continue;
		//cout << "tmp "<<tmp<<endl;
		tmp = tmp%divisor;
	}

	return tmp;
}

int gcd(int *a, int *b, int len){
	if(*b==0) return *a;
	else{
		flag++; int mod;
		if(flag == 1) mod = *a;
		else if(flag == 2) mod = find_mod(a, b, len); //first arg is array
		else mod = (*a)%(*b);

		//cout << mod << endl;
		return gcd(b, &mod, len);
	}
}

int main(){
	int cases;

	cin >> cases;
	while(cases--){
		int a;
		flag = 0;
		string s;
		cin >> a;
		cin >> s;

		int len = s.size();
		int b[len];

		for(int i=0; i<len; i++) b[i] = s[i] - '0';
		if(a == 0){ for(int i=0; i<len; i++) cout<<b[i]; cout << endl; }
		else cout << gcd(&a, b, len)<<endl;
	}
	return 0;
}
