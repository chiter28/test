#include <iostream>
#include "Game/Character.h"
	

int main()
{  
	#ifdef SKIP_GAME
		std::cout << "============= Game Skiped ==============";
		return 0;
	#endif
	Character hero1("Max");
	Character hero2("Dir");

	Character* attaker = &hero1;
	Character* defender = &hero2;
	
	int round = 1;
	bool lastFiredStatus = false;

	while (true) {

		

		std::cout << "================== Round " << round++ << " ====================\n";
		const bool fired = attaker->attack(*defender);
		if (!lastFiredStatus && !fired) {
			std::cout << '\n' << "============ Friendship wins! ============\n";
			break; 
		}
		lastFiredStatus = fired;

		if (defender->dead()) {
			std::cout << '\n' << "============ GAME OVER ============\n";
			std::cout << defender->name() << " is dead =(\n";
			std::cout << attaker->name() << " is wins !!! =)\n";
			break;
		}
		std::cout << "\n\n";
		std::swap(attaker, defender);
	}


}



