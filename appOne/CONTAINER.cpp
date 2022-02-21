#include "CONTAINER.h"
void CONTAINER::load() {
	setData();
	loadGraphic();
}
void CONTAINER::setData() {
	//text
	Data.title.textSize   = 200;
	Data.title.pos.x      = 180;
	Data.title.pos.y      = 700;
	//title
	Data.title.textColor  = COLOR(0, 255, 0);
	Data.title.backColor  = COLOR(0, 20, 0);
	strcpy_s(Data.title.str,"動物虐待ダメ絶対");

	//player
	Data.player.angle     = 0;
	Data.player.pos.x     = 960;
	Data.player.pos.y     = 970;
	Data.player.limmitW   = 100;
	Data.player.advSpeed  = 300;
	Data.player.launchVec = VECTOR2(0, -1);
	Data.player.triggerErapsedTime = 0;
	Data.player.triggerInterval = 0.1f;
	Data.player.ofstLaunchDist = 100;
	Data.player.bcRadius = 40;
	Data.player.invincibleRestTime = 0;
	Data.player.invincibleTime = 0.05f;
	Data.player.hp = 5;
	Data.player.HpGaugeOfst = VECTOR2(0, -120);
	Data.player.collisionColor = COLOR(255, 0, 0);
	Data.player.normalColor = COLOR(255, 255, 255);

	//enemy
	Data.enemy.totalNum   = 8;
	Data.enemy.curNum = Data.enemy.totalNum;
	Data.enemy.majRadius  = 700;
	Data.enemy.minRadius  = 100;
	Data.enemy.centerPos  = VECTOR2(960, -300);
	Data.enemy.fallSpeed  = 60;
	Data.enemy.targetPosY = 300;
	Data.enemy.refTheta   = 0;
	Data.enemy.thetaSpeed = 0.6f;
	Data.enemy.triggerInterval = 1.0f;
	Data.enemy.ofstLaunchDist = 100;
	Data.enemy.bcRadius = 40;
	Data.enemy.invincibleTime = 0.05f;
	Data.enemy.initHp = 5;
	Data.enemy.HpGaugeOfst = VECTOR2(0, -120);
	Data.enemy.collisionColor = COLOR(255, 0, 0);
	Data.enemy.normalColor = COLOR(255, 255, 255);

	//animal
	Data.animal.angle = 0;
	Data.animal.pos.x = 960;
	Data.animal.pos.y = Data.enemy.centerPos.y;
	Data.animal.limmitW = 100;
	Data.animal.centerPos = Data.enemy.centerPos;
	Data.animal.fallSpeed = Data.enemy.fallSpeed;
	Data.animal.targetPosY = Data.enemy.targetPosY;
	Data.animal.advSpeed = 300;
	Data.animal.bcRadius = 40;
	Data.animal.invincibleRestTime = 0;
	Data.animal.invincibleTime = 0.05f;
	Data.animal.hp = 3;
	Data.animal.HpGaugeOfst = VECTOR2(0, -120);
	Data.animal.collisionColor = COLOR(255, 0, 0);
	Data.animal.normalColor = COLOR(255, 255, 255);

	//playerBullets
	Data.playerBullet.totalNum = 10;
	Data.playerBullet.curNum = 0;
	Data.playerBullet.advSpeed = 600;
	Data.playerBullet.angSpeed = 5;
	Data.playerBullet.bcRadius = 20;

	//enemyBullets
	Data.enemyBullet.totalNum = 5;
	Data.enemyBullet.curNum = 0;
	Data.enemyBullet.advSpeed = 600;
	Data.enemyBullet.angSpeed = 0;
	Data.enemyBullet.bcRadius = 20;

	//hpGauge
	Data.hpGauge.coWidth = 30;
	Data.hpGauge.hi = 15;
	Data.hpGauge.safeColor = COLOR(0, 255, 0);
	Data.hpGauge.dangerColor = COLOR(255, 0, 0);
	
}
void CONTAINER::loadGraphic() {
	Data.player.img = loadImage("assets\\player.png");
	Data.enemy.img  = loadImage("assets\\gomibako.png");
	Data.animal.img = loadImage("assets\\risu.png");
	Data.playerBullet.img = loadImage("assets\\mizu.png");
	Data.enemyBullet.img = loadImage("assets\\sutoresu.png");
}