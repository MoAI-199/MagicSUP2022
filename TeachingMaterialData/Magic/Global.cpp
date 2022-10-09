#include "DxLib.h"
#include "../lib/Magic.h"
#include "mathematics.h"
#include <string>
#include <stdarg.h>
#include <array>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern Global* _instance;
Matrix _mat_transform;

Global::Global( ) {
	_instance = this;
	_camera = CameraPtr( new Camera( ) );
}

Global::~Global( ) {

}

void Global::createCanvas( int w, int h ) {
	_width = w;
	_height = h;
	SetWindowSize( _width, _height );
	int sx = GetSystemMetrics( SM_CXSCREEN );
	int sy = GetSystemMetrics( SM_CYSCREEN );
	int window_width;
	int window_height;
	GetWindowSize( &window_width, &window_height );
	SetWindowPosition( ( sx - window_width ) / 2, ( sy - window_height ) / 2 );
	background( 255 );
}

void Global::background( int grey, int alpha ) {
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, alpha );
	DrawBox( 0, 0, _width, _height, GetColor( grey, grey, grey ), TRUE );
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
}

void Global::background( int r, int g, int b, int alpha ) {
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, alpha );
	DrawBox( 0, 0, _width, _height, GetColor( r, g, b ), TRUE );
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
}

void Global::background( ImagePtr img, int alpha ) {
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, alpha );
	DrawExtendGraph( 0, 0, _width, _height, img->getHandle( ), TRUE );
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
}

void Global::ellipse( int x, int y, int r ) {
	Vector2 pos = _mat_transform.multiply( Vector2( ) );
	Vec c_pos = _camera->getPos( );
	bool camera_on = _camera->isCameraOn( );
	int ox = 0;
	int oy = 0;
	if ( camera_on ) {
		ox = ( int )pos.x - c_pos.x;
		oy = ( int )pos.y - c_pos.y;
	}
	int r_x = returnRotatePosX( x, y );
	int r_y = returnRotatePosY( x, y );
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, _fill_alpha );
	if ( _fill_enabled ) {
		DrawCircle( ox + r_x, oy + r_y, r / 2, _fill_color, TRUE );
	}
	if ( _stroke_enabled ) {
		DrawCircle( ox + r_x, oy + r_y, r / 2, _stroke_color, FALSE, _stroke_weight );
	}
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
}

void Global::noStroke( ) {
	_stroke_enabled = false;
}

void Global::stroke( int r, int g, int b, int alpha ) {
	_stroke_alpha = alpha;
	_stroke_enabled = true;
	_stroke_color = GetColor( r, g, b );
}

void Global::stroke( int r, int g, int b ) {
	_stroke_enabled = true;
	_stroke_color = GetColor( r, g, b );
}

void Global::strokeWeight( int weight ) {
	_stroke_weight = weight;
}

void Global::noFill( ) {
	_fill_enabled = false;
}

void Global::fill( int r, int g, int b, int alpha ) {
	_fill_alpha = alpha;
	_fill_enabled = true;
	_fill_red = r;
	_fill_green = g;
	_fill_blue = b;
	if ( r > 255 ) {
		r = 255;
	}
	if ( g > 255 ) {
		g = 255;
	}
	if ( b > 255 ) {
		b = 255;
	}
	_fill_color = GetColor( r, g, b );
}

void Global::fill( int gray, int alpha ) {
	_fill_alpha = alpha;
	_fill_enabled = true;
	_fill_color = GetColor( gray, gray, gray );
}

ImagePtr Global::loadImage( std::string filename ) {
	std::string resource_pass = "resource/";
	int img = LoadGraph( ( resource_pass + filename ).c_str( ) );

	ImagePtr image = ImagePtr( new Image( img, _width, _height ) );
	_images.push_back( image );
	return image;
}

void Global::image( ImagePtr img, int x, int y ) {
	if ( _image_mode == CENTER ) {
		int w;
		int h;
		GetGraphSize( img->getHandle( ), &w, &h );
		x -= w / 2;
		y -= h / 2;
	}

	Vector2 pos = _mat_transform.multiply( Vector2( ) );
	Vec c_pos = _camera->getPos( );
	bool camera_on = _camera->isCameraOn( );
	int ox = 0;
	int oy = 0;
	if ( camera_on ) {
		ox = ( int )pos.x - c_pos.x;
		oy = ( int )pos.y - c_pos.y;
	}

	DrawGraph( ox + x, oy + y, img->getHandle( ), TRUE );

	img->setPos( ox + x, oy + y );
}

