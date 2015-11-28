#include <iostream>

using namespace std;

int a[100] = {0};

void make_stable(int max_particles, int no_chambers){
  int cur = a[0], count = 0;
  while(cur > max_particles && count < no_chambers){
    a[count] = 0;
    a[count+1]++;
    count++;
    cur = a[count];
  }
}

void find_distribution(long long int no_particles, int max_particles, int no_chambers){

  while(no_particles--){
    a[0]++;
    if(a[0] > max_particles) make_stable(max_particles, no_chambers);
  }
}

int main(){
  long long int no_particles;
  int max_particles, no_chambers;
  cin >> no_particles >> max_particles >> no_chambers;

  find_distribution(no_particles, max_particles, no_chambers);
  for(int i=0; i<no_chambers; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
