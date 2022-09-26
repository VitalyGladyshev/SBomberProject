#pragma once

#include <vector>
#include <string>

#include "LevelGUI.h"

using namespace std;

class Tank;

class Mediator
{
public:
    Mediator(LevelGUI* _clGUI) : clGUI(_clGUI) {};
    
    void AddColleague(Tank* pNewTank);

    void Notify(string info);

private:
    vector<Tank*> v;
    LevelGUI* clGUI;
};

