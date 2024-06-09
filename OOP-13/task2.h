#pragma once
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

void print(priority_queue<pair<int, double>> data) {
	while (!data.empty()) {
		cout << endl << "(" << data.top().first << ", " << data.top().second << ")" << endl;
		data.pop();
	}
}

int addfirst(priority_queue<pair<int, double>> data) {
	int min = data.top().first, max=data.top().first;
	data.pop();
	while (!data.empty()) {
		if (data.top().first < min) min = data.top().first;
		if (data.top().first > max) max = data.top().first;
		data.pop();
	}
	return min + max;
}

double addsecond(priority_queue<pair<int, double>> data) {
	int min = data.top().second, max = data.top().second;
	data.pop();
	while (!data.empty()) {
		if (data.top().second < min) min = data.top().second;
		if (data.top().second > max) max = data.top().second;
		data.pop();
	}
	return min + max;
}

int avgfirst(priority_queue<pair<int, double>> data) {
	priority_queue<pair<int, double>> nque = data;
	int sum = 0, i = 0;
	while (!nque.empty()) { sum += nque.top().first; nque.pop(); i++; }
	return sum / i;
}

double avgsecond(priority_queue<pair<int, double>> data) {
	priority_queue<pair<int, double>> nque = data;
	int sum = 0, i = 0;
	while (!nque.empty()) { sum += nque.top().second; nque.pop(); i++; }
	return sum / i;
}

void task2() {
	priority_queue<pair<int, double>> que;
	pair<int, double> npair;
	int n;
	cout << "Enter how much elements should be in container: ";
	cin >> n;
	cout << "Enter elements. Use space as separator in pair." << endl;
	for (int i = 1; i <= n; i++) {
		cout << "#" << i << ": ";
		cin >> npair.first >> npair.second;
		que.push(npair);
	}

	print(que); // after creating

	npair.first = avgfirst(que);
	npair.second = avgsecond(que);
	que.push(npair);

	print(que); // after adding min+max

	int b1, b2, i = 0;
	cout << "Enter index borders (2 values): ";
	cin >> b1 >> b2;
	priority_queue<pair<int, double>> nque{};

	while (!que.empty()) {
		if (!(i >= b1 && i <= b2)) {
			nque.push(que.top());
		}
		que.pop();
		i++;
	}
	que = nque;
	
	print(que); // after deleting


	nque = que;

	cout << "Enter pair to look for: ";
	cin >> npair.first >> npair.second;

	while (!nque.empty()) {
		if (nque.top() == npair) {
			cout << endl << "found!" << endl;
			break;
		}
		nque.pop();
	}
	nque = {};
	int addf = addfirst(que); 
	double adds = addsecond(que);
	while (!que.empty()) {
		npair.first = que.top().first + addf;
		npair.second = que.top().second + adds;
		nque.push(npair);
		que.pop();
	}
	que = nque;

	print(que);
}