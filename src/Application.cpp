#include "Application.h"

#include "components/TransformComponent.h"
#include "components/ImageComponent.h"

void Application::setup()
{
	// setup scene
	this->scene = new Scene(new SceneRenderer());

	ofAddListener(this->scene->onActorAdded, this, &Application::onActorAdded);
	ofAddListener(this->scene->onImageAdded, this, &Application::onImageAdded);

	// setup file import panel
	this->fileImportPnl.setup("Import file");
	this->fileImportPnl.add(this->imageImportBtn.setup("Import image"));

	this->imageImportBtn.addListener(this, &Application::handleImageImportBtnClicked);

	// setup actor panel
	this->createActorPnl.setup("Create actor");
	this->createActorPnl.add(this->createImageActorBtn.setup("Create image actor"));

	this->createImageActorBtn.addListener(this, &Application::handleAddImageActorBtnClicked);

	// setup actor list panel
	this->actorListPnl.setup("Actor list");
}

void Application::update()
{

}

void Application::draw()
{
	this->scene->draw();

	this->fileImportPnl.draw();
	this->createActorPnl.draw();
	this->actorListPnl.draw();
}

void Application::exit()
{

}

void Application::keyPressed(int key)
{

}

void Application::keyReleased(int key)
{

}

void Application::mouseMoved(int x, int y )
{

}

void Application::mouseDragged(int x, int y, int button)
{

}

void Application::mousePressed(int x, int y, int button)
{

}

void Application::mouseReleased(int x, int y, int button)
{

}

void Application::mouseEntered(int x, int y)
{

}

void Application::mouseExited(int x, int y)
{

}

void Application::windowResized(int w, int h)
{

}

void Application::gotMessage(ofMessage msg)
{

}

void Application::onActorAdded(Actor& actor)
{
	ofxToggle* item = new ofxToggle();

	this->actorListPnl.add(item->setup(to_string((int)&actor), false));

	item->addListener(this, &Application::handleActorTglClicked);
}

void Application::onImageAdded(ofImage& image)
{
	ofLogNotice() << "image added";
}

void Application::handleImageImportBtnClicked()
{
	ofFileDialogResult result = ofSystemLoadDialog("Import image");

	if (result.bSuccess) {
		ofImage* image = new ofImage(result.getPath());

		this->scene->addImage(image);
	}
}

void Application::handleAddImageActorBtnClicked()
{
	Actor* imageActor = new Actor();

	imageActor->addComponent(new TransformComponent());
	imageActor->addComponent(new ImageComponent(this->scene->getFirstImage()));

	this->scene->addActor(imageActor);
}

void Application::handleActorTglClicked(bool& value)
{
	ofLogNotice() << "actor added";
}

void Application::dragEvent(ofDragInfo dragInfo)
{ 

}
