#pragma once

#include <vector>

#include "Plane.h"
#include "GameObject.h"
#include "DynamicObject.h"

class AbstractCommand
{
public:
    //virtual ~AbstractCommand() {}
    virtual void Execute() = 0;
};

class DeleteDynamicObjCommand : public AbstractCommand
{
    std::vector<DynamicObject*>& _vecDynamicObj;
    DynamicObject* _pBomb;
public:
    DeleteDynamicObjCommand(std::vector<DynamicObject*>& vecDynamicObj, DynamicObject* pBomb) : 
        _vecDynamicObj(vecDynamicObj), _pBomb(pBomb) {}
    void Execute() override;
};

class DeleteStaticObjCommand : public AbstractCommand
{
    std::vector<GameObject*>& _vecStaticObj;
    GameObject* _pObj;
public:
    DeleteStaticObjCommand(std::vector<GameObject*>& vecStaticObj, GameObject* pObj) : 
        _vecStaticObj(vecStaticObj), _pObj(pObj) {}
    void Execute() override;
};

class DropBombCommand : public AbstractCommand
{
    const Plane* _pPlane;
    std::vector<DynamicObject*>& _vecDynamicObj;
    uint16_t& _bombsNumber;
    int16_t& _score;
public:
    DropBombCommand(const Plane* pPlane, std::vector<DynamicObject*>& vecDynamicObj, uint16_t& bombsNumber, int16_t& score) :
        _pPlane(pPlane), _vecDynamicObj(vecDynamicObj), _bombsNumber(bombsNumber), _score(score) {};
    void Execute() override;
};

