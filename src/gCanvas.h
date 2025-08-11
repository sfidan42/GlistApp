/*
* gCanvas.h
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#ifndef GAMECANVAS_H_
#define GAMECANVAS_H_

#include "ecs.hpp"
#include "gBaseCanvas.h"
#include "gFont.h"
#include "gCamera.h"
#include "gLight.h"
#include "gModel.h"
#include "components/primitives.h"
#include "ecs.hpp"

class gCanvas : public gBaseCanvas {
public:
	gCanvas(gBaseApp *root);
	virtual ~gCanvas();

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered();
	void mouseExited();

	void showNotify();
	void hideNotify();

private:
	gFont font;

	float animationTime = 0.0f;
	float animationDuration = 0.0f;

	ecs::Registry reg;
	gCamera camera;

};

#endif /* GAMECANVAS_H_ */
