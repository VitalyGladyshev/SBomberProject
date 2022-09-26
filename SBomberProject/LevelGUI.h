#pragma once

#include <stdint.h>
#include <string>
#include <vector>

#include "GameObject.h"

using namespace std;

class LevelGUI : public GameObject {
public:

    LevelGUI() : bombsNumber(0), score(0), passedTime(0), fps(0), messageTime(0), height(0) 
    { /*vecMessage.push_back("Hello Plane!"); vecMessage.push_back("Plane Hello!");*/ }

    void __fastcall SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew);
    
    void __fastcall SetHeight(uint16_t heightN) { height = heightN; };
    
    inline uint16_t GetFinishX() const { return finishX; }
    inline void SetFinishX(uint16_t finishXN) { finishX = finishXN; }

    void Draw() const override;

    void AddMessage(string sMessage);

private:

    uint16_t height;
    uint16_t finishX = 109;

    uint64_t passedTime, fps;
    mutable uint64_t messageTime;
    uint16_t bombsNumber;
    int16_t score;

    mutable vector<string> vecMessage;
};



