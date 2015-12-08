#include <iostream>

using namespace std;

int main(){
  int cases;

  cin >> cases;
  while(cases--){
    int lines, max_set_count = 1;

    cin >> lines;
    int line_set[5000][3] = {0};
    for(int i=0; i<lines; i++){
      cin >> line_set[i][0] >> line_set[i][1] >> line_set[i][2];
    }

    for(int i=0; i<lines; i++){
      int count = 1;
      for(int j=i; j<lines; j++){
        // cout << "a*cur_b "<< line_set[i][0]*line_set[j][1] << " b*cur_a " << line_set[i][1]*line_set[j][0]<<endl;
        // cout << "c*cur_a "<< line_set[i][2]*line_set[j][0] << " a*cur_c " << line_set[j][2]*line_set[i][0]<<endl;
        // cout << endl;
        if(line_set[i][0]*line_set[j][1] == line_set[i][1]*line_set[j][0] && (line_set[i][2]*line_set[j][0] != line_set[j][2]*line_set[i][0])) count++;
      }
      if(count > max_set_count) max_set_count = count;
      // cout << endl;
      // cout << endl;
    }
    cout << max_set_count << endl;
  }
  return 0;
}
