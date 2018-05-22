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
		auto lambert = gl::ShaderDef().color();
		gl::GlslProgRef shader = gl::getStockShader( lambert );	
		mRectBatch = gl::Batch::create( geom::Rect(), shader );
	}

	void RenderUtils::drawSolidRect(float width, float height)
	{
		gl::ScopedMatrices mat;
		gl::scale(width, height);
		mRectBatch->draw();

	}
} //namesoace rph