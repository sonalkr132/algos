#include <iostream>

using namespace std;

unsigned long long int find_min(unsigned long long int a, unsigned long long int b, unsigned long long int c){
  if(a < b){
    if(a < c) return a;
    else return c;
  }
  else{
    if(b < c) return b;
    else return c;
  }
}

unsigned long long int find_minimum_left_stones(unsigned long long int pile_a, unsigned long long int pile_b, unsigned long long int max_remove){
  if(max_remove == 0) return pile_a + pile_b;
  while(true){
    unsigned long long int removeable = find_min(pile_a, pile_b, max_remove);
    if(pile_a >= removeable) pile_a -= removeable;
    if(pile_b >= removeable) pile_b -= removeable;
    max_remove--;
    if(max_remove == 0) return pile_b + pile_a;
  }
}

int main(){
  unsigned long long int cases;

  cin >> cases;
  while(cases--){
    unsigned long long int n1, n2, m;
    cin >> n1 >> n2 >> m;
    unsigned long long int left_stones = find_minimum_left_stones(n1, n2, m);
    cout << left_stones << endl;
  }

  return 0;
}
