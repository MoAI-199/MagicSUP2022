/*
宣言
	void imageMode( int mode )
概要
	画像の表示位置の指定方法を変更します。デフォルトはCORNERで、これは左上角の座標で指定するモードです。CORNERSは左上と右下の角の座標を指定するモード、CENTERは画像の中心の座標を指定するモードです。
引数
	mode : CENTER、CORNERS、CORNERのいずれか
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	ImagePtr img = loadImage( "logo.png" );

	imageMode( CORNERS );
	image( img, getWidth( ) / 2, getHeight( ) / 2, getWidth( ), getHeight( ) );

	imageMode( CENTER );
	image( img, getWidth( ) / 2, getHeight( ) / 2, 100, 100 );

	imageMode( CORNER );
	image( img, getWidth( ) / 2, getHeight( ) / 2, 100, 100 );
}

void draw( ) {

}

MAGIC_END