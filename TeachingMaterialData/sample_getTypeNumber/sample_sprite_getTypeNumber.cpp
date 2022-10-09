/*
* クラス　Sprite
* 宣言 int getTypeNumber( );
* 概要 Spriteのタイプの数字を設定する
* 引数  なし
* 戻り値 タイプの数字
*/

#include "Magic.h"
MAGIC_BEGIN

SpritePtr sprite;
SpritePtr sprite_2;

void setup( ) {
	createCanvas( 600, 400 );
	sprite = createSprite( 100, 100 );
	sprite->setTypeNumber( 1 );

	sprite_2 = createSprite( 100, 300 );
	sprite_2->setTypeNumber( 2 );
}

void draw( ) {
	background( 255 );
	sprite->setPos( sprite->getTypeNumber( ) * 100, ( int )sprite->getPos( ).y );
	sprite_2->setPos( sprite_2->getTypeNumber( ) * 100, ( int )sprite_2->getPos( ).y );
	drawSprites( );
}

MAGIC_END