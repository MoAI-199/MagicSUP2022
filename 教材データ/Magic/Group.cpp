#include "../lib/Magic.h"

Group::Group( ) {

}

Group::~Group( ) {

}

void Group::add( SpritePtr sprite ) {
	_sprite_list.push_back( sprite );
}

int Group::getSize( ) const {
	return ( int )_sprite_list.size( );
}

SpritePtr Group::getSprite( int idx ) const {
	return _sprite_list.at( idx );
}

void Group::remove( ) {
	int sprite_size = _sprite_list.size( );

	for ( int i = 0; i < sprite_size; i++ ) {
		std::vector<SpritePtr>::iterator number = _sprite_list.begin( );
		_sprite_list.at( 0 )->remove( );
		_sprite_list.erase( number );
	}
}

void Group::collide( SpritePtr sprite ) {
	Global::Vec sprite_pos = sprite->getPos( );
	Global::Vec before_sprite_pos = sprite->getBeforePos( );
	Global::Vec difference_vec;
	difference_vec.x = sprite_pos.x - before_sprite_pos.x;
	difference_vec.y = sprite_pos.y - before_sprite_pos.y;
	Global::Vec sp_size = sprite->getImageSize( );

	Global::Vec difference;
	difference.x = abs( sprite_pos.x - before_sprite_pos.x );
	difference.y = abs( sprite_pos.y - before_sprite_pos.y );

	int sprite_size = _sprite_list.size( );
	for ( int i = 0; i < sprite_size; i++ ) {
		Global::Vec group_sprite_pos = _sprite_list[ i ]->getPos( );
		Global::Vec group_sprite_size = _sprite_list[ i ]->getImageSize( );
		int top_sprite = sprite_pos.y;
		int left_sprite = sprite_pos.x;
		int top_group_sprite = group_sprite_pos.y;
		int left_group_sprite = group_sprite_pos.x;
		int before_top_sprite = before_sprite_pos.y;
		int before_left_sprite = before_sprite_pos.x;
		int bottom_sprite = top_sprite + sp_size.y;
		int before_bottom_sprite = before_top_sprite + sp_size.y;
		int bottom_group_sprite = top_group_sprite + group_sprite_size.y;
		int before_bottom_group_sprite = top_group_sprite + group_sprite_size.y;
		int right_sprite = left_sprite + sp_size.x;
		int right_group_sprite = left_group_sprite + group_sprite_size.x;
		int before_right_sprite = before_left_sprite + sp_size.x;

		bool top_collide = bottom_sprite >= top_group_sprite && bottom_sprite <= bottom_group_sprite;
		bool before_top_collide = before_bottom_sprite >= top_group_sprite && before_bottom_sprite <= before_bottom_group_sprite;
		bool bottom_collide = top_sprite <= before_bottom_group_sprite && top_sprite >= top_group_sprite;
		bool before_bottom_collide = before_top_sprite <= before_bottom_group_sprite && before_top_sprite >= top_group_sprite;
		bool left_collide = right_sprite >= left_group_sprite && right_sprite <= right_group_sprite;
		bool before_left_collide = before_right_sprite >= left_group_sprite && before_right_sprite <= right_group_sprite;
		bool right_collide = left_sprite <= right_group_sprite && left_sprite >= left_group_sprite;
		bool before_right_collide = before_left_sprite <= right_group_sprite && before_left_sprite >= left_group_sprite;

		bool collide = ( top_collide || bottom_collide ) && ( left_collide || right_collide );

		if ( collide ) {
				if ( sprite_pos.y - before_sprite_pos.y > 0 ) {
					top_group_sprite += difference.y;
				}
				else if ( sprite_pos.y - before_sprite_pos.y < 0 ) {
					top_group_sprite -= difference.y;
				}
				else if ( sprite_pos.x - before_sprite_pos.x > 0 ) {
					left_group_sprite += difference.x;
				}
				else if ( sprite_pos.x - before_sprite_pos.x < 0 ) {
					left_group_sprite -= difference.x;
				}

			_sprite_list[ i ]->setPos( left_group_sprite, top_group_sprite );
		}
	}
}

void Group::remove( int idx ) {
	std::vector<SpritePtr>::iterator number = _sprite_list.begin( );
	_sprite_list.erase( number + idx );
}
