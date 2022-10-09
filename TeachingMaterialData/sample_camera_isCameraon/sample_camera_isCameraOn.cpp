/*
クラス
	Camera
宣言
	bool isCameraOn ( )
概要
	カメラを起動しているか。
引数
	なし
戻り値
	true : 起動している
　　	false: 起動していない
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
	if ( camera->isCameraOn( ) ) {
		ellipse( 100, 300, 100 );
	}
	camera->off( );
	if ( !camera->isCameraOn( ) ) {
		ellipse( 300, 200, 50 );
	}
}

MAGIC_END