//
//  Utils.cpp
//
//  Created by Adrià Navarro López on 5/5/16.
//
//

#include "Utils.h"
#include <sstream> 

namespace rph {
    
    void searchAndAddAssetDirectory(std::string dir, int depth){
        // expecting a relative path
        for(int i = 0; i < depth; i++ ){
            if( fs::exists(ci::app::getAppPath() / dir) ){
//                ci::app::console() << "Adding Asset folder: " << (ci::app::getAppPath() / dir) << std::endl;
                cinder::app::addAssetDirectory(ci::app::getAppPath() / dir);
                break;
            }
            dir = "../"+dir;
        }
    }
    
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
	
	ci::ColorA getColorAFromRgbaString(std::string rgba){
		// accepts strings in the form of "rgba(225,163,92,0.6)"
		try{
			int start = rgba.find("(")+1;
			int end = rgba.find(")") - start;
			rgba = rgba.substr(start, end);		std::vector<std::string> colorValues = ci::split( rgba, ',');
			return ci::ColorA( std::stof(colorValues[0])/255.0f,std::stof(colorValues[1])/255.0f,std::stof(colorValues[2])/255.0, std::stof(colorValues[3]) );
		}catch(...){
			CI_LOG_E( "rph::getColorAFromRgbaString|Error converting " << rgba << " to ci::ColorA." );
		}
	}
	
	std::string toRgbaString(ColorA c){
		std::string str = "rgba(";
		str += ci::toString(int(c.r*255.0f))+",";
		str += ci::toString(int(c.g*255.0f))+",";
		str += ci::toString(int(c.b*255.0f))+",";
		str += ci::toString(c.a);
		str += ")";
		return str;
	}
    
}
