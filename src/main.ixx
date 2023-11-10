module;
#include <raylib.h>

export module Main;
import Router;
//----------------------------------------------------------------------------------
// Global Variables Declaration (shared by several modules)
//----------------------------------------------------------------------------------
export Font font = {
    0
};
export Music music = {
    { nullptr }
};
export Sound fxCoin = {
    { nullptr }
};
export Router router = Router();