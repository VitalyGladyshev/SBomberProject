#include <string>

#include "Bomb.h"
#include "Ground.h"
#include "Commands.h"
#include "FileLoggerSingletone.h"

using namespace std;

void DeleteDynamicObjCommand::Execute()
{
    LoggerSingletone::getInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

    auto it = _vecDynamicObj.begin();
    for (; it != _vecDynamicObj.end(); it++)
    {
        if (*it == _pBomb)
        {
            _vecDynamicObj.erase(it);
            break;
        }
    }
}

void DeleteStaticObjCommand::Execute()
{
    LoggerSingletone::getInstance().WriteToLog(string(__FUNCTION__) + " was invoked");
    
    auto it = _vecStaticObj.begin();
    for (; it != _vecStaticObj.end(); it++)
    {
        if (*it == _pObj)
        {
            _vecStaticObj.erase(it);
            break;
        }
    }
}

void DropBombCommand::Execute()
{
    if (_bombsNumber > 0)
    {
        LoggerSingletone::getInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

        double x = _pPlane->GetX() + 4;
        double y = _pPlane->GetY() + 2;

        Bomb* pBomb = new Bomb;
        pBomb->SetDirection(0.3, 1);
        pBomb->SetSpeed(2);
        pBomb->SetPos(x, y);
        pBomb->SetWidth(SMALL_CRATER_SIZE);

        _vecDynamicObj.push_back(pBomb);
        _bombsNumber--;
        _score -= Bomb::BombCost;
    }
}
