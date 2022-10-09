/*
�錾 
	int getImagesLength(�@)
�T�v 
	�ǂݍ��񂾉摜�̐����擾����
����
	�Ȃ�
�߂�l
�@	�ǂݍ��񂾉摜�̐�
*/

#include "Magic.h"
MAGIC_BEGIN

ImagePtr img[ 5 ];
SpritePtr sprite[ 5 ];

void setup( ) {
	createCanvas( 600, 400 );
	img[ 0 ] = loadImage( "01.png" );
	img[ 1 ] = loadImage( "02.png" );
	img[ 2 ] = loadImage( "03.png" );
	img[ 3 ] = loadImage( "04.png" );
	img[ 4 ] = loadImage( "05.png" );

	int images_idx = getImagesLength( );
	for ( int i = 0; i < images_idx; i++ ) {
		sprite[ i ] = createSprite( 50 + 50 * i, getHeight( ) / 2 );
	}
	for ( int i = 0; i < images_idx; i++ ) {
		sprite[ i ]->addImage( img[ i ] );
	}
}

void draw( ) {
	drawSprites( );
}

MAGIC_END