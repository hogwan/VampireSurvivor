#pragma once

enum class ERenderOrder
{
	Back,
	Title,
	Exp,
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
	Exp,
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

enum class ESelectList
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

enum class EUI
{
	HPBar,
	HPBar_Back,
	LevelBar,
	LevelBar_Back,
	LevelVal,
	KillCount,
	Gold,
	EquipList,

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
