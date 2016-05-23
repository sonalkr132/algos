#include <iostream>

using namespace std;

int check_leaf(int *arr, int size){
	if(arr[0] > 1) return 0;
	if((arr[0] == 1) && (size > 1)) return 0;
	if((arr[0] == 1) && (size == 1)) return 1;

	if(arr[size-1]%2 != 0) return 0;
	int cur_nodes = arr[size-1]/2;
	for(int i=(size-2); i > 0; i--){
		int nodes = arr[i] + cur_nodes;
		if(nodes%2 !=0) return 0;
		cur_nodes = nodes/2;
	}
	if(cur_nodes==1) return 1;
	else return 0;
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int levels;
		cin >> levels;
		int arr[levels];
		for(int i=0; i<levels; i++) cin >> arr[i];

		if(check_leaf(arr, levels)) cout << "Yes" <<endl;
		else cout << "No" << endl;
	}
	return 0;
}
