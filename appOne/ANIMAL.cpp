#include "ANIMAL.h"
#include"CONTAINER.h"
#include"GAME.h"
#include "PLAYER_BULLETS.h"
ANIMAL::ANIMAL(class GAME* game) :
	GAME_OBJECT(game) {

}
void ANIMAL::create() {
	Animal = game()->container()->animal();
}
void ANIMAL::init() {
	Animal.pos = game()->container()->animal().pos;
	Animal.hp = game()->container()->animal().hp;
}
void ANIMAL::update() {
	move();
	collision();
}
void ANIMAL::move() {
	if (Animal.centerPos.y < Animal.targetPosY) {
		Animal.centerPos.y += Animal.fallSpeed * delta;
		Animal.pos.y = Animal.centerPos.y;
	}
}

void ANIMAL::collision() {
	if (Animal.invincibleRestTime > 0) {
		Animal.invincibleRestTime -= delta;
	}
	else {
		Animal.color = Animal.normalColor;

		PLAYER_BULLETS* bullets = game()->playerBullets();
		float distance = Animal.bcRadius + bullets->bcRadius();
		float sqDistance = distance * distance;
		for (int i = bullets->curNum() - 1; i >= 0; i--) {
			VECTOR2 vec = Animal.pos - bullets->pos(i);
			if (sqLength(vec) < sqDistance) {
				Animal.hp--;
				Animal.invincibleRestTime = Animal.invincibleTime;
				Animal.color = Animal.collisionColor;
				bullets->kill(i);
				i = 0;
			}
		}
	}
}
void ANIMAL::draw() {
	imageColor(Animal.color);
	rectMode(CENTER);
	image(Animal.img, Animal.pos.x, Animal.pos.y, Animal.angle,1.5);
	game()->hpGauge()->draw(Animal.pos, Animal.HpGaugeOfst, Animal.hp);
}