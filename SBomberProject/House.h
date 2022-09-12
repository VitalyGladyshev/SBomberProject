#pragma once

#include <stdint.h>
#include <vector>
#include <string>

#include "DestroyableGroundObject.h"

class House : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	friend class HouseBuilderA;

private:

	const uint16_t score = 40;

	std::vector<std::string> vecHouse;
};

class HouseBuilder
{
protected:
	House* pHouse;
public:
	HouseBuilder() : pHouse(nullptr) {}
	
	virtual void createHouse() {}
	virtual void buildBlock() {}
	virtual void buildChimney() {}
	virtual void buildWindows() {}
	
	virtual House* getHouse() { return pHouse; }
};

class HouseBuilderA : public HouseBuilder
{
public:

	void createHouse() { pHouse = new House; }

	void buildBlock();
	void buildChimney();
	void buildWindows();
};

class HouseDirector
{
	bool _bChimney;
	bool _bWindows;

public:
	HouseDirector(bool bChimney = true, bool bWindows = true) : _bChimney(bChimney), _bWindows(bWindows) {};
	
	House* createHouse(HouseBuilder& builder);
};
