/*
 * StateHandler.cpp
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
#include "StateHandler.h"
namespace rph{
    
    std::map<State, std::string> StateHandler::mStateToString;
    
    std::string StateHandler::stateToString(const State &s){
        if( mStateToString.find(s) != mStateToString.end()){
            return mStateToString[s];
        }else{
            return "!State not registered in mStateToString map!";
        }
    }
    
    StateHandler::StateHandler(){
        mCurState = STATE_NONE;
        mNextState = STATE_NONE;
        
        mStateToString[STATE_NONE]         = "STATE_NONE";
        mStateToString[STATE_IN]           = "STATE_IN";
        mStateToString[STATE_OUT]          = "STATE_OUT";
        
        //mDispatchCompleteOnUnchangedState = true;
    }
    StateHandler::~StateHandler(){}
    
    
    void StateHandler::changeState(State nextState){ //, bool force
        //ci::app::console()<< "StateHandler::changeState( "<< stateToString(nextState) <<" ), cur: " << stateToString(mCurState)<<std::endl;
        // special case if transitioning:
        if(!mAllowChangeStateWhileTransitioning && isTransitioningStates() ) return;
        // special case if same state
        //if( mCurState == nextState && mCurState != STATE_NONE ) { return; }
        
        mNextState = nextState;
        signal_onStateChangeStart.emit();
        
        // switch statement
        _changeState(nextState);
    }
    
    void StateHandler::onStateChangeComplete(){
        // switch statement
        _onStateChangeComplete();
        
        mCurState = mNextState;
        mNextState = STATE_NONE;
        signal_onStateChangeComplete.emit();
    }
    
    
    void StateHandler::_changeState(State s){
        // switch statement here..
        onStateChangeComplete();
    };
    void StateHandler::_onStateChangeComplete(){
        // switch statement here
    };
    
    
    bool StateHandler::isTransitioningStates(){
        bool b = ( mNextState != STATE_NONE );
        //cinder::app::console() << "Model::isTransitioningStates() : " << b << "-" << stateToString(mNextState) << std::endl;
        return b;
    }
}
