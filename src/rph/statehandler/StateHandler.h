/*
 * StateHandler.h
 *
 * Created by Daniel Scheibel on 04/17/11.
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
    
//    class State{
//        public:
//        State::State(std::string s){
//            
//        }
//        int id;
//        
//    };
    
    typedef int State;
    const static State STATE_NONE = 0;
    const static State STATE_IN = 1;
    const static State STATE_OUT = 2;
    
    class StateHandler {
      public:
        StateHandler();
        ~StateHandler();
        
        static std::string stateToString(const State &s);
        
        virtual void changeState(State nextState);//, bool force = false
        virtual bool isTransitioningStates();

        virtual State getCurState()const{ return mCurState; };
        //void setCurState(const State &stateId); -> onStateChangeComplete()

        virtual State getNextState()const{ return mNextState; }
        //void setNextState(const State &stateId); -> changeState( State s)
        
        ci::signals::Signal<void ()> signal_onStateChangeStart;
        ci::signals::Signal<void ()> signal_onStateChangeComplete;
        
      protected:    
        State mCurState;
        State mNextState;
        
        bool mAllowChangeStateWhileTransitioning = false;
        virtual void onStateChangeComplete();
        
        static std::map<State, std::string> mStateToString;
        
        // private functions to override in subclasses
        virtual void _changeState(State s);
        virtual void _onStateChangeComplete();

        
        
    };
    
}
