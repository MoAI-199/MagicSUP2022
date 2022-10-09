/*
�N���X
	Sprite
�錾
	const char* getAnimationLabel( );
�T�v
	sprite�����݂̕\�����Ă���摜�̃��x�����擾����
����
	�Ȃ�
�߂�l
	���݂̕\�����Ă���摜�̃��x��
*/

#include "Magic.h"
MAGIC_BEGIN

SpritePtr sprite;
ImagePtr img1;
ImagePtr img2;

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
	if ( sprite->getAnimationLabel( ) == "e" ) {
		sprite->changeImage( "p" );
	} else {
		sprite->changeImage( "e" );
	}
}

MAGIC_END