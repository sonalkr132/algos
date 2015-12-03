/*
question: a node id and sum of immediate children id is given
          ex: node   sum
                4     0   (leaf)

          find the root node

solution: just sum all given node ids(sum_ids) and sums(sum_childrens) seperately.
          root_id = sum_ids - sum_childrens
          case root_id will never be included in sum_children as it is child of no
          node.
*/

#include <iostream>

using namespace std;

int main(){
  int cases;
  cin >> cases;

  while(cases--){
    int nodes, x = 0;
    cin >> nodes;
    while(nodes--){
      int id, sum;
      cin >> id >> sum;
      x += (id-sum);
    }
    cout << x<<endl;
  }
  return 0;
}
