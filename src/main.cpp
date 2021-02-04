#include "ofMain.h"
#include "Application.h"

int main( )
{
	ofGLFWWindowSettings windowSettings;

	windowSettings.setSize(1280, 720);
	windowSettings.setGLVersion(3, 3);

	ofCreateWindow(windowSettings);

	ofRunApp(new Application());
}
