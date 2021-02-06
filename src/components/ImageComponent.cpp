#include "ImageComponent.h"

ImageComponent::ImageComponent(ofImage* image) : image(image)
{

}

void ImageComponent::draw()
{
	if (this->image != nullptr) {
		// render image...
	}
}
