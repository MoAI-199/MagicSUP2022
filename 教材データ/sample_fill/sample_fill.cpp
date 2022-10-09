/*
宣言
	void fill( int r,int g, int b ,int alpha )
	void fill( int r,int g, int b )
	void fill( int grey ,int alpha )
	void fill( int grey )
概要
	色を変更できる
	alpha値を指定する事で透明度を変更できる
引数
	r : 赤の成分 (0 ～ 255)
	g : 緑の成分 (0 ～ 255)
	b : 青の成分 (0 ～ 255)
	alpha : 透明度 ( 0 ～ 255 )
	gray : グレースケール (0 ～ 255)
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
	//赤色の円を透明度20で描画
	fill( 255, 0, 0, 20 );
	ellipse( 100, 100, 100 );
	//255を上回る数値の場合255に抑えられる
	fill( 500, 500, 0 );
	ellipse( 100, 200, 100 );
}

void draw( ) {
	//青色の円を描画
	fill( 0, 0, 255 );
	ellipse( 200, 100, 100 );
	//グレースケールを設定して円を描画
	fill( 80 );
	ellipse( 300, 100, 100 );

}

MAGIC_END

