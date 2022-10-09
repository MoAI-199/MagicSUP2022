/*
クラス
	Sprite
宣言
	void addImage( const ImagePtr image );
	void addImage( const char* label, const ImagePtr image );
概要
	spriteに画像を読み込む
引数
	label : 画像につけるラベル名
	image :　ロードする画像、及び動画ファイルのファイルパス文字列へのポインタ
戻り値
	なし
*/
#include "Magic.h"
MAGIC_BEGIN

SpritePtr sprite;
ImagePtr _logo;
void setup( ) {
	sprite = createSprite( 0, 0 );
	_logo = loadImage( "logo.png" );
	sprite->addImage( _logo );
	sprite->addImage( "tca", _logo );
}

void draw( ) {
	drawSprite( sprite );
}

MAGIC_END
