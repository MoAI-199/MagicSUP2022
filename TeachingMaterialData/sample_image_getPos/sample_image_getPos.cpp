/*
クラス
	Image
宣言
	Vec image::getPos( );
概要
	Imageの座標を取得します。
引数
	なし。
戻り値
	Imageの座標。
*/
#include "Magic.h"
MAGIC_BEGIN

ImagePtr img;
void setup( ) {
	img = loadImage( "logo.png" );
	image( img, 40, 20 );
}

void draw( ) {
	int pos_x = ( int )img->getPos( ).x;
	int pos_y = ( int )img->getPos( ).y;
	fill( 255, 0, 0 );
	rect( pos_x, pos_y, 50, 50);
}

MAGIC_END
