//
//	RenderUtils.h
//	
//	Created by Shuvashis Das
//	05/22/2018
//


#pragma once

#include "cinder/app/App.h"
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace ci;

namespace rph 
{

	class RenderUtils
	{

	private:
		// singleton implementation
		RenderUtils(){};
		~RenderUtils(){};
		RenderUtils(RenderUtils const&){};
		RenderUtils& operator=(RenderUtils const&){return *m_pInstance;};
		static RenderUtils* m_pInstance;

	public:
		static RenderUtils* getInstance();
		void drawSolidRect(float width, float height);
	
	protected:

		void setup();
		gl::BatchRef	mRectBatch;
		
			
	};

	inline 	void drawSolidRect(float width, float height){  RenderUtils::getInstance()->drawSolidRect(width, height); };


}
