#pragma once

#ifdef EXPORT
#define GAME_API __declspec(dllexport)
#elif IMPORT 
#define GAME_API __declspec(dllimport)
#else 
#define GAME_API
#endif // EXPORT

class Weapon;

class GAME_API Character
{
public:
	Character(const char* name);

	~Character();

	const char* name() const;
	bool attack(Character& target);
	void takeDamage(int damage);
	bool dead() const;

private:
	const char* m_name;
	Weapon* m_weapon;
	int m_health{ 100 };
};