#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

class points{
public:
	int x, y;
};

int compare(const void *a_tmp, const void *b_tmp){
	points a = *(points *)a_tmp;
	points b = *(points *)b_tmp;
	if(a.x > b.x) return 1;
	else if((a.x == b.x) && (a.y == b.y)) return 0;
	else if(a.x < b.x) return -1;
	else{
		// a.x is equal to b.x but y's are not same
		if(a.y > b.y) return -1;
		else return 1;
	}
}


int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int n;
		cin >> n;
		points p[n];
		for(int i=0; i<n; i++){
			cin >> p[i].x >> p[i].y;
		}

		qsort(p, n, sizeof(points), compare);
		double dist = 0.0;
		for(int i=0; i<n-1; i++){
			long int x_2 = pow((p[i].x - p[i+1].x), 2);
			long int y_2 = pow((p[i].y - p[i+1].y), 2);
			dist+=sqrt(x_2 + y_2);
		}
		cout << setprecision(2) << fixed << dist << endl;
	}
	return 0;
}
