#include <iostream>
#include <math.h>
#include <stdlib.h>


using namespace std;

int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b, a%b);
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int n, found = 0;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) cin >> arr[i];


		//take gcd two at a time
		if(n == 1 && arr[0] == 1){cout << -1 << endl; found =1;}
		int first = arr[0], tmp_first = arr[0];
		for(int i=1; i < n && !found; i++){
			tmp_first = gcd(first, arr[i]);
			if(tmp_first != 1) first = tmp_first;
			else{
				cout << -1 <<endl;
				found = 1;
			}
		}

		//find factor of last gcd obtianed
		for(int i = 2; i <= sqrt(tmp_first) && (!found); i++){
			if((tmp_first%i) == 0){
			 	cout << i << endl;
			 	found = 1; //factor was found
			}
		}
		if(!found) cout << tmp_first <<endl;
	}

	return 0;
}
