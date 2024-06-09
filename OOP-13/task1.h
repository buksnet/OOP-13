#pragma once
#include <list>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

int avgfirst(list<pair<int, double>> data) {
	list<pair<int, double>>::iterator it = data.begin();
	int sum = 0, i = 0;
	while (it != data.end()) {
		sum += (*it).first;
		i++;
		it++;
	}
	return sum / i;
}
double avgsecond(list<pair<int, double>> data) {
	list<pair<int, double>>::iterator it = data.begin();
	double sum = 0;
	int i = 0;
	while (it != data.end()) {
		sum += (*it).second;
		i++;
		it++;
	}
	return sum / i;
}

int addfirst(list<pair<int, double>> data) {
	list<pair<int, double>>::iterator it = data.begin();
	int min = (*it).first, max = (*it).first;
	it++;
	while (it != data.end()) {
		if ((*it).first < min) min = (*it).first;
		if ((*it).first > max) max = (*it).first;
		it++;
	}
	return min + max;
}

double addsecond(list<pair<int, double>> data) {
	list<pair<int, double>>::iterator it = data.begin();
	double min = (*it).second, max = (*it).second;
	it++;
	while (it != data.end()) {
		if ((*it).second < min) min = (*it).second;
		if ((*it).second > max) max = (*it).second;
		it++;
	}
	return min + max;
}

void print(list<pair<int, double>> data) {
	list<pair<int, double>>::iterator it = data.begin();
	cout << endl;
	while (it != data.end()) {
		cout << "(" << (*it).first << ", " << (*it).second << ")" << endl;
		it++;
	}
	cout << endl;
}

void task1() {
	list<pair<int, double>> adap;
	pair<int, double> npair;
	int n;
	cout << "Enter how much elements should be in container: ";
	cin >> n;
	cout << "Enter elements. Use space as separator in pair." << endl;
	for (int i = 1; i <= n; i++) {
		cout << "#" << i << ": ";
		cin >> npair.first >> npair.second;
		adap.push_back(npair);
	}

	print(adap); // after filling up

	npair.first = avgfirst(adap);
	npair.second = avgsecond(adap);
	adap.push_back(npair);

	print(adap); // after adding avg element

	list<pair<int, double>>::iterator it = adap.begin(), oldit;
	int b1, b2;
	cout << "Enter index borders (2 values): ";
	cin >> b1 >> b2;
	it = adap.begin();
	for (int i = 0; i < n; i++) {
		if (i >= b1 && i <= b2) {
			oldit = it;
			it++;
			i++;
			adap.remove(*oldit);
		}
		it++;
	}

	print(adap); //after deleting

	adap.sort();

	print(adap); // after sorting

	cout << "Enter pair to look for: ";
	cin >> npair.first >> npair.second;
	it = find(adap.begin(), adap.end(), npair);

	if (it != adap.end()) cout << endl << "found!" << endl;

	std::for_each(adap.begin(), adap.end(), [adap](pair<int, double>& iter) {iter.first += addfirst(adap); iter.second += addsecond(adap); });

	print(adap); // after searching & adding min+max to each element
}