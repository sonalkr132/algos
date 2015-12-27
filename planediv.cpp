#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
  int cases;

  cin >> cases;
  while(cases--){
    int lines, max_set_count = 1;

    //cin >> lines;
    lines = 5;
    int line_set[5000][3] = {0};
    for(int i=0; i<lines; i++){
      cin >> line_set[i][0] >> line_set[i][1] >> line_set[i][2];
      // line_set[i][0] = rand()%7 - 3;
      // line_set[i][1] = rand()%7 - 3;
      // line_set[i][2] = rand()%7 - 3;
      // cout << line_set[i][0]<<" " << line_set[i][1] <<" "<< line_set[i][2]<<endl;
    }

    for(int i=0; i<lines; i++){
      if(line_set[i][0] == 0 && line_set[i][1] == 0) continue;
      int count = 1;
      for(int j=i; j<lines; j++){
        cout << "a*cur_b "<< line_set[i][0]*line_set[j][1] << " b*cur_a " << line_set[i][1]*line_set[j][0]<<endl;
        cout << "c*cur_a "<< line_set[i][2]*line_set[j][0] << " a*cur_c " << line_set[j][2]*line_set[i][0]<<endl;
        cout << endl;
        int as = line_set[i][0] - line_set[j][0];
        int bs = line_set[i][1] - line_set[j][1];
        int cs = line_set[i][2] - line_set[j][2];

        // bs is always at bottom so check for devide by zero
        if(bs == 0){
          if(line_set[i][0] == line_set[j][0] && line_set[i][2] != line_set[j][2]) count++
        }
        else if(as)
      }
      if(count > max_set_count) max_set_count = count;
      cout << endl;
      cout << endl;
    }
    cout << max_set_count << endl<<endl;
  }
  return 0;
}
