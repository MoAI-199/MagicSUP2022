/*
宣言
	void image( int img, int x, int y)
	void image( int img, int x, int y, int width, int height )
概要
	画像を画面に表示します
引数
	img : 表示する画像
	x : 表示位置のx座標
	y : 表示位置のy座標
	width : 表示時の画像の幅
	height : 表示時の画像の高さ
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

ImagePtr img;

void setup( ) {
	img = loadImage( "logo.png" );
	image( img, 0, 0 );
	image( img, 100, 100, 200, 200 );
}

void draw( ) {

}

MAGIC_END