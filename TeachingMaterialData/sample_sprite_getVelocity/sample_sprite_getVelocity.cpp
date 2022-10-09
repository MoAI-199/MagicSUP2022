/*
クラス
	Sprite
宣言
	Vec Sprite::getVelocity( );
概要
	spriteの進行方向への移動量を取得する
引数
	なし
戻り値
	spriteの進行方向への移動量
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
double _velocity_x = 0;
double _velocity_y = 0;
void setup( ) {
	sprite = createSprite( 0, 200 );
	sprite->setVelocity( 0.5, 0.5 );
	_velocity_x = sprite->getVelocity( ).x;
	_velocity_y = sprite->getVelocity( ).y;
}

void draw( ) {
	background( 255 );
	drawSprite( sprite );
	if ( isMousePressed( ) ) {
		sprite->setVelocity( -_velocity_x, -_velocity_y );
	}
}

MAGIC_END
