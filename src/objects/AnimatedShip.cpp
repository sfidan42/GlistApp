#include "objects/AnimatedShip.h"

AnimatedShip::AnimatedShip(const Ship* ship) : AShipBase(ship->getFramePathFmt()) {
	if (!ship) {
		gLoge("AnimatedShip::AnimatedShip") << "Base ship is null!";
		return;
	}
	this->size = ship->getSize();
	this->pos = ship->getPosition() - ship->getSize() * 0.5f;
	this->animator = new SpriteAnimator();
	this->addAnimation(AShipBase::framepathfmt);
}

AnimatedShip::~AnimatedShip(void) {
	delete this->animator;
}

static std::string formatted(const std::string& format, int num) {
    int size = std::snprintf(nullptr, 0, format.c_str(), num);
    if(size <= 0) {
    	return "";
    }
    std::vector<char> buffer(size + 1);
    std::snprintf(buffer.data(), buffer.size(), format.c_str(), num);
    return std::string(buffer.data());
}

void AnimatedShip::addAnimation(const std::string &pathFmt) {
	SpriteAnimation *anim = new SpriteAnimation();
	const std::string &baseDir = gObject::gGetImagesDir();
	for(int i = 1; ;i++) {
		std::string path = formatted(pathFmt, i);
		if(gFile::doesFileExist(baseDir + path)) {
			anim->loadFrame(path);
		} else {
			break;
		}
	}
	this->animator->addAnimation(anim);
	this->animator->changeAnimation(anim->getId());
}

void AnimatedShip::changeCurrentFps(int fps) {
	this->animator->changeCurrentFps(fps);
}

void AnimatedShip::update(float deltaTime) {
	this->animator->update(deltaTime);
}

void AnimatedShip::draw(void) {
	this->animator->draw(pos.x, pos.y, size.x, size.y);
}

void AnimatedShip::move(glm::vec2 stepSize) {
	this->pos += stepSize;
}

glm::vec2 AnimatedShip::getSize(void) const {
	return (this->size);
}

glm::vec2 AnimatedShip::getPosition(void) const {
	return (this->pos + this->size * 0.5f);
}
