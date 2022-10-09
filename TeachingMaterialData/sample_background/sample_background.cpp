/*
宣言 
	 void background( int r, int g, int r)
	 void background( int r, int g, int r, int alpha)
	 void background( int gray )
	 void background( int gray , int alpha )
	 void background( ImagePtr img )
	 void background( ImagePtr img , int alpha )
概要 
	背景の色を変更できる
	背景のalpha値を指定する事で透明度を変更できる
引数
	r : 赤の成分 (0 ～ 255)
	g : 緑の成分 (0 ～ 255)
	b : 青の成分 (0 ～ 255)
	alpha : 透明度 ( 0 ～ 255 )
	gray : グレースケール (0 ～ 255)　　　
	img：背景画像
戻り値
	なし

*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	//キャンバスのサイズを設定
	createCanvas( 600, 400 );
	//赤色の背景を設定
	background( 255, 0, 0 );
	//黒の半透明の背景を設定
	background( 0, 128 );
	ImagePtr img = loadImage( "photo05.png" );
	background( img );
}

void draw( ) {

}

MAGIC_END