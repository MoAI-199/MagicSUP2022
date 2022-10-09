/*
クラス
	Sprite
宣言
	double setVelocity( double velocityX, double velocityX );
概要
	spriteの進行方向への移動量を設定する
引数
	double velocityX ： X方向への移動量
	double velocityY ： Y方向への移動量
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
void setup( ) {
	sprite = createSprite( 0, 200 );
	sprite->setVelocity( 0.5, 0.5 );
}

void draw( ) {
	background( 255 );
	drawSprite( sprite );
}

MAGIC_END
