#include "../lib/Magic.h"
#include "DxLib.h"

Image::Image( int handle, int canvas_width, int canvas_height )
{
	_handle = handle;
	_canvas_width = canvas_width;
	_canvas_height = canvas_height;
	  _x = 0;
	 _y = 0;
}

Image::~Image( ) {

}

int Image::getHandle( ) const {
	return _handle;
}

int Image::getWidth( ) const {
	int width = 0;
	int height = 0;
	GetGraphSize( _handle, &width, &height );
	return width;
}

int Image::getHeight( ) const {
	int width = 0;
	int height = 0;
	GetGraphSize( _handle, &width, &height );
	return height;
}

void Image::loadPixels( ) {
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

int Image::getPixel( int index ) const {
	return _pixels[ index ];
}



void Image::setPixel( int index, int color ) {
	_pixels[ index ] = color;
}

void Image::updatePixels( ) {
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

void Image::setPos( int x, int y ) {
	_x = x;
	_y = y;
}

Global::Vec Image::getPos( ) const {
	return _pos;
}





