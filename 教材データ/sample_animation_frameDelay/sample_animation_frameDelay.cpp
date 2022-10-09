/*
クラス
	Animation
宣言
	void frameDelay( int delay );
概要
	アニメーションの遅延
引数
	delay : 待機フレーム数
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

AnimationPtr animation;
SpritePtr sprite;
void setup( ) {
	sprite = createSprite( 100, 100 );
	animation = loadAnimation(
		9,
		"01.png",
		"02.png",
		"03.png",
		"04.png",
		"05.png",
		"06.png",
		"07.png",
		"08.png",
		"09.png" );
	sprite->addAnimation( "walk", animation );
	animation->frameDelay( 60 );
}

void draw( ) {
	background( 255 );
	drawSprite( sprite );
}

MAGIC_END