#include <iostream>

enum class JOB
{
	Knight, 
	Archer, 
	Magicion
};

struct Player
{
	char Name[32];
	JOB Job;
	int Attack;
	int Armor;
	int HP;
	int HPMax;
	int MP;
	int MPMax;
};

int main()
{
	std::cout << sizeof(Player) << std::endl;

	Player player;

	return 0;
}