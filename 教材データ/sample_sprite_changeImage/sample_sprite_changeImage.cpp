/*
クラス
	Sprite
宣言
	void changeImage( const char* label );
概要
	spriteが表示する画像を変える
引数
	label : 画像につけたラベル名
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

SpritePtr sprite;
ImagePtr img1;
ImagePtr img2;
bool flip = false;

void setup( ) {
	sprite = createSprite( getWidth( ) / 2, getHeight( ) / 2 );

	img1 = loadImage( "enemy.png" );
	img2 = loadImage( "player.png" );
	sprite->addImage( "e", img1 );
	sprite->addImage( "p", img2 );
}

void draw( ) {
	background( 255 );
	sprite->onMousePressed( this, &Instance::change );
	drawSprite( sprite );
}

void change( ) {
	if ( flip ) {
		sprite->changeImage( "p" );
	} else {
		sprite->changeImage( "e" );
	}
	flip = !flip;
}

MAGIC_END