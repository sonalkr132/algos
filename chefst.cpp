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

unsigned long long int find_sum(int n){
  return (n*(n+1))/2;
}

unsigned long long int return_pile(unsigned long long int a, unsigned long long int b){
  if(a > b) return (a-b);
  else return (b-a);
}

unsigned long long int find_minimum_left_stones(unsigned long long int pile_a, unsigned long long int pile_b, unsigned long long int max_remove){
  if(max_remove == 0) return pile_a + pile_b;
  unsigned long long int removeable = find_min(pile_a, pile_b, max_remove);

  if(removeable == max_remove){
    unsigned long long int to_remove = find_sum(max_remove);
    if(pile_a >= to_remove && pile_b >= to_remove) return (pile_a + pile_b - 2 * to_remove);
    else return return_pile(pile_a, pile_b);
  }
  else return return_pile(pile_a, pile_b);
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
