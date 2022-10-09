/*
宣言 
	int getImagesLength(　)
概要 
	読み込んだ画像の数を取得する
引数
	なし
戻り値
　	読み込んだ画像の数
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