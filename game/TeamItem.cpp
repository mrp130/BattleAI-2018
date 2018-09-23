#include "TeamItem.h"


TeamItem::TeamItem(Zone* zone, Team* team) : GameItem(zone) , team(team) {}
TeamItem::~TeamItem() {}

Team * TeamItem::getTeam()
{
	return team;
}

int TeamItem::canMine()
{
	char team = this->getTeam()->getSymbol();
	int total = 0;
	std::vector<Zone*> adjs = this->zone->getAdjacencies();
	for (auto adj = adjs.begin(); adj != adjs.end(); ++adj) {
		if ((*adj)->getItem()->getClassName() == "Mine") {
			bool canBeMined = true;
			std::vector<Zone*> mine_adjs = (*adj)->getAdjacencies();
			for (auto m = mine_adjs.begin(); m != mine_adjs.end(); ++m) {
				char c = (*m)->getItem()->getMapChar();
				c = toupper(c);
				if (c < 'A' || c > 'B') continue;
				if (c != team) {
					canBeMined = false;
					break;
				}
			}
			if (canBeMined) total++;
		}
	}
	return total;
}