void Global::image( ImagePtr img, int x, int y, int width, int height ) {
	Vector2 pos = _mat_transform.multiply( Vector2( ) );
	Vec c_pos = _camera->getPos( );
	bool camera_on = _camera->isCameraOn( );
	int ox = 0;
	int oy = 0;
	if ( camera_on ) {
		ox = ( int )pos.x - c_pos.x;
		oy = ( int )pos.y - c_pos.y;
	}

	int x1 = ox;
	int y1 = oy;
	int x2 = ox;
	int y2 = oy;
	switch ( _image_mode ) {
	case CORNER:
		x1 += x;
		y1 += y;
		x2 += x + width;
		y2 += y + height;
		break;
	case CORNERS:
		x1 += x;
		y1 += y;
		x2 += width;
		y2 += height;
		break;
	case CENTER:
		x1 += x - width / 2;
		y1 += y - height / 2;
		x2 += x + width / 2;
		y2 += y + height / 2;
		break;
	}

	DrawExtendGraph( x1, y1, x2, y2, img->getHandle( ), TRUE );

	img->setPos( x1, y1 );
}

void Global::imageMode( int mode ) {
	_image_mode = mode;
}

void Global::text( const char* str, int x, int y ) {
	int width = GetDrawStringWidth( str, ( int )strlen( str ) );
	switch ( _text_align ) {
	case LEFT:
		break;
	case CENTER:
		x -= width / 2;
		break;
	case RIGHT:
		x -= width;
		break;
	}

	Vector2 pos = _mat_transform.multiply( Vector2( ) );
	int ox = ( int )pos.x;
	int oy = ( int )pos.y;
	DrawString( ox + x, oy + y, str, _fill_color, _now_text_style );
}

void Global::textSize( int size ) {
	SetFontSize( size );
}

void Global::textAlign( int align ) {
	_text_align = align;
}

void Global::textStyle( const char* style_name ) {
	std::string str = style_name;
	if ( str == "NORMAL" ) {
		_now_text_style = _normal_text_style;
	}
	if ( str == "BOLD" ) {
		_now_text_style = _bold_text_style;
	}
	if ( str == "ITALIC" ) {
		_now_text_style = _italic_text_style;
	}
	if ( str == "BOLD_ITALIC" ) {
		_now_text_style = _bold_italic_text_style;
	}
}

bool Global::keyDown( const char* key_str ) {
	int code = 0;
	std::string str = key_str;
	if ( str == "LEFT" ) {
		code = KEY_INPUT_LEFT;
	}
	if ( str == "UP" ) {
		code = KEY_INPUT_UP;
	}
	if ( str == "RIGHT" ) {
		code = KEY_INPUT_RIGHT;
	}
	if ( str == "DOWN" ) {
		code = KEY_INPUT_DOWN;
	}
	if ( code == 0 ) {
		return false;
	}
	return CheckHitKey( code ) == 1;
}

double Global::random( int high ) {
	const int val = 2000000000;
	double num = GetRand( val - 1 );
	return num / val * high;
}

double Global::random( int low, int high ) {
	return low + random( high - low );
}

