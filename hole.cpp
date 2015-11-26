#include <iostream>

using namespace std;

int check_holes(char input[]){
  int count = 0;
  for(int i=0; input[i] != '\0'; i++){
    if(input[i] == 'A' || input[i] == 'D' || input[i] == 'Q' || input[i] == 'R' || input[i] == 'O' ||input[i] == 'P' ) count ++;
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