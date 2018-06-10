#include "rph/RenderUtils.h"

namespace rph{

	RenderUtils* RenderUtils::m_pInstance = NULL;
	RenderUtils* RenderUtils::getInstance(){
		if (!m_pInstance){ // Only allow one instance of class to be generated.
			m_pInstance = new RenderUtils();

			m_pInstance->setup();
		}
		return m_pInstance;
	}

	void RenderUtils::setup()
	{
		gl::GlslProgRef shader = gl::getStockShader( gl::ShaderDef().color() );
		mRectBatch = gl::Batch::create( geom::Rect(Rectf(0,0,1,1)), shader );
	}

	void RenderUtils::drawSolidRect(float width, float height)
	{
		gl::ScopedMatrices mat;
		gl::scale(width, height);
		mRectBatch->draw();
	}
	
	void RenderUtils::drawSolidRect(DisplayObject2D *obj){
		gl::ScopedMatrices mat;
		gl::ScopedColor c(obj->mColorA);
		gl::translate(obj->mPos() + obj->mOffset());
		gl::scale(obj->mWidth, obj->mHeight);
		mRectBatch->draw();
	}
} //namesoace rph