void Global::rect( int x, int y, int w, int h ) {
	
	int ox = 0;//原点
	int oy = 0;//原点
	int width = 0;
	int height = 0;
	
	//左上ベース
	if ( _rect_mode == CORNER ) {
		ox = x;
		oy = y;
		width = w;
		height = h;
	}
	//中心ベース
	if ( _rect_mode == CENTER ) {
		ox = x - w / 2;
		oy = y - h / 2;
		width = w;
		height = h;
	}
	//中心ベースでサイズは半径
	if ( _rect_mode == RADIUS ) {
		ox = x - w / 2;
		oy = y - h / 2;
		width = w * 2;
		height = h * 2;
	}
	//translaterに合わせた調整
	Vector2 translate_pos = _mat_transform.multiply( Vector2( ) );
	ox += translate_pos.x;
	oy += translate_pos.y;

	//カメラの調整
	Vec c_pos = _camera->getPos( );
	bool camera_on = _camera->isCameraOn( );
	if ( camera_on ) {
		ox -= c_pos.x;
		oy -= c_pos.y;
	}
	
	int handle = 0;
	SetDrawBlendMode( DX_BLENDMODE_ALPHA, _fill_alpha );

	if ( _rotate_enabled ) {
		handle = MakeScreen( width, height, FALSE );
		FillGraph( handle, 0, 0, 0, 0 );
		SetDrawScreen( handle );
		DrawLineBox(
			0,
			0,
			ox + width,
			oy + height,
			_stroke_color );
		SetDrawScreen( DX_SCREEN_BACK );
		int rx = returnRotatePosX( ox, oy );//rotateでの回転した座標
		int ry = returnRotatePosY( ox, oy );//rotateでの回転した座標
		DrawRotaGraph( rx + width / 2, ry + height / 2, 1.0, _angle, handle, FALSE );
	} else {
		if ( _fill_enabled && !_stroke_enabled ) {
			DrawBox( ox,
					 oy,
					 ox + width,
					 oy + height,
					_fill_color,
					TRUE);

		} else if( !_fill_enabled && _stroke_enabled ) {//枠あり、塗りつぶし無し
			DrawLineBox( 
					 ox,
					 oy,
					 ox + width,
					 oy + height,
					 _stroke_color );

		} else if ( _fill_enabled && _stroke_enabled ) {//枠あり、塗りつぶしあり
			DrawBox( ox,
					 oy,
					 ox + width,
					 oy + height,
					 _fill_color,
					 TRUE );
		} 
	}

	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
	DeleteGraph( handle );
}

void Global::line( int x1, int y1, int x2, int y2 ) {
	Vector2 pos = _mat_transform.multiply( Vector2( ) );
	Vec c_pos = _camera->getPos( );
	bool camera_on = _camera->isCameraOn( );
	int ox = pos.x;
	int oy = pos.y;
	if ( camera_on ) {
		ox = ( int )pos.x - c_pos.x;
		oy = ( int )pos.y - c_pos.y;
	}

	SetDrawBlendMode( DX_BLENDMODE_ALPHA, _stroke_alpha );
	
	int r_start_x = returnRotatePosX( x1, y1 );
	int r_start_y = returnRotatePosY( x1, y1 );
	int r_end_x =   returnRotatePosX( x2, y2 );
	int r_end_y =   returnRotatePosY( x2, y2 );

	DrawLine( ox + r_start_x,
			  oy + r_start_y,
			  ox + r_end_x,
			  oy + r_end_y,
			  _stroke_color );
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );

}

double Global::sin( double angle ) {
	return ::sin( angle );
}

double Global::cos( double angle ) {
	return ::cos( angle );
}

int Global::floor( double num ) {
	return ( int )( num );
}

SoundPtr Global::loadSound( std::string filename ) {
	std::string directori_pass( "resource/" );
	return SoundPtr( new Sound( ( directori_pass + filename ).c_str( ) ) );
}

void Global::translate( int x, int y ) {
	_mat_transform = _mat_transform * Matrix::makeTransformTranslation( Vector2( x, y ) );
}

int Global::getFrameRate( ) {
	return _frame_rate;
}

void Global::setFrameRate( int rate ) {
	if ( _frame_rate == rate || rate < 1 ) {
		return;
	}
	_frame_rate = rate;
	_frame_count = 0;
	_start_time = GetNowCount( );
}

VideoPtr Global::createVideo( std::string filename ) {
	std::string path = "resource/" + filename;
	return VideoPtr( new Video( path.c_str( ), _camera ) );
}

SpritePtr Global::createSprite( int x, int y ) {
	SpritePtr sprite = SpritePtr( new Sprite( x, y, _camera ) );
	_sprites.push_back( sprite );
	return sprite;
}

int Global::getMouseX( ) {
	return _mouse_x;
}

int Global::getMouseY( ) {
	return _mouse_y;
}

bool Global::isMousePressed( ) {
	return _mouse_pressed;
}

