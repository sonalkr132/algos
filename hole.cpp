#include <iostream>
#include <algorithm> // for std::find

using namespace std;

int check_holes(char input[]){
  int count = 0;
  char hole[] = {'A', 'D', 'Q', 'R', 'O', 'P'};
  for(int i=0; input[i] != '\0'; i++){
    if(find(hole, hole+6, input[i]) != hole+6) count ++;
    else if(input[i] == 'B') count+=2;
  }
  return count;
}

int main(){
  int cases;
  cin >> cases;
  while(cases--){
    char input[100];
    cin >> input;
    int ans = check_holes(input);
    cout<<ans<<endl;
  }
  return 0;
}
y