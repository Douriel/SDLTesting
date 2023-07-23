#include "KeyTest.h"

KeyTest::KeyTest()
{
}

KeyTest::~KeyTest()
{
}

void KeyTest::checkKey()
{
 /*   while (SDL_PollEvent(&Event)) {
        if (Event.type == SDL_KEYDOWN) {
            
        }
    }*/
}

void KeyTest::PrintKeyInfo(SDL_KeyboardEvent* key)
{
    std::cout
        << "Key Pressed! Key Code: ";
        ////<< key.key.keysym.sym
        ////<< ", Key Name: "
        ////<< SDL_GetKeyName(key.key.keysym.sym)
        ////<< '\n';
}
