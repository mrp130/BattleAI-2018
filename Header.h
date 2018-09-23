#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>

#include "game\Game.h"
#include "define.h"

vecstring readMapNames(std::string file);
void printMapNames(vecstring names);
int getMapIndex(vecstring names);
void scanMap(std::string file, char arr[][5]);


vecstring readMapNames(std::string file) {
	using namespace std;

	vecstring out;
	char data[255];

	ifstream infile;
	infile.open(file);

	while (infile.peek() != EOF) {
		infile.getline(data, 255);
		out.push_back(data);
	}

	infile.close();
	return out;
}

void printMapNames(vecstring names) {
	using namespace std;

	cout << endl;
	int i = 1;
	for (auto it = names.begin(); it != names.end(); ++it, i++) {
		cout << i << ". " << *it << endl;
	}
	cout << endl;
}

int getMapIndex(vecstring names)
{
	using namespace std;

	char map;

	do {
		cout << "Choose map[1-" << names.size() << "]: ";
		cin >> map;
		flush;
		map -= '1';
	} while (map < 0 || map > (int) names.size() - 1);

	return map;
}

void scanMap(std::string file, char arr[][5]) {
	using namespace std;

	ifstream infile;
	infile.open(file);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			infile >> arr[i][j];
		}
	}

	infile.close();
}