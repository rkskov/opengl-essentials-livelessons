#pragma once

// Windows
#include <windows.h>

// Standard
#include <memory>

#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

// OpenGL
#include "GL/gl3w.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

// Library
#include "GameException.h"
#include "Game.h"
#include "ColorHelper.h"

// Local
#include "RenderingGame.h"