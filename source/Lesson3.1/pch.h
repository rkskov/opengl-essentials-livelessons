#pragma once

// Windows
#include <windows.h>

// Standard
#include <stdlib.h>
#include <crtdbg.h>
#include <memory>
#include <vector>

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
#include "Utility.h"
#include "DrawableGameComponent.h"
#include "Camera.h"
#include "FirstPersonCamera.h"
#include "VertexDeclarations.h"
#include "ShaderProgram.h"

// Local
#include "RenderingGame.h"
#include "ColoredTriangleDemo.h"

//TODO: remove
#define DeleteObject(object) if((object) != NULL) { delete object; object = NULL; }
#define DeleteObjects(objects) if((objects) != NULL) { delete[] objects; objects = NULL; }
