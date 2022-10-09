/*
車を配列化して三台に増やしてください。
変数car_image、car_pos_x、car_pos_y、car_vec_xの後ろに「 [ 3 ] 」を書いて配列にしてください。(例：car_image[ 3 ])
[preload]でcar_image[ 0 ]～[ 2 ]に[loadImage]を代入してください。
car_image[ 0 ]の[loadImage]の中は( "car.png"  )にしてください。
car_image[ 1 ]の[loadImage]の中は( "car1.png"  )にしてください。
car_image[ 2 ][loadImage]の中は( "car2.png"  )にしてください。
[setup]で、car_pos_x[ 0 ]に150、car_pos_x[ 1 ]に100、car_pos_x[ 2 ]に200を代入してください。
[setup]で、car_pos_y[ 0 ]に200、car_pos_y[ 1 ]に300、car_pos_y[ 2 ]に400を代入してください。
[setup]で、car_vec_x[ 0 ]に5、car_vec_x[ 1 ]に6、car_vec_x[ 2 ]に4を代入してください。
[draw]にfor ( int i = 0; i < 3; i++ ) { }を書いてください。
[draw]のforの{ }の中に問題２と３で[draw]内に書いたコードを入れて、配列化した変数の後ろに「 [ i ] 」を書いてください。
*/

#include "Magic.h"
MAGIC_BEGIN

ImagePtr car_image[ 3 ];
int car_pos_x[ 3 ];
int car_pos_y[ 3 ];
int car_vec_x[ 3 ];
ImagePtr background_image;

void preload( ) {
    car_image[ 0 ] = loadImage( "car.png" );
    car_image[ 1 ] = loadImage( "car1.png" );
    car_image[ 2 ] = loadImage( "car2.png" );
    background_image = loadImage( "bg.png" );
}


void setup( ) {
    createCanvas( 600, 600 );

    car_pos_x[ 0 ] = 150;
    car_pos_y[ 0 ] = 200;
    car_vec_x[ 0 ] = 5;

    car_pos_x[ 1 ] = 100;
    car_pos_y[ 1 ] = 300;
    car_vec_x[ 1 ] = 6;

    car_pos_x[ 2 ] = 200;
    car_pos_y[ 2 ] = 400;
    car_vec_x[ 2 ] = 4;
}

void draw( ) {
    background( 255 );
    image( background_image, 300, 300 );
    imageMode( CENTER );

    for ( int i = 0; i < 3; i++ ) {
        image( car_image[ i ], car_pos_x[ i ], car_pos_y[ i ], 100, 100 );
        car_pos_x[ i ] += car_vec_x[ i ];
        int width = getWidth( );
        if ( car_pos_x[ i ] > width + 50 ) {
            car_pos_x[ i ] = -50;
        }
    }
}

MAGIC_END