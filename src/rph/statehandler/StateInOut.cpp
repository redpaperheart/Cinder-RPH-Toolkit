/*
 * StateInOut.cpp
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
#include "StateInOut.h"
namespace rph{

StateInOut::StateInOut(){
    mCurState = STATE_OUT;
    mDispatchCompleteOnUnchangedState = true;
}
StateInOut::~StateInOut(){}

void StateInOut::animateIn(){
    animateIn(false);
}
void StateInOut::animateIn( bool forceAnim ){
    if((mCurState != STATE_IN_START && mCurState != STATE_IN) || forceAnim ){
        mCurState = STATE_IN_START;
        signal_onAnimateInStart.emit();
        _animateIn();
    }else if(mCurState == STATE_IN && mDispatchCompleteOnUnchangedState){
        signal_onAnimateIn.emit();
    }
}
void StateInOut::animateOut(){
    animateOut(false);
}
void StateInOut::animateOut( bool forceAnim ){
    if(mCurState == STATE_IN || forceAnim){
        mCurState = STATE_OUT_START;
        signal_onAnimateOutStart.emit();
        _animateOut();
    }else if(mCurState == STATE_OUT && mDispatchCompleteOnUnchangedState){
        signal_onAnimateOut.emit();
    }
}

void StateInOut::_animateIn(){
    _onAnimateIn();
}

void StateInOut::_animateOut(){
    _onAnimateOut();
}

void StateInOut::_onAnimateIn(){
    mCurState = STATE_IN;
    signal_onAnimateIn.emit();
}

void StateInOut::_onAnimateOut(){
    mCurState = STATE_OUT;
    signal_onAnimateOut.emit();
}
    
}