void Global::loadPixels( ) {
	_pixels.clear( );
	DrawGraph( 0, 0, DX_SCREEN_BACK, FALSE );
	int si_handle = MakeARGB8ColorSoftImage( _width, _height );
	GetDrawScreenSoftImage( 0, 0, _width, _height, si_handle );
	BYTE* image = ( BYTE* )GetImageAddressSoftImage( si_handle );
	for ( int i = 0; i < _height; i++ ) {
		for ( int j = 0; j < _width; j++, image += 4 ) {
			_pixels.push_back( image[ 2 ] );
			_pixels.push_back( image[ 1 ] );
			_pixels.push_back( image[ 0 ] );
			_pixels.push_back( image[ 3 ] );
		}
	}
	SetDrawScreen( DX_SCREEN_BACK );
	DeleteGraph( si_handle );
}

int Global::getPixel( int index ) const {
	return _pixels[ index ];
}

void Global::setPixel( int index, int color ) {
	_pixels[ index ] = color;
}

void Global::updatePixels( ) {
	for ( int i = 0; i < _height; i++ ) {
		for ( int j = 0; j < _width; j++ ) {
			int index = ( j + i * _width ) * 4;
			DrawPixel( j, i, GetColor( _pixels[ index ], _pixels[ ( __int64 )index + 1 ], _pixels[ ( __int64 )index + 2 ] ) );
		}
	}
}

int Global::getHeight( ) {
	return _height;
}

int Global::getWidth( ) {
	return _width;
}

void Global::systemInit( ) {
	_start_time = GetNowCount( );
}

void Global::systemUpdate( ) {

	GetMousePoint( &_mouse_x, &_mouse_y );
	int mouse_input = GetMouseInput( );
	bool now_mouse_pressed =
		( mouse_input & MOUSE_INPUT_LEFT ) != 0 ||
		( mouse_input & MOUSE_INPUT_RIGHT ) != 0;
	if ( now_mouse_pressed && !_mouse_pressed ) {
		_instance->mouseClicked( );
	}
	_mouse_pressed = now_mouse_pressed;

	_frame_count++;
	int now_count = GetNowCount( );
	int wait_time = _frame_count * 1000 / _frame_rate - now_count + _start_time;
	if ( wait_time > 0 ) {
		Sleep( wait_time );
	}

	if ( _frame_count == 100 ) {
		_frame_count = 0;
		_start_time = now_count;
	}

	for ( int i = 0; i < _sprites.size( ); i++ ) {
		_sprites.at( i )->update( );
		if ( isSpriteTouch( i ) ) {
			_sprites.at( i )->callOnMousePressed( );
		}
	}
}

void Global::initTextStyle( ) {
	_normal_text_style = CreateFontToHandle( NULL, -1, 5, DX_FONTTYPE_NORMAL, DX_CHARSET_DEFAULT );
	_bold_text_style = CreateFontToHandle( NULL, -1, 9, DX_FONTTYPE_NORMAL, DX_CHARSET_DEFAULT );
	_italic_text_style = CreateFontToHandle( NULL, -1, 5, DX_FONTTYPE_NORMAL, DX_CHARSET_DEFAULT, -1, TRUE );
	_bold_italic_text_style = CreateFontToHandle( NULL, -1, 9, DX_FONTTYPE_NORMAL, DX_CHARSET_DEFAULT, -1, TRUE );
	_now_text_style = _normal_text_style;
}

void Global::deleteTextStyle( ) {
	DeleteFontToHandle( _normal_text_style );
	DeleteFontToHandle( _bold_text_style );
	DeleteFontToHandle( _italic_text_style );
	DeleteFontToHandle( _bold_italic_text_style );
}

void Global::drawSprite( SpritePtr sprite ) {
	sprite->draw( );
}

void Global::drawSprites( ) {
	for ( int i = 0; i < _sprites.size( ); i++ ) {
		_sprites.at( i )->draw( );
	}
}

void Global::deleteSprite( ) {
	for ( int i = 0; i < _sprites.size( ); i++ ) {
		if ( _sprites[ i ]->isDelete( ) ) {
			_sprites.erase( _sprites.begin( ) + i );
		}
	}
}

