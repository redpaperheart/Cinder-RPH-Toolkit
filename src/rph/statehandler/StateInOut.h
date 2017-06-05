/*
 * StateInOut.h
 *
 * Created by Daniel Scheibel on 12/06/11.
 *
 * Copyright (c) 2011, Red Paper Heart, All rights reserved.
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
#pragma once

namespace rph{

class StateInOut {
  public:
    StateInOut();
    ~StateInOut();
    
    enum State{
        STATE_IN_START,
        STATE_IN,
        STATE_OUT_START,
        STATE_OUT
    };
    
    static std::string stateToString(const State &s){
        std::map<State, std::string> stateToString;
        stateToString[STATE_IN_START]     = "IN_START";
        stateToString[STATE_IN]           = "IN";
        stateToString[STATE_OUT_START]    = "OUT_START";
        stateToString[STATE_OUT]          = "OUT";
        return stateToString[s];
    }
    
    virtual void animateIn();
    virtual void animateOut();
    virtual void animateIn(bool forceAnim);
    virtual void animateOut(bool forceAnim);

    virtual State getCurState()const{return mCurState;};
        
    ci::signals::Signal<void ()> signal_onAnimateInStart;
    ci::signals::Signal<void ()> signal_onAnimateIn;
    ci::signals::Signal<void ()> signal_onAnimateOutStart;
    ci::signals::Signal<void ()> signal_onAnimateOut;
    
  protected:
    //override these ones, and don't forget to call _onAnimateIn()/_onAnimateOut() at the end.
    virtual void _animateIn();
    virtual void _animateOut();
    
    virtual void _onAnimateIn();
    virtual void _onAnimateOut();
    
    State mCurState;
    
    bool mDispatchCompleteOnUnchangedState;
    
};
}
