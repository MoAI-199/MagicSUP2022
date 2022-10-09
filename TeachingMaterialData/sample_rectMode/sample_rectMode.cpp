/*
宣言
    void rectMode( int mode )
概要
    四角の表示位置の指定方法を変更します。CENTERは四角の中心の座標を指定するモードです。
引数
    mode : CENTER
戻り値
    無し
*/
#include "Magic.h"
MAGIC_BEGIN

ImagePtr photoImage;

void setup( ) {
    createCanvas( 600, 600 );
    background( 228 );
    rectMode( CENTER );
}

void draw( ) {
    fill( 100 );
    rotate( 45 );
    rect( 300, 300, 150, 150 );
}


MAGIC_END
