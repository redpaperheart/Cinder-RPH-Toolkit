/*
 * Distribution.cpp
 *
 * Created by Daniel Scheibel on 10/25/12.
 *
 * Copyright (c) 2012, Red Paper Heart, All rights reserved.
 * This code is intended for use with the Cinder C++ library: http://libcinder.org
 *
 * To contact Red Paper Heart, email hello@redpaperheart.com or tweet @redpaperhearts
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in
 * the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "Distribution.h"
namespace rph {
    
    void Distribution::setup(std::vector<float> dist){
        mDist = dist;
        float sum = 0.0f;
        for( std::vector<float>::iterator it = mDist.begin(); it != mDist.end(); it++){
            sum += (*it);
        }
        float sumPct = 0.0f;
        for( std::vector<float>::iterator it = mDist.begin(); it != mDist.end(); it++){
            sumPct += (*it);
            mDistPct.push_back( sumPct/sum);
        }
    }
    
    int Distribution::getIndexByPerc(float perc){
        perc = ci::math<float>::clamp(perc, 0.0f, 1.0f);
        for (int i = 0; i<mDistPct.size(); i++){
            if( perc <= mDistPct[i]){
                return i;
            }
        }
        return -1;
    }
    
    std::string Distribution::toStr(){
        if(mDist.empty() || mDistPct.empty()) return "distribution lists are empty.";
        
        std::string str = "<";
        for(int i=0; i<mDist.size()-1; i++){
            str += ci::toString(mDist[i])+",";
        }
        str += ci::toString(mDist[mDist.size()-1])+"> -> <";
        
        for(int i=0; i < mDistPct.size()-1; i++){
            str += ci::toString(mDistPct[i])+",";
        }
        str += ci::toString(mDistPct[mDistPct.size()-1])+">";
        return str;
    }
}