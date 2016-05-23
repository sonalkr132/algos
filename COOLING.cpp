#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	int tests;

	cin >> tests;
	while(tests--){
		int n;
		cin >> n;

		int arr1[n], arr2[n];
		for(int i=0; i<n; i++) cin >> arr1[i];
		for(int i=0; i<n; i++) cin >> arr2[i];

		sort(arr1, arr1+n);
		sort(arr2, arr2+n);

		// for(int i=0; i<n; i++) cout << arr1[i]<< " ";
		// for(int i=0; i<n; i++) cout << arr2[i] << " ";

		int count=0, j=0;
		for(int i=0; i<n; i++){
			while(arr1[i] > arr2[j] && j < n){
				j++;
			}
			if(j == n) break;
			if(arr1[i] <= arr2[j]) count++;
			j++;
		}

		cout << count << endl;
	}
	return 0;
}
