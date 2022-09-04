#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs();

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;

    class BombIterator { // «Итератор» по объектам Bomb в массиве vecDynamicObj
        std::vector<DynamicObject*>& refArr;
        int curIndex;
    public:
        BombIterator(std::vector<DynamicObject*>& ref) : refArr(ref), curIndex(-1) { ++(*this); }
        
        void reset() { curIndex = -1; }
        BombIterator& operator++ (); // префиксный инкремент
        BombIterator& operator-- (); // префексный декремент
        Bomb* operator*(); // операция разыменования итератора
        bool operator==(BombIterator it); // проверка на лог. равенство итераторов
        bool operator!=(BombIterator it); // проверка на лог. неравенство
    };

    // получаем итератор настроенный на начало массива
    BombIterator begin() { BombIterator it(vecDynamicObj); return it; }
    // итератор в конечном состоянии
    BombIterator end() { BombIterator it(vecDynamicObj); it.reset(); return it; }
};