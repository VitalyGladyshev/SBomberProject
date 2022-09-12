
#include <iostream>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	MyTools::SetColor(CC_Yellow);

	for (int i = 0; i < vecHouse.size(); i++)
	{
		GotoXY(x, y - vecHouse.size() + 1 + i);
		cout << vecHouse[i];
	}
}

void HouseBuilderA::buildBlock()
{
	pHouse->vecHouse.clear();
	pHouse->vecHouse.push_back("            ");
	pHouse->vecHouse.push_back("  ########  ");
	pHouse->vecHouse.push_back("##        ##");
	pHouse->vecHouse.push_back("#          #");
	pHouse->vecHouse.push_back("#          #");
	pHouse->vecHouse.push_back("############");
}

void HouseBuilderA::buildChimney()
{
	if(pHouse->vecHouse.size() > 0)
		pHouse->vecHouse[0] = "       ##   ";
}

void HouseBuilderA::buildWindows()
{
	if (pHouse->vecHouse.size() >= 4)
		pHouse->vecHouse[3] = "#  ##  ##  #";
}

House* HouseDirector::createHouse(HouseBuilder& builder) 
{
	builder.createHouse();

	builder.buildBlock();
	if (_bChimney)
		builder.buildChimney();
	if(_bWindows)
		builder.buildWindows();

	return builder.getHouse();
}
