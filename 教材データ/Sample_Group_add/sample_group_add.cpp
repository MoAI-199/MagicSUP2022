/*
クラス　Group
宣言 void add（　SpritePtr sprite ）
概要 Groupに新しくSprietを追加する。
引数  sprite:Groupに登録するSprite
戻り値 なし
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
	for ( int i = 0; i < group_size; i++ ) {
		SpritePtr spr = group->getSprite( i );
		int sprite_pos_y = ( int )spr->getPos( ).y;
		int screen_height = getHeight( );
		if ( sprite_pos_y > screen_height ) {
			spr->setPos( ( int )spr->getPos( ).x, 0 );
		}
	}
	drawSprites( );
}

void mouseClicked( ) {
	int mouse_x = getMouseX( );
	int mouse_y = getMouseY( );
	SpritePtr sprite = createSprite( mouse_x, mouse_y );
	sprite->setVelocity( sprite->getVelocity( ).x, 2 );
	group->add( sprite );
}
MAGIC_END