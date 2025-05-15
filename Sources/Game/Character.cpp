#include <iostream>
#include <thread>
#include "Character.h"
#include "Weapon.h"
#include "Utils/math.h"





Character::Character(const char* name)
	: m_name{ name }
{
	const int bulletCount = randomInt(1, 10);
	m_weapon = new Weapon(bulletCount);
}

Character::~Character()
{
	delete m_weapon;
	m_weapon = nullptr;
}

const char* Character::name() const
{
	return m_name;
}


bool Character::attack(Character& target)
{

	const bool fired = m_weapon->fire();
	if (fired) {
		const int demage = m_weapon->damage();
		std::cout << m_name << " is attacking with damage: " << demage << "\n";
		target.takeDamage(demage);
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
	else {
		std::cout << m_name << " has no more bullets. Shit... bad day...: " << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(300));

	}

	return fired;
}

void Character::takeDamage(int damage)
{
	m_health -= damage;
	if (m_health < 0) m_health = 0;

	std::cout << m_name << " was attecked, current health: " << m_health << "\n";
}

bool Character::dead() const
{
	if (m_health == 0) {
		return true;
	}
	return false;
}

