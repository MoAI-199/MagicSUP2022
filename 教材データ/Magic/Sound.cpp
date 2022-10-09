#include "../lib/Magic.h"
#include "DxLib.h"

Sound::Sound( std::string filename ) {
	std::string directori_pass( "resource/" );
	_handle = LoadSoundMem( ( filename ).c_str( ) );
}

Sound::~Sound( ) {

}

void Sound::play( ) {
	PlaySoundMem( _handle, DX_PLAYTYPE_BACK );
}

void Sound::pause( ) {
	StopSoundMem( _handle );
}

void Sound::loop( ) {
	PlaySoundMem( _handle, DX_PLAYTYPE_LOOP );
}

int Sound::isPlaying( ) {
	return CheckSoundMem( _handle );
}
