#include "Game.h"
#include "TeamItem.h"
#include "Base.h"
#include "Unit.h"


#include <iostream>
#include <typeinfo>

#include "../define.h"
#include<algorithm>

void Game::run() {
	using namespace std;

	turn = 1;

	while (true) {
		cls;

		cout << endl << endl << "Turn " << turn << endl << endl;
		this->print();

		vector<Team*> teams = map->getTeams();
		vector< pair <Team*, string> > moves;

		for (auto team = teams.begin(); team != teams.end(); ++team) {
			Map* cloned_map = new Map(*map);
			string m = (*team)->move(cloned_map);
			moves.push_back( make_pair((*team), m) );
			delete cloned_map;
		}
		
		this->moves(moves);
		this->map->resolveZone();

		this->produceMaterial();

		this->print();

		cout << "Press ENTER to continue...";
		getchar();

		if (++turn > 20) {
			cout << "Game Over" << endl << endl;
			for (auto team = teams.begin(); team != teams.end(); ++team) {
				int point = (*team)->countBase() * 20
					+ (*team)->countUnit() * 2
					+ (*team)->getMaterial();
				cout << (*team)->getSymbol() << ": " << point << " point" << endl;
			}
			break;
		}
		bool isEnd = false;
		for (auto team = teams.begin(); team != teams.end(); ++team) {
			if ((*team)->countBase() == 0) {
				cout << (*team)->getSymbol() << " defeated." << endl;
				isEnd = true;
			}
		}
		if (isEnd) break;
	}

	flush;
	cout << endl;
	cout << "Press ENTER to continue...";
	getchar();
}

void Game::produceMaterial()
{
	std::vector<Team*> teams = map->getTeams();
	for (auto it = teams.begin(); it != teams.end(); ++it) {
		(*it)->produceMaterial();
	}
}

void Game::moves(std::vector<std::pair <Team*, std::string>> moves)
{
	using namespace std;

	for (auto it = moves.begin(); it != moves.end(); ++it) {
		Coor from;
		Coor to;
		convertMoveString((*it).second, from, to);
		if (!move((*it).first, from, to)) {
			cout << "move from team " << (*it).first->getSymbol() << " is invalid." << endl;
		}
	}
}

bool Game::move(Team * team, Coor from, Coor to)
{
	if (!map->isInBorder(from)) return false;
	if (!map->isInBorder(to)) return false;

	Zone* z_from = map->getZone(from);
	Zone* z_to = map->getZone(to);

	char c_team = team->getSymbol();
	char c_from = z_from->getItem(c_team)->getMapChar();
	char c_to = z_to->getItem(c_team)->getMapChar();

	if (c_team != toupper(c_from)) return false;
	
	if (islower(c_from) && z_from == z_to) {
		return team->getWarehouse()->createBase(z_to) != NULL;
	}

	if(z_from == z_to) return false;
	if (tolower(c_team) == c_to) return false;

	if (z_to->getItem()->getClassName() == "Wall") return false;
	if (z_to->getItem()->getClassName() == "Mine") return false;

	std::vector<Zone*> visited;
	if (!isValidMove(team, z_from, z_to, visited)) return false;
	if (c_from == c_team) {
		return team->getWarehouse()->createUnit(z_to) != NULL;
	}

	z_to->addItem(z_from->takeItem(c_team));
	return true;
}

bool Game::isValidMove(Team * team, Zone * curr, Zone * finish, std::vector<Zone*>& visited)
{
	using namespace std;

	if (curr == finish) return true;

	if(find(visited.begin(), visited.end(), curr) != visited.end()) return false;

	visited.push_back(curr);

	char c_team = team->getSymbol();
	char c_curr = curr->getItem(c_team)->getMapChar();

	if (visited.size() > 1 && tolower(c_curr) != tolower(c_team) &&
		curr->getItem()->getClassName() != "Mine"
	) return false;
	
	bool isValid = false;
	vector<Zone*> adjs = curr->getAdjacencies();
	for (auto adj = adjs.begin(); adj != adjs.end(); ++adj) {
		isValid = isValid || isValidMove(team, *adj, finish, visited);
		if (isValid) break;
	}

	return isValid;
}

void Game::convertMoveString(std::string move, Coor & from, Coor & to)
{
	if(move.length() < 5) return;

	move[0] = toupper(move[0]);
	move[3] = toupper(move[3]);

	from.setY(move[0] - 'A');
	from.setX(move[1] - '1');

	to.setY(move[3] - 'A');
	to.setX(move[4] - '1');
}


void Game::initMap(char map[5][5])
{
	if (this->map != NULL) delete this->map;
	this->map = new Map(map);
}

void Game::print()
{
	using namespace std;
	cout << endl << endl;
	this->map->printMaterial();
	this->map->printMap();
}

Game::Game()
{
	map = NULL;
	turn = 1;
}


Game::~Game()
{
	delete map;
}
