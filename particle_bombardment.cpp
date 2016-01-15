/*
problem: given no_of_bombardments, champers and capacity of chambers, find the state of chamber at end of bombardment
         each bombardment splits particle in two. Fix capacity of chamber exceeds then one particle goes to next and
         particle count in current chamber is set to zero.
         q_link: https://www.codechef.com/problems/NUKES

solution: found pattern with smaller cases in copy
          rem = no_of_bombardments%((capacity+1)^chamber_index)
          particles[chamber_index] = rem/((capacity+1)^previous_chamber_index)
*/

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
