#include "../lib/Magic.h"
#include "Dxlib.h"

Animation::Animation( ) {

}

Animation::~Animation( ) {

}

void Animation::add( const char* filename ) {
	_handles.push_back( LoadGraph( filename ) );
}

int Animation::getHandle( ) {
	return _handles.at( _count );
}

int Animation::AnimationCounter( ) {
	_count++;
	if ( _count >= _handles.size( ) ) {
		_count = 0;
	}
	WaitVSync( _delay );
	return _count;
}

void Animation::frameDelay( int delay ) {
	_delay = delay;
}
