#include <iostream>
#include <algorithm>
#include <stdlib.h>     /* abs */


using namespace std;

int main(){
	long long int cases;
	cin >> cases;
	while(cases--){
		long long int n, k;
		cin >> n >> k;
		long long int arr[n];

		long long int sum = 0;
		for(long long int i = 0; i < n; i++){ cin >> arr[i]; sum+= arr[i];}
		sort(arr, arr + n);

		long long int first_k = 0, last_k = 0;
		for(long long int i = 0; i < k; i++) first_k+=arr[i];
		for(long long int i = n-k; i < n; i++) last_k+=arr[i];
		//cout << n-k-1 << " " << last_k << endl;

		cout << max(abs(first_k - (sum - first_k)), abs(last_k - (sum - last_k))) << endl;
	}
	return 0;
}
