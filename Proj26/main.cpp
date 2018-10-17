#include "proj06_functions.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int g;
	vector<vector<int>> v = {
	{ 1,0,1,1,1,0,1,1,1,0,1,0,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,1 },
	{ 1,1,0,0,0,0,0,0,0,1,1,0,0,0,1 },
	{ 1,1,0,0,0,1,0,0,0,1,1,1,0,1,0 },
	{ 0,0,0,0,1,0,0,0,0,1,1,1,0,0,1 },
	{ 0,0,0,0,1,1,1,1,0,1,0,1,1,1,1 },
	{ 0,1,0,0,0,0,1,0,0,1,0,0,0,0,0 },
	{ 1,0,0,0,0,1,0,1,0,1,1,0,1,1,0 }
	};
	g = col_to_int(v, 5);
	cout << g << endl;
	system("pause");
}