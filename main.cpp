#include "Header.h"

class A {
public:
	int a;
	A(int a) : a(a) {}
};

int main() {
	using namespace std;

	string folder = "maps/";
	vecstring names = readMapNames(folder + "names.txt");
	printMapNames(names);
	int i = getMapIndex(names);

	char map[5][5];
	scanMap(folder + names.at(i), map);

	cout << endl << "When using ManualInput, input move coordinate from keyboard" << endl;
	cout << "Format: [A-E][1-5][dash][A-E][1-5]" << endl;
	cout << "Example: E2-E3" << endl << endl;
	
	cout << "Press ENTER to continue...";
	getchar();

	cls;

	Game* game = new Game();
	game->initMap(map);
	game->run();

	return 0;
}