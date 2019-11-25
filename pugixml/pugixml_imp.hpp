#pragma once

#if defined(_WIN32)
#define PUGIXML_CLASS __declspec(dllimport)
#else
#define PUGIXML_CLASS
#endif
#include "pugixml/pugixml.hpp"

