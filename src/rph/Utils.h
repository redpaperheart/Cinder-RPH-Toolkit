
#pragma once

#include "cinder/app/App.h"
#include "cinder/Utilities.h"
#include "cinder/Log.h"
using namespace ci;

namespace rph {
    std::string getTimestamp(const std::string &format = "%Y%m%d_%H%M%S");

    std::string toTwoDec( float num );
    
    std::string getDateString();
    std::string getTimeString();
    
    void searchAndAddAssetDirectory(std::string dir, int depth = 10);
    
    template<typename T>
    T clampedLmap(T val, T inMin, T inMax, T outMin, T outMax)
    {
        return glm::clamp(lmap(val, inMin, inMax, outMin, outMax), outMin, outMax);
    }
    
    template<typename T>
    T smoothLmap(T val, T inMin, T inMax, T outMin, T outMax)
    {
        return outMin + ((outMax - outMin) * smoothstep(inMin, inMax, val));
    }
	
	// concert "rgba(225,163,92, .6)" to ci::Color
	ci::ColorA getColorAFromRgbaString(std::string rgba);
}
