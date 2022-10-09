/*
宣言
	ImagePtr loadImage( const char * filename )
概要
	画像ファイルをメモリにロードします
引数
	filename :　ロードする画像、及び動画ファイルのファイルパス文字列へのポインタ
戻り値
	－１　　　:　エラー発生
	－１以外　:　グラフィックのハンドル
*/

#include "Magic.h"
MAGIC_BEGIN

ImagePtr img;
void setup( ) {
	img = loadImage( "logo.png" );
	image( img, 0, 0 );
}

void draw( ) {

}

MAGIC_END