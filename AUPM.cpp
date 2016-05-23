#include <iostream>
#include <iomanip>

using namespace std;

void print_square(int size){
	//get first line drawn
	for(int i=0; i < size; i++) cout << "#";
	cout << endl;
	int mid = size/2;
	//upto start of next square
	for(int i=0; i< mid-1; i++) cout <<"#"<<setw(size-1)<<"#"<<endl;
	//the complicated one
	cout<<"#"<<setw(mid);
	for(int i=0; i < size; i++) cout << "#";
	cout << endl;

	//last half
	for(int i=0; i< mid-1; i++){
		 for(int j=0; j< 3; j++)cout<<"#"<<setw(mid);
		 cout << "#";
		 cout << endl;
	}
	//las complicated one
	for(int i=0; i < size; i++) cout << "#";
	cout<<setw(mid)<<"#";
	cout << endl;
	//last last simple one
	for(int i=0; i< mid-1; i++){
	  cout<<setw(mid+1) <<"#";
	  cout<<setw(size-1)<<"#"<<endl;
	}
	//last last last one
	cout<<setw(mid+1);
	for(int i=0; i<size; i++) cout << "#";
	cout<<endl;
}

int main(){
	int cases;
	cin >> cases;
	for(int i=0; i<cases; i++){
		int size;
		cin >> size;
		print_square(size);
	}
	return 0;
}