#include "proj06_functions.h"
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
vector<vector<int>> read_file(const string & fname) {
	string line;
	vector<int> line_int;
	vector<vector<int>> r;
	int placeholder;
	ifstream infile(fname);
	while (getline(infile, line)) {
		for (auto i = 0; i < line.size(); i++) {
			placeholder = line[i] - '0';
			line_int.push_back(placeholder);
		}
		if (line_int.size() >= 1) {
			r.push_back(line_int);
			line_int = {};
		}
	}
	return r;
}

vector<int> get_row(const vector<vector<int>>& v, int row) {
	return v[row];
}

vector<int> get_column(const vector<vector<int>>& v, int col) {
	vector<int> r;
	for (auto i = 0; i < v.size(); i++) {
		r.push_back(v[i].at(col));
	}
	return r;
}

int col_to_int(const vector<vector<int>>& v, size_t col) {
	vector<int> column = get_column(v, col);
	int r = 0;
	int n;
	for (auto i = 1; i < column.size(); i++) {
		if (column[i] == 1) {
			n = 8 - i;
			r += pow((1*2), (n-1));
		}
	}
	return r;
}

string get_time(const vector<vector<int>>& v) {
	int hour = col_to_int(v, 4);
	int minute = col_to_int(v, 1);
	string h = to_string(hour);
	string m = to_string(minute);
	string r;
	r = h + ":" + m;
	return r;
}
