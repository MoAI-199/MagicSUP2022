#include "../lib/Magic.h"
#include "DxLib.h"

Video::Video( const char* filename, CameraPtr camera ) {
	_handle = LoadGraph( filename );
	_pause = false;
	_hide = false;
	_x = 0;
	_y = 0;
	_canvas_height = getHeight( );
	_canvas_width = getWidth( );
	_camera = camera;
}

Video::~Video( ) {

}

void Video::image( int x, int y ) {
	Global::Vec c_pos = _camera->getPos( );
	bool camera_on = _camera->isCameraOn( );
	int _x = 0;
	int _y = 0;
	if ( camera_on ) {
		_x = x - c_pos.x;
		_y = y - c_pos.y;
	}
	if ( !_hide ) {
		DrawGraph( x, y, _handle, FALSE );

	} else {
		_hide = false;
	}
}

void Video::pause( ) {
	PauseMovieToGraph( _handle );
	_pause = true;
}

void Video::loop( ) {
	if ( _pause == false ) {
		if ( GetMovieStateToGraph( _handle ) == 0 ) {
			SeekMovieToGraph( _handle, 0 );
			PlayMovieToGraph( _handle );
		}
	} else {
		PlayMovieToGraph( _handle );
		_pause = false;
	}
}

void Video::hide( ) {

	_hide = true;
}

int Video::getWidth( ) const {
	int width = 0;
	int height = 0;
	GetGraphSize( _handle, &width, &height );
	return width;
}

int Video::getHeight( ) const {
	int width = 0;
	int height = 0;
	GetGraphSize( _handle, &width, &height );
	return height;
}

void Video::loadPixels( ) {
	_pixels.clear( );
	int width = 0;
	int height = 0;
	GetGraphSize( _handle, &width, &height );
	if ( width > _canvas_width ) {
		width = _canvas_width;
	}
	if ( height > _canvas_height ) {
		height = _canvas_height;
	}
	DrawGraph( _x, _y, _handle, FALSE );
	int si_handle = MakeARGB8ColorSoftImage( width, height );
	GetDrawScreenSoftImage( _x, _y, _x + width, _y + height, si_handle );
	BYTE* image = (BYTE*)GetImageAddressSoftImage( si_handle );
	for ( int i = 0; i < height; i++ ) {
		for ( int j = 0; j < width; j++, image += 4 ) {
			_pixels.push_back( image[ 2 ] );
			_pixels.push_back( image[ 1 ] );
			_pixels.push_back( image[ 0 ] );
			_pixels.push_back( image[ 3 ] );
		}
	}
	SetDrawScreen( DX_SCREEN_BACK );
	DeleteGraph( si_handle );
}

int Video::getPixel( int index ) const {
	return _pixels[ index ];
}

void Video::setPixel( int index, int color ) {
	_pixels[ index ] = color;
}

void Video::updatePixels( ) {
	int width = 0;
	int height = 0;
	GetGraphSize( _handle, &width, &height );
	for ( int i = 0; i < height; i++ ) {
		for ( int j = 0; j < width; j++ ) {
			int index = ( j + i * width ) * 4;
			DrawPixel( _x + j, _y + i, GetColor( _pixels[ index ], _pixels[ (__int64)index + 1 ], _pixels[ (__int64)index + 2 ] ) );
		}
	}
}