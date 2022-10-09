/*
クラス
	Image
宣言
	void getPixel( int index );
概要
	indexで指定した、画像のピクセルの色を取得します。
引数
	index：ピクセルの要素番号
戻り値
	色の値（0～255）
*/
#include "Magic.h"
MAGIC_BEGIN

ImagePtr img;
void setup( ) {
	img = loadImage( "test_pixel.png" );
	image( img, 20, 20 );
}

void draw( ) {
	img->loadPixels( );

	for ( int i = 0; i < img->getHeight( ); i++ ) {
		for ( int j = 0; j < img->getWidth( ); j++ ) {
			int index = ( j + i * img->getWidth( ) ) * 4;
			if ( img->getPixel( index ) == 255 ) {
				img->setPixel( index, 0 );
			}
		}
	}

	img->updatePixels( );
}

MAGIC_END
