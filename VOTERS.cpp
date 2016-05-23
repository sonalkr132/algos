#include <iostream>
#include <algorithm>

using namespace std;

int compare(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main(){
  int n1, n2, n3;

  cin >> n1 >> n2 >> n3;
  int total = n1+n2+n3, input;

  int arr[total], ans[50000];

  for(int i=0; i < total; i++){
    cin >> input;
    arr[i] = input;
  }

   qsort(arr, total, sizeof(int), compare);



  int count = 0, cur = arr[0], index = 0;
  for(int i=0; i < total; i++){
    int tmp = arr[i];
    if(cur == tmp) count++;
    else {
      count = 1;
      cur = tmp;
    }
    if(count == 2){
      ans[index++] = tmp;
    }
  }

  cout << index << endl;
  for(int i=0; i < index; i++){
    cout << ans[i] << endl;
  }

  return 0;
}
