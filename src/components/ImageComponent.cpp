#include "ImageComponent.h"

ImageComponent::ImageComponent(ofImage* image) : image(image)
{
    
}

void ImageComponent::draw(ofShader& shader)
{
	if (this->image != nullptr)
    {
        shader.setUniformTexture("image", this->image->getTexture(), 1);

        this->image->draw(0, 0, this->image->getWidth(), this->image->getHeight());
	}
}
