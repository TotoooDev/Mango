#pragma once
#include <Mango/OS.h>

#ifdef MANGO_DEBUG
	#include <iostream>
	#define MANGO_LOG_INFO(x) std::cout << x << std::endl; 
	#define MANGO_LOG_ERROR(x) std::cerr << x << std::endl; 
#else
	#define MANGO_LOG_INFO(x)
	#define MANGO_LOG_ERROR(x)
#endif

#ifdef MANGO_DO_ASSERT
	#define MANGO_ASSERT(x, info) if (!x) { MANGO_LOG_ERROR(info); MANGO_LOG_ERROR("You know what? Fuck this. *crashes*"); *((char*)-1) = 'x'; } // We stop the program the funnier way here
	#define MANGO_STOP(info) MANGO_ASSERT(false, info)
#else
	#define MANGO_ASSERT(x, info)
	#define MANGO_STOP(info)
#endif