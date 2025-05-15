#include "Utils/math.h"
#include "Game/Character.h"
#include <cassert>

int main()
{
    assert(max(3, 0) == 3);
    assert(max(-3, 0) == 0);

    Character hero("Pacman");
    assert(!hero.dead());

    hero.takeDamage(10);
    assert(!hero.dead());

    hero.takeDamage(1000);
    assert(hero.dead());
}