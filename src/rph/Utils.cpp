//
//  Utils.cpp
//
//  Created by Adrià Navarro López on 5/5/16.
//
//

#include "Utils.h"

namespace rph {
    
    std::string getTimestamp(const std::string &format)
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), format.c_str());
        return ss.str();
    }
    
    std::string getDateString()
    {
        return getTimestamp("%Y%m%d");
    }
    
    std::string getTimeString()
    {
        return getTimestamp("%H%M%S");
    }
    
    std::string toTwoDec( float num )
    {
        std::ostringstream out;
        out << std::fixed << std::setprecision( 2 ) << num;
        return out.str();
    }
    
}
