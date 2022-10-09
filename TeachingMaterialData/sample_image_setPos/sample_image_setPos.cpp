/*
クラス
	Image
宣言
	void setPos( int x, int y );
概要
	Imageの座標を設定します。
引数
	int x：ImageのX座標。
	int y：ImageのY座標。
戻り値
	なし。
*/
#include "Magic.h"
MAGIC_BEGIN

ImagePtr img;
void setup( ) {
	img = loadImage( "logo.png" );
	img->setPos( 200, 200 );
}

void draw( ) {
	int pos_x = ( int )img->getPos( ).x;
	int pos_y = ( int )img->getPos( ).y;
	image( img, pos_x, pos_y );

}

MAGIC_END
