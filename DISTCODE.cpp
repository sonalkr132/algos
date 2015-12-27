/*
problem: a country code be of two capital letter strings. given a string find all the
         possible country codes in it.
         q_link: https://www.codechef.com/LTIME31/problems/DISTCODE

solution: make a 26x26 array. Map each char in string to 0 base index. if you have used
          a country code in count then set its value 1 in check 26x26 matrix
*/
#include <iostream>
#include <string.h>

#define MAP 65

using namespace std;

int find_num_country(string input, int size){
  int check[26][26] = {0}, count = 0;
  for(int i=0; i<size-1; i++){
    int first_index = int(input[i])%MAP;
    int second_index  = int(input[i+1])%MAP;
    if(!check[first_index][second_index]){
      count++;
      check[first_index][second_index] = 1;
    } //end of if
  }//end of for

  return count;
}

int main(){
  int cases;
  cin >> cases;
  while(cases--){
    string input;
    cin >> input;
    cout << find_num_country(input, input.size())<<endl;
  }
  return 0;
}
