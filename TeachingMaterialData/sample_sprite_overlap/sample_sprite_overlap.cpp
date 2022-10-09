/*
クラス
	Sprite
宣言
	void overlap( GroupPtr group, Instance* _inst, void( Instance::* func )( SpritePtr myself, SpritePtr group_menber ) )
概要
	スプライトとグループ内のスプライトが衝突したとき、登録した関数を呼び出す
引数
	GroupPtr group             : スプライトのグループ
	Instance* _inst              : thisと記入してください
	void( Instance::*func ) : 登録する関数
戻り値
	なし
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
GroupPtr group;

void setup( ) {
	sprite = createSprite( 0, 0 );
	group = createGroup( );
	SpritePtr sp = createSprite( 500, 300 );
	group->add( sp );
	
}

void deleted( SpritePtr myself, SpritePtr group_member ) {
	myself->remove( );
}

void draw( ) {
	background( 255 );
	sprite->setPos( getMouseX( ), getMouseY( ) );
	sprite->overlap( group, this, &Instance::deleted );
	drawSprites( );
}


MAGIC_END
