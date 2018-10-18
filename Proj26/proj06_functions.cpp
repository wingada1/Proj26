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

string get_date(const vector<vector<int>>& v) {
	int month = col_to_int(v, 6);
	int day = col_to_int(v, 5);
	int year = col_to_int(v, 7);
	string m = to_string(month);
	string d = to_string(day);
	string y = to_string(year);
	string r;
	if (m.size() == 1)
		m.insert(0, "0");
	if (d.size() == 1)
		d.insert(0, "0");
	if (y.size() == 1)
		y.insert(0, "0");
	r = m + "/" + d + "/" + "20" + y;
	return r;
}

string get_serial(const vector<vector<int>>& v) {
	int one = col_to_int(v, 13);
	int two = col_to_int(v, 12);
	int three = col_to_int(v, 11);
	int four = col_to_int(v, 10);
	string o = to_string(one);
	string t = to_string(two);
	string th = to_string(three);
	string f = to_string(four);
	if (o.size() == 1)
		o.insert(0, "0");
	if (t.size() == 1)
		t.insert(0, "0");
	if (th.size() == 1)
		th.insert(0, "0");
	if (f.size() == 1)
		f.insert(0, "0");

	string r;

	r = o + t + th + f;
	return r;
}
