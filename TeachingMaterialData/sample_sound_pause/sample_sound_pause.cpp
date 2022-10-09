/*
クラス
	Sound
宣言
	void pause( );
概要
	停止する
引数
	なし
戻り値
	なし
*/
#include "Magic.h"
MAGIC_BEGIN

SoundPtr sound;
void setup( ) {
	sound = loadSound( "mySound.mp3" );
	sound->play( );
}

void draw( ) {
	if ( isMousePressed( ) ) {
		sound->pause( );
	}
}
MAGIC_END
