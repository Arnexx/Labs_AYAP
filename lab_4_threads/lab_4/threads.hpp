#pragma once
#include "Line.hpp"
#include "Octahedron.hpp"
#include "Square.hpp"

DWORD WINAPI drawfunc(void* pParams);
void newThreads(WindowParams* params);
void killThreads(WindowParams* params);