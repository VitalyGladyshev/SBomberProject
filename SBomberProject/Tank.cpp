
#include <iostream>
#include <sstream>
#include <ctime>

#include "Tank.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

Tank::Tank(Mediator* _pMed, std::string _sMessage) : pMediator(_pMed), sMessage(_sMessage)
{
	srand(time(NULL)); 
	vecMessages.push_back("Plane is bad!");
	vecMessages.push_back("Plane go home!");
	vecMessages.push_back("Plane never forever!");
}

bool Tank::isInside(double x1, double x2) const
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

void Tank::Draw() const
{
	//ostringstream ss;
	//ss << 1 + rand() % 20;
	//string s(ss.str());
	
	MyTools::SetColor(CC_Brown);
	GotoXY(x, y - 3);
	cout << "    #####";
	GotoXY(x-2, y - 2);
	cout << "#######   #";
	GotoXY(x, y - 1);
	cout << "    #####";
	GotoXY(x,y);
	cout << " ###########";

	if ((1 + rand() % 20) == 20)
		pMediator->Notify(sMessage + ": " + vecMessages[rand() % vecMessages.size()]);
}