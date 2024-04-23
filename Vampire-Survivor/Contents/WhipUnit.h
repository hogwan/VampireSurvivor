#pragma once

// Ό³Έν :
class WhipUnit
{
public:
	// constructor destructor
	WhipUnit();
	~WhipUnit();

	// delete Function
	WhipUnit(const WhipUnit& _Other) = delete;
	WhipUnit(WhipUnit&& _Other) noexcept = delete;
	WhipUnit& operator=(const WhipUnit& _Other) = delete;
	WhipUnit& operator=(WhipUnit&& _Other) noexcept = delete;

protected:

private:

};

