#pragma once
#include <iostream>
#include <utility>
#include <algorithm>
#include <map>

void print(map<int, pair<int, double>> data){
	map<int, pair<int, double>>::iterator it = data.begin();
	cout << endl;
	while (it != data.end()) {
		cout << "[" << (*it).first << "] : (" << (*it).second.first << ", " << (*it).second.second << endl;
	}
	cout << endl;
}

int avgfirst(map<int, pair<int, double>> data) {
	map<int, pair<int, double>>::iterator it = data.begin();
	int sum = 0, i = 0;
	while (it != data.end()) {
		sum += (*it).second.first;
		i++;
		it++;
	}
	return sum / i;
}
double avgsecond(map<int, pair<int, double>> data) {
	map<int, pair<int, double>>::iterator it = data.begin();
	double sum = 0;
	int i = 0;
	while (it != data.end()) {
		sum += (*it).second.second;
		i++;
		it++;
	}
	return sum / i;
}

int addfirst(map<int, pair<int, double>> data) {
	map<int, pair<int, double>>::iterator it = data.begin();
	int min = (*it).second.first, max = (*it).second.first;
	it++;
	while (it != data.end()) {
		if ((*it).second.first < min) min = (*it).second.first;
		if ((*it).second.first > max) max = (*it).second.first;
		it++;
	}
	return min + max;
}

double addsecond(map<int, pair<int, double>> data) {
	map<int, pair<int, double>>::iterator it = data.begin();
	double min = (*it).second.second, max = (*it).second.second;
	it++;
	while (it != data.end()) {
		if ((*it).second.second < min) min = (*it).second.second;
		if ((*it).second.second > max) max = (*it).second.second;
		it++;
	}
	return min + max;
}

void task3() {
	map<int, pair<int, double>> dict;
	pair<int, double> npair;
	int n;
	cout << "Enter how much elements should be in container: ";
	cin >> n;
	cout << "Enter elements. Use space as separator in pair." << endl;
	for (int i = 0; i < n; i++) {
		cout << "#" << i << ": ";
		cin >> npair.first >> npair.second;
		dict.insert(pair<int, pair<int, double>>(i, npair));
	}

	print(dict);

	npair.first = avgfirst(dict);
	npair.second = avgsecond(dict);
	dict.insert(pair<int, pair<int, double>>(dict.size(), npair));
	
	print(dict);

	int b1, b2;
	cout << "Enter index borders (2 values): ";
	cin >> b1 >> b2;
	//remove_if(dict.begin(), dict.end(), [b1, b2](pair<int, pair<int, double>> ind) {return ((ind.second.first >= b1) && (ind.second.second <= b2)); });

	print(dict);

	map<int, pair<int, double>>::iterator it;
	cout << "Enter pair to look for: ";
	cin >> npair.first >> npair.second;
	it = find_if(dict.begin(), dict.end(), [npair](pair<int, pair<int, double>> p) {return (p.second == npair); });
	if (it != dict.end()) cout << endl << "found!" << endl;

	for_each(dict.begin(), dict.end(), [dict](pair<int, pair<int, double>> it) { it.second.first += addfirst(dict); it.second.second += addsecond(dict); });
	
	print(dict);
}