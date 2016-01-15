/*
problem: given a collection of infinte balls of every color, you have to
         chose n balls of k colors. Each color must have at least one ball.
         find the total number of possible combinations given n and k
         q_link: https://www.codechef.com/problems/MARBLES

solution: look up "stars and bars problem". possible combination is (n-1)C(k-1)
          When diving the num with deno go from smaller to larger.
          mulitplication of n consecutive integers is devisible by n.
          edge cases are k==0 and k==n where C = 1
*/

#include <iostream>

using namespace std;

long long int find_combination(long long int n, long long int k){
  if(k==0 || k==n) return 1;

  long long int arr[59999], lower_arr[59999];
  long long int bigger, smaller;
  bigger = (n-k) < k ? k : (n-k);
  smaller = (bigger == (n-k)) ? k : (n-k) ;

  int index=0;
  for(int i=n, j=smaller; i>bigger, j>0; i--, j--) {
    arr[index] = i;
    lower_arr[index++] = j;
  }

  long long int ans = arr[index-1];
  for(int i=index-2; i>=0; i--){
    ans*=arr[i];
    ans/=lower_arr[i];
  }

  return ans;
}

int main(){
  long long int cases;

  cin >> cases;
  while(cases--){
    long long int n,k;
    cin >> n >> k;
    cout << find_combination(n-1 ,k-1) << endl;
  }
}
