#include "ImageComponent.h"

ImageComponent::ImageComponent(ofImage* image) : image(image)
{
    ofDisableArbTex();

    bool bLoaded = this->shader.load(
        "passthrough_330_vs.glsl",
        "passthrough_330_fs.glsl");
}

void ImageComponent::draw()
{
	if (this->image != nullptr) {
        this->shader.begin();

        this->shader.setUniformTexture("image", this->image->getTexture(), 1);

        this->image->draw(0, 0, this->image->getWidth(), this->image->getHeight());

        this->shader.end();
	}
}
