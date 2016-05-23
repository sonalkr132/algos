#include <iostream>

using namespace std;

int main(){
  long long int cases;
  cin >> cases;
  while(cases--){
    long long int l, d, s, c;
    cin >> l >> d >> s >> c;

    long long int cur_day_likes = s;
    for(long long int i = 1; i < d; i++){
      cur_day_likes = s + s * c;
      if(cur_day_likes > 1000000000) break;
      else s = cur_day_likes;
    }

    if(cur_day_likes >= l) cout << "ALIVE AND KICKING" <<endl;
    else cout << "DEAD AND ROTTING" << endl;
  }
  return 0;
}
