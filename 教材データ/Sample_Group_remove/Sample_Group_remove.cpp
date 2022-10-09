/*
クラス　Group
宣言 void remove( int idx　)
		void remove( )
概要 Groupに登録してあるスプライトを消す
引数 idx : 登録したスプライトのインデックス
戻り値　なし
*/

#include "Magic.h"
MAGIC_BEGIN

GroupPtr group;

void setup( ) {
	createCanvas( 600, 400 );
	background( 255 );
	group = createGroup( );
}

void draw( ) {
	background( 0 );
	int group_size = group->getSize( );
	int sprite_count = 0;
	while ( group_size > 0 ) {
		group_size = group->getSize( );
		SpritePtr spr = group->getSprite( sprite_count );
		int sprite_pos_y = ( int )spr->getPos( ).y;
		int screen_height = getHeight( );
		if ( sprite_pos_y > screen_height ) {
			group->remove( sprite_count );
			group_size = group->getSize( );
		} else {
			sprite_count++;
		}
		if ( group_size > 5 ) {
			group->remove( );
			group_size = group->getSize( );
		}
		if ( sprite_count == group_size ) {
			break;
		}
	}
	drawSprites( );
}

void mouseClicked( ) {
	int mouse_x = getMouseX( );
	int mouse_y = getMouseY( );
	SpritePtr sprite = createSprite( mouse_x, mouse_y );
	double sprite_velocity_x = sprite->getVelocity( ).x;
	sprite->setVelocity( sprite_velocity_x, 2 );
	group->add( sprite );
}
MAGIC_END