/*
クラス
	Camera
宣言
	void off ( )
概要
	カメラを停止する。
引数
	なし
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN

int x;
int y;
Vec move;

void setup( ) {
	createCanvas( 600, 400 );
	background( 120 );
	move.x = 1;
	move.y = 1;
}

void draw( ) {
	background( 120 );
	CameraPtr camera = getCamera( );
	Vec c_pos = camera->getPos( );
	if ( keyDown( "LEFT" ) ) {
		c_pos.x -= move.x;
	} else if ( keyDown( "RIGHT" ) ) {
		c_pos.x += move.x;
	} else if ( keyDown( "UP" ) ) {
		c_pos.y -= move.y;
	} else if ( keyDown( "DOWN" ) ) {
		c_pos.y += move.y;
	}
	camera->on( );
	camera->setPos( c_pos );
	ellipse( 100, 300, 100 );
	camera->off( );
	ellipse( 300, 200, 10 );
}

MAGIC_END