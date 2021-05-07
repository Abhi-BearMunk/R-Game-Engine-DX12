#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers.
#endif

#include "../Test/TestGame.h"

int main()
{
    TestGame game;
    game.Init();
    while(true)
    {
        game.Update();
    }
    return 0;
}