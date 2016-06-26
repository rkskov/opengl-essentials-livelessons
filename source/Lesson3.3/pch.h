#pragma once

// Windows
#include <windows.h>

// Standard
#include <stdlib.h>
#include <crtdbg.h>
#include <memory>
#include <vector>
#include <algorithm>

#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

// OpenGL
#include "GL/gl3w.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// Library
#include "GameException.h"
#include "Game.h"
#include "ColorHelper.h"
#include "VectorHelper.h"
#include "Utility.h"
#include "DrawableGameComponent.h"
#include "Camera.h"
#include "FirstPersonCamera.h"
#include "VertexDeclarations.h"
#include "ShaderProgram.h"
#include "Grid.h"
#include "Model.h"
#include "Mesh.h"

// Local
#include "RenderingGame.h"
#include "ModelDemo.h"

//TODO: remove
#define DeleteObject(object) if((object) != NULL) { delete object; object = NULL; }
#define DeleteObjects(objects) if((objects) != NULL) { delete[] objects; objects = NULL; }
