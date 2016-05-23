#include <iostream>
#include <math.h>

using namespace std;

int check_robbery(int *arr, int size, int sum){
	unsigned int pow_set_size = pow(2, size);
  int counter, j;

  /*Run from counter 000..0 to 111..1*/
  for(counter = 0; counter < pow_set_size; counter++)
  {
  	int tmp_sum = 0;
    for(j = 0; j < size; j++)
     {
        /* Check if jth bit in the counter is set
           If set then print jth element from set */
        if(counter & (1<<j))
          tmp_sum+= arr[j];
     }
     if(tmp_sum == sum) return 1;
  }
  return 0;
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int n, m;
		cin >> n >> m;
		int arr[n];
		for(int i=0; i<n; i++) cin >> arr[i];
		if(check_robbery(arr, n, m)) cout << "Yes" <<endl;
		else cout << "No" <<endl;
	}
	return 0;
}
