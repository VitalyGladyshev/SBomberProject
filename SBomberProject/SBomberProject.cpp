
#include <conio.h>

#include "SBomber.h"
#include "MyTools.h"
#include "FileLoggerSingletone.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    LoggerSingletone::getInstance().OpenLogFile("log.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.CommandExecuter();
        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    LoggerSingletone::getInstance().CloseLogFile();

    return 0;
}
