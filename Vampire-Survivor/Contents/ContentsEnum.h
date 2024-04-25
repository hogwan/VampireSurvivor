#pragma once

enum class ERenderOrder
{
	Knife,
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

enum class EWeapon
{
	None,
	Axe,
	Cross,
	FireWand,
	Garlic,
	KingBible,
	Knife,
	LightingRing,
	MagicWand,
	RuneTracer,
	SantaWater,
	Whip,
};

enum class EAccessory
{
	None,
	Armor,
	Attractorb,
	Bracer,
	Candelabrador,
	Clover,
	Duplicator,
	EmptyTome,
	HollowHeart,
	Pummarola,
	Spellbinder,
	Spinach,
	Wings,
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
