#pragma once

#define GEODE_API
#define GEODE_DLL 

namespace geode {
	using dylib_t = void*;
    struct PlatformInfo {
    	dylib_t m_dylib;
    };
}
