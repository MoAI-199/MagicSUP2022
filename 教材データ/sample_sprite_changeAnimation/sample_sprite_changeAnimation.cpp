/*
クラス
	Sprite
宣言
	void changeAnimation( const char* label );
概要
	spriteが表示するアニメーションを変える
引数
	label : アニメーションにつけたラベル名
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

SpritePtr sprite;
AnimationPtr anm1;
AnimationPtr anm2;
int count = 0;
bool flip = false;

void setup( ) {
	sprite = createSprite( getWidth( ) / 2, getHeight( ) / 2 );
	
	anm1 = loadAnimation( 12,
						  "ghost_left00.png",
						  "ghost_left01.png",
						  "ghost_left02.png",
						  "ghost_left03.png",
						  "ghost_left04.png",
						  "ghost_left05.png",
						  "ghost_left06.png",
						  "ghost_left07.png",
						  "ghost_left08.png",
						  "ghost_left09.png",
						  "ghost_left10.png",
						  "ghost_left11.png" );
	anm2 = loadAnimation( 12,
						  "ghost_right00.png",
						  "ghost_right01.png",
						  "ghost_right02.png",
						  "ghost_right03.png",
						  "ghost_right04.png",
						  "ghost_right05.png",
						  "ghost_right06.png",
						  "ghost_right07.png",
						  "ghost_right08.png",
						  "ghost_right09.png",
						  "ghost_right10.png",
						  "ghost_right11.png" );
	sprite->addAnimation( "l", anm1 );
	sprite->addAnimation( "r", anm2 );
}

void draw( ) {
	background( 255 );
	count++;
	if ( count % 60 == 0 ) {
		change( );
	}
	drawSprites( );
}

void change( ) {
	if ( flip ) {
		sprite->changeAnimation( "r" );
	} else {
		sprite->changeAnimation( "l" );
	}
	flip = !flip;
}

MAGIC_END