bool Global::isSpriteTouch( int index ) {
	SpritePtr sprite = _sprites.at( index );
	int sprite_center_x = ( int )sprite->getPos( ).x;
	int sprite_center_y = ( int )sprite->getPos( ).y;
	int sprite_half_size_x = ( int )sprite->getImageSize( ).x / 2;
	int sprite_half_size_y = ( int )sprite->getImageSize( ).y / 2;
	int sprite_left = sprite_center_x - sprite_half_size_x;
	int sprite_right = sprite_center_x + sprite_half_size_x;
	int sprite_top = sprite_center_y - sprite_half_size_y;
	int sprite_bottom = sprite_center_y + sprite_half_size_y;

	if ( _mouse_x < sprite_right && _mouse_x > sprite_left &&
		 _mouse_y < sprite_bottom && _mouse_y > sprite_top ) {
		if ( _mouse_pressed ) {
			return true;
		}
	}
	return false;
}

AnimationPtr Global::loadAnimation( int num, ... ) {
	AnimationPtr animation( new Animation( ) );

	va_list args;
	va_start( args, num );

	for ( int i = 0; i < num; i++ ) {
		const char* filename = va_arg( args, const char* );
		animation->add( filename );
	}

	va_end( args );

	return animation;
}

AnimationPtr Global::loadAnimation( const char* filename_begin, const char* filename_end ) {
	AnimationPtr animation( new Animation( ) );
	std::string begin = filename_begin;
	std::string end = filename_end;

	int num_count_begin[ 9 ] = { 0 };
	int num_count_end[ 9 ] = { 0 };
	int num_pos = -1;
	int digit_begin = 0;
	int digit_end = 0;

	for ( int i = 0; i < 9; i++ ) {
		std::string count_str = std::to_string( i );
		std::string begin_search;
		std::string end_search;
		for ( int j = 0; j < begin.size( ); j++ ) {
			begin_search = begin.substr( j, 1 );
			if ( begin_search == count_str ) {
				num_count_begin[ i ]++;
			}
		}
		for ( int j = 0; j < end.size( ); j++ ) {
			end_search = end.substr( j, 1 );
			if ( end_search == count_str ) {
				num_count_end[ i ]++;
			}
		}
		if ( num_pos == -1 ) {
			num_pos = ( int )begin.find( count_str.c_str( ) );
		}
		digit_begin += num_count_begin[ i ];
		digit_end += num_count_end[ i ];
	}

	std::string img_name = begin.substr( 0, num_pos );
	std::string img_behind_name = begin.substr( num_pos + digit_begin, begin.size( ) );
	std::string img_num_begin = begin.substr( num_pos, digit_begin );
	std::string img_num_end = end.substr( num_pos, digit_end );

	int loop_begin = atoi( img_num_begin.c_str( ) );
	int loop_end = atoi( img_num_end.c_str( ) );
	for ( int i = 0; i < loop_end; i++ ) {
		std::string str = img_name;
		if ( i < 9 ) {
			str += "0";
		}
		str += std::to_string( loop_begin + i ) + img_behind_name.c_str( );
		animation->add( str.c_str( ) );
	}
	return animation;
}

void Global::rectMode( int mode ) {
	_rect_mode = mode;
}

CameraPtr Global::getCamera( ) const {
	return _camera;
}

GroupPtr Global::createGroup( ) {
	GroupPtr group( new Group );
	return group;
}

int Global::getImagesLength( ) {
	return _images.size( );
}

void Global::angleMode( int mode ) {
	_angle_mode = mode;
}

void Global::rotate( double angle ) {
	rotateRectOn( true );
	if ( _angle_mode == DEGREES ) {
		_angle += ( angle *  PI ) / 180 ;
	}
	if ( _angle_mode == RADIANS ) {
		_angle += angle;
	}
}

void Global::rotateRectOn( bool enable ) {
	_rotate_enabled = enable;
}

int Global::returnRotatePosX( int x, int y ) {
	double sin_p = sin( _angle );
	double cos_p = cos( _angle );
	return cos_p * (double)x - sin_p * (double)y;
}

int Global::returnRotatePosY( int x, int y ) {
	double sin_p = sin( _angle );
	double cos_p = cos( _angle );
	return sin_p * x + cos_p * y;
}

// フレーム毎に値を初期化
void Global::resetSetting( ) {
	_angle = 0.0;
	_fill_color = 0;
}