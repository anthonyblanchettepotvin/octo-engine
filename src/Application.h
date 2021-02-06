#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Scene.h"

class Application : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void onActorAdded(Actor& actor);
	void onImageAdded(ofImage& image);

private:
	// --------------------------------------------------
	// Scene
	// --------------------------------------------------

	Scene* scene = nullptr;

	// --------------------------------------------------
	// UI
	// --------------------------------------------------
	
	// file import panel

	ofxPanel fileImportPnl;
	ofxButton imageImportBtn;

	void handleImageImportBtnClicked();

	// create actor panel

	ofxPanel createActorPnl;
	ofxButton createImageActorBtn;

	void handleAddImageActorBtnClicked();

	// actor list panel

	ofxPanel actorListPnl;

	void handleActorTglClicked(bool& value);
};
