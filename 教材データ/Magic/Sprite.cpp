#include "../lib/Magic.h"
#include "DxLib.h"

const int DEFAULT_SIZE = 100;

Sprite::Sprite( int x, int y, CameraPtr camera ) {
	_pos.x = x;
	_pos.y = y;
	_before_pos = _pos;
	_image_size.x = DEFAULT_SIZE;
	_image_size.y = DEFAULT_SIZE;
	_velocity.x = 0.0;
	_velocity.y = 0.0;
	_func_on_mouse_pressed = NULL;
	_func_on_mouse_pressed_with_arguments = NULL;
	_func_overlap = NULL;
	_instance = NULL;
	_delete = false;
	_scale = 1.0;
	_index = 0;
	_label_list[ -1 ] = "";
	_type_num = 0;
	_camera = camera;
}

Sprite::~Sprite( ) {
}

void Sprite::update( ) {
	_pos.x += _velocity.x;
	_pos.y += _velocity.y;
	if ( _life > 0 ) {
		_life--;
		if ( _life <= 0 ) {
			_delete = true;
		}
	}
}

void Sprite::draw( ) {
	if ( _delete ) {
		return;
	}
	Global::Vec c_pos = _camera->getPos( );
	bool camera_on = _camera->isCameraOn( );
	int x = ( int )_pos.x;
	int y = ( int )_pos.y;
	if ( camera_on ) {
		x = ( int )_pos.x - c_pos.x;
		y = ( int )_pos.y - c_pos.y;
	}

	if ( _image == -1 ) {
		if ( _animation == nullptr ) {
			int box_size = ( int )( DEFAULT_SIZE * _scale );
			DrawBox(
				x - box_size / 2, y - box_size / 2,
				x + box_size / 2, y + box_size / 2,
				GetColor( 255, 0, 0 ), TRUE );
		} else {
			int handle = _animation->getHandle( );
			int image_size_x = 0;
			int image_size_y = 0;
			GetGraphSize( handle, &image_size_x, &image_size_y );
			image_size_x = ( int )( image_size_x * _scale );
			image_size_y = ( int )( image_size_y * _scale );
			DrawExtendGraph(
				x - image_size_x / 2, y - image_size_x / 2,
				x + image_size_x / 2, y + image_size_x / 2,
				handle, TRUE );
			_animation->AnimationCounter( );
		}
	} else {
		int image_size_x = ( int )( _image_size.x * _scale );
		int image_size_y = ( int )( _image_size.y * _scale );
		DrawExtendGraph(
			x - image_size_x / 2, y - image_size_y / 2,
			x + image_size_x / 2, y + image_size_y / 2,
			_image, TRUE );
	}
}

void Sprite::addImage( const ImagePtr image ) {
	_image = image->getHandle( );
	int image_size_x = DEFAULT_SIZE;
	int image_size_y = DEFAULT_SIZE;
	GetGraphSize( _image, &image_size_x, &image_size_y );
	_image_size.x = image_size_x;
	_image_size.y = image_size_y;
}

void Sprite::addImage( const char* label, const ImagePtr image ) {
	_image = image->getHandle( );
	int image_size_x = DEFAULT_SIZE;
	int image_size_y = DEFAULT_SIZE;
	GetGraphSize( _image, &image_size_x, &image_size_y );
	_image_size.x = image_size_x;
	_image_size.y = image_size_y;
	_image_list[ label ] = _image;
	_label_list[ _image ] = label;
}

void Sprite::setPos( int x, int y ) {
	_before_pos = _pos;
	_pos.x = x;
	_pos.y = y;
}

Global::Vec Sprite::getVelocity( )  const {
	return _velocity;
}

void Sprite::setVelocity( double velocityX, double velocityY ) {
	_velocity.x = velocityX;
	_velocity.y = velocityY;
}

void Sprite::onMousePressed( Instance* _inst, void( Instance::* func )( ) ) {
	_func_on_mouse_pressed = func;
	_instance = _inst;
}

void Sprite::onMousePressed( Instance* _inst, void( Instance::* func )( SpritePtr myself ) ) {
	_func_on_mouse_pressed_with_arguments = func;
	_instance = _inst;
}

void Sprite::callOnMousePressed( ) {
	if ( _func_on_mouse_pressed != NULL && _instance != NULL ) {
		( _instance->*_func_on_mouse_pressed )( );
	}
	if ( _func_on_mouse_pressed_with_arguments != NULL && _instance != NULL ) {
		( _instance->*_func_on_mouse_pressed_with_arguments )( shared_from_this( ) );
	}
}


void Sprite::setScale( double scale ) {
	_scale = scale;
}

double Sprite::getScale( ) const {
	return _scale;
}


void Sprite::remove( ) {
	_delete = true;
}

bool Sprite::isDelete( ) const {
	return _delete;
}

void Sprite::setTypeNumber( int num ) {
	_type_num = num;
}

int Sprite::getTypeNumber( ) const {
	return _type_num;
}

void Sprite::setIndex( int index ) {
	_index = index;
}

int Sprite::getIndex( ) const {
	return _index;
}

void Sprite::setLife( int life ) {
	_life = life * 30;
}

void Sprite::changeImage( const char* label ) {
	_image = _image_list[ label ];
	int image_size_x = DEFAULT_SIZE;
	int image_size_y = DEFAULT_SIZE;
	GetGraphSize( _image, &image_size_x, &image_size_y );
	_image_size.x = image_size_x;
	_image_size.y = image_size_y;
}


void Sprite::addAnimation( const char* label, AnimationPtr animation ) {
	_animation = animation;
	_animation_list[ label ] = animation;
}

const char* Sprite::getAnimationLabel( ) const {
	return _label_list.at( _image );
}

void Sprite::changeAnimation( const char* label ) {
	_animation = _animation_list[ label ];
}

void Sprite::overlap( GroupPtr group, Instance* _inst, void( Instance::* func )( SpritePtr myself, SpritePtr group_menber ) ) {
	if ( _func_overlap == NULL || _instance == NULL ) {
		_instance = _inst;
		_func_overlap = func;
	}
	int sprite_size = group->getSize( );
	for ( int i = 0; i < sprite_size; i++ ) {
		SpritePtr sp = group->getSprite( i );
		Global::Vec gr_pos = sp->getPos( );
		Global::Vec gr_size = sp->getImageSize( );

		bool up_collide = _pos.y + _image_size.y >= gr_pos.y && _pos.y + _image_size.y <= gr_pos.y + gr_size.y;
		bool down_collide = _pos.y <= gr_pos.y + gr_size.y && _pos.y >= gr_pos.y;
		bool left_collide = _pos.x + _image_size.x >= gr_pos.x && _pos.x + _image_size.x <= gr_pos.x + gr_size.x;
		bool right_collide = _pos.x <= gr_pos.x + gr_size.x && _pos.x >= gr_pos.x;

		bool overlap = ( up_collide || down_collide ) && ( left_collide || right_collide );

		if ( overlap ) {
			if ( _func_overlap != NULL && _instance != NULL ) {
				( _instance->*_func_overlap )( shared_from_this( ), sp );
			}
		}
	}
}

Global::Vec Sprite::getPos( ) const {
	return _pos;
}

Global::Vec Sprite::getBeforePos( ) const {
	return _before_pos;
}

Global::Vec Sprite::getImageSize( ) const {
	return _image_size;
}
