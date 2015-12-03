#include <iostream>
#include <math.h>

using namespace std;

int *find_binary(int num, int size){
  static int arr[100001] = {0}, i=size-1;

  while(num!=0){
    int r = num%2;
    arr[i--] = r;
    num /= 2;
  }

  return arr;
}


int main(){
  int size_n, count = 0;
  int dec[100001] = {0}, num_ones[100001] = {0};

  int parity = 0;

  cin >> size_n;
  for(int i=0; i<size_n; i++){
    int l, u;
    cin >> l >> u;
    int num = (pow(2, size_n-l+1) - pow(2, size_n-u));
    dec[i-1] = num;
    num_ones[i-1] = (u-l+1);

    //update count
    count+= num_ones[i-1];

    parity = parity^num;

  }

  int *bin = find_binary(parity, size_n);

  int query;
  cin >> query;
  while(query--){
    int i, j;
    cin >> i >> j;

    bool even_parity = (count%2==0)?true:false;

    //check for row
    if(even_parity){
      even_parity = (num_ones[i-1]%2==0)?true:false;
    }
    else{
      even_parity = (num_ones[i-1]%2==0)?false:true;
    }

    //check for col
    if(even_parity){
      even_parity = bin[j-1]?false:true;
    }
    else{
      even_parity = bin[j-1]?true:false;
    }

    //find interstion
    int intersection = pow(2, size_n-j);

    if(dec[i-1] & intersection){
      even_parity = even_parity?false:true;
    }

    if(even_parity) cout<<'E'<<endl;
    else cout <<'O'<<endl;
  }

  return 0;
}
