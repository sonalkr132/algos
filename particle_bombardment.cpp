#include <iostream>
#include <math.h>

using namespace std;

int a[101] = {0};

void find_distribution(long long int no_particles, int max_particles, int no_chambers){

  for(int i=1; i<=no_chambers; i++){
    int tmp = ((int)pow((max_particles+1), i));
    int pre_tmp = (int)pow((max_particles+1), (i -1));
    long long int rem = no_particles%tmp;
    a[i] = rem/pre_tmp;
  }
}

int main(){
  long long int no_particles;
  int max_particles, no_chambers;
  cin >> no_particles >> max_particles >> no_chambers;

  find_distribution(no_particles, max_particles, no_chambers);
  for(int i=1; i<=no_chambers; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
