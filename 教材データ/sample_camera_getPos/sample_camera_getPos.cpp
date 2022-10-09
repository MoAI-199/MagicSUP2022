/*
クラス
	Camera
宣言
	Global::Vec getPos( )
概要
	cameraのposを取得します。
引数
	なし
戻り値
	cameraのpos
*/

#include "Magic.h"
MAGIC_BEGIN

void setup( ) {
	createCanvas( 600, 400 );
	background( 120 );
}

void draw( ) {
	background( 120 );
	CameraPtr camera = getCamera( );
	Vec add;
	add.x = 0;
	add.y = 1;
	Vec c_pos = camera->getPos( );
	c_pos.x += add.x;
	c_pos.y += add.y;
	camera->setPos( c_pos );
	//キャンバスに円を表示
	fill( 0, 255, 0 );
	ellipse( 100, 100, 100 );
	//カメラが表示している座標に円を表示
	fill( 255, 0, 0 );
	ellipse( c_pos.x + 100 , c_pos.y + 100, 50 );
}

MAGIC_END