#pragma once

enum class ERenderOrder
{
	Back,
	Monster,
	Garlic,
	PlayerWeapon,
	Particle,
	Player,

};

enum class ECollisionOrder
{
	Player,
	Monster,
	Item,
	PlayerWeapon,
	Detect,
};

enum class EPollingOrder
{
	None,
	Bat1,
	Bat2,
	Bat3,
	Zombie1,
	Zombie2,
	Zombie3,
	Zombie4,
	Mentis,
	Skeleton,
	WereWolf,
	Medusa,
	Experience,
	Money,
	Weapon,
};

enum class EEnemySpawnData
{
	Bat,
	Zombie1,
	Zombie2,
	Zombie3,
	Zombie4,
	Mentis,
	Skeleton,
	WereWolf,
	Medusa,
};
