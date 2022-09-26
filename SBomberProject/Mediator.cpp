#include "Mediator.h"


void Mediator::AddColleague(Tank* pNewTank)
{
    v.push_back(pNewTank);
}

void Mediator::Notify(string info)
{
    clGUI->AddMessage(info);
}
