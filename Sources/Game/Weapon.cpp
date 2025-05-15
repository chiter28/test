#include "Utils/math.h"
#include "Weapon.h"

Weapon::Weapon(int bullets) : m_bullet{ bullets }
{
}  
 
bool Weapon::fire() { 
	if (m_bullet <= 0) return false;
	--m_bullet;
	return true;
}

int Weapon::damage() const
{ 
	return randomInt(10, 30);
}
