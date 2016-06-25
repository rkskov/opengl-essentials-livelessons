#pragma once

// Windows
#include <windows.h>

// Standard
#include <stdlib.h>
#include <crtdbg.h>
#include <memory>
#include <vector>

// OpenGL
#include "GL/gl3w.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

// Library
#include "GameException.h"
#include "Game.h"
#include "ColorHelper.h"
#include "Utility.h"
#include "DrawableGameComponent.h"
#include "FirstPersonCamera.h"

// Local
#include "RenderingGame.h"
#include "PointDemo.h"

//TODO: remove
#define DeleteObject(object) if((object) != NULL) { delete object; object = NULL; }
#define DeleteObjects(objects) if((objects) != NULL) { delete[] objects; objects = NULL; }
