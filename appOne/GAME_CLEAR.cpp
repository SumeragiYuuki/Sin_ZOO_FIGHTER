#include"libOne.h"
#include"GAME.h"
#include"PLAYER.h"
#include"ANIMAl.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include "GAME_CLEAR.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game) :
	SCENE(game) {

}
GAME_CLEAR::~GAME_CLEAR() {

}
void GAME_CLEAR::update() {
	game()->playerBullets()->update();
	game()->enemyBullets()->update();
}
void GAME_CLEAR::draw() {
	game()->draw();
	printSize(300);
	print("Game Clear");
}
void GAME_CLEAR::nextScene() {
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::TITLE_ID);
	}
}