/*
宣言
	CameraPtr getCamera( )
概要
	cameraを取得します。
引数
	なし
戻り値
	cameraのポインタ
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
	ellipse( 100, 100, 100 );
}

MAGIC_END