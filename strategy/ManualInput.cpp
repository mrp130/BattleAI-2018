#include "ManualInput.h"

#include<iostream>

std::string ManualInput::move(Map* map)
{
	using namespace std;

	char input[100];
	do {
		cout << "Input: ";
		cin.getline(input, 100);
		input[0] = toupper(input[0]);
		input[3] = toupper(input[3]);
	} while (!validateMove(input));

	return string(input);
}

bool ManualInput::validateMove(std::string move)
{
	if (move.length() != 5) return false;
	if (move[0] < 'A' || move[0] > 'E') return false;
	if (move[1] < '0' || move[1] > '9') return false;
	if (move[2] != '-') return false;
	if (move[3] < 'A' || move[3] > 'E') return false;
	if (move[4] < '0' || move[4] > '9') return false;
	return true;
}


ManualInput::ManualInput() {}
ManualInput::~ManualInput() {}
