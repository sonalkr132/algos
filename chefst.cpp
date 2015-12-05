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

int find_sum(int n){
  return (n*(n+1))/2;
}

unsigned long long int find_minimum_left_stones(unsigned long long int pile_a, unsigned long long int pile_b, unsigned long long int max_remove){
  if(max_remove == 0) return pile_a + pile_b; //int i = 0;
  unsigned long long int removeable = find_min(pile_a, pile_b, max_remove);

  if(removeable == max_remove){
    int min = pile_a > pile_b ? pile_b: pile_a;
    int times = min/max_remove;
    pile_a -= times * max_remove - find_sum(times - 1);
    pile_b -= times * max_remove - find_sum(times - 1);
    removeable = max_remove - times;
    max_remove = removeable;
  }

  int removeable_sum = find_sum(removeable);

  while(removeable != 0){
    removeable = find_min(pile_a, pile_b, max_remove);
    //cout << max_remove <<" "<< removeable<<" " << pile_a<<" " << pile_b << endl;
    pile_a -= removeable;
    pile_b -= removeable;
    max_remove = removeable-1; //i++;
  }
  return pile_b + pile_a;
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
