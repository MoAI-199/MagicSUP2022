#pragma once

#include <memory>
#include <vector>
#include <string>
#include <stdarg.h>
#include <map>
#include <string>
#include <algorithm>
#ifndef PTR
#define PTR( NAME )\
	class NAME;\
	typedef std::shared_ptr< NAME > NAME##Ptr;
#endif

PTR( Sound );
PTR( Video );
PTR( Sprite );
PTR( Image );
PTR( Animation );
PTR( Group );
PTR( Camera );

class Instance;


class Global {
public:
	Global( );
	virtual ~Global( );
public:
	struct Vec {
		double x;
		double y;
	};
public:
	virtual void setup( ) { }
	virtual void draw( ) { }
	virtual void preload( ) { }
	virtual void mouseClicked( ) { }
public:
	static const int LEFT = 1;
	static const int RIGHT = 2;
	static const int CENTER = 3;
	static const int CORNERS = 4;
	static const int CORNER = 5;
	static const int RADIUS = 6;
	static const int RADIANS = 7;
	static const int DEGREES = 8;
public:
	void createCanvas( int w, int h );
	void background( int grey, int alpha = 255 );
	void background( int r, int g, int b, int alpha = 255 );
	void background( ImagePtr img, int alpha = 255 );
	void ellipse( int x, int y, int r );
	void noFill( );
	void fill( int r, int g, int b, int alpha = 255 );
	void fill( int gray, int alpha = 255 );
	void noStroke( );
	void stroke( int r, int g, int b );
	void stroke( int r, int g, int b, int alpha );
	void strokeWeight( int weight );
	ImagePtr loadImage( std::string filename );
	void image( ImagePtr img, int x, int y );
	void image( ImagePtr img, int x, int y, int width, int height );
	void imageMode( int mode );
	void text( const char* str, int x, int y );
	void textSize( int size );
	void textAlign( int align );
	void textStyle( const char* style_name );
	bool keyDown( const char* key_str );
	double random( int high );
	double random( int low, int high );
	void rect( int x, int y, int w, int h );
	void line( int x1, int y1, int x2, int y2 );
	double sin( double angle );
	double cos( double angle );
	int floor( double num );
	SoundPtr loadSound( std::string filename );
	VideoPtr createVideo( std::string filename );
	SpritePtr createSprite( int x, int y );
	GroupPtr createGroup( );
	void drawSprite( SpritePtr sprite );
	void drawSprites( );
	void deleteSprite( );
	void translate( int x, int y );
	int getFrameRate( );
	void setFrameRate( int rate );
	int getMouseX( );
	int getMouseY( );
	int getHeight( );
	int getWidth( );
	bool isMousePressed( );
	void loadPixels( );
	int getPixel( int index ) const;
	void setPixel( int index, int color );
	void updatePixels( );
	void systemInit( );
	void systemUpdate( );
	void initTextStyle( );
	void deleteTextStyle( );
	AnimationPtr loadAnimation( int num, ... );
	AnimationPtr loadAnimation( const char* filename_begin, const char* filename_end );
	void rectMode( int mode );
	CameraPtr getCamera( ) const;
	int getImagesLength( );
	void angleMode( int mode );
	void rotate( double angle );
	void rotateRectOn( bool enable );
	void resetSetting( );
private:
	bool isSpriteTouch( int index );
	int returnRotatePosX(int x, int y);
	int returnRotatePosY(int x, int y);
private:
	int _frame_rate = 60;
	int _frame_count = 0;
	int _start_time = 0;
	int _width = 640;
	int _height = 480;
	bool _mouse_pressed = false;
	int _mouse_x = 0;
	int _mouse_y = 0;
	bool _push = false;
	bool _fill_enabled = true;
	bool _stroke_enabled = true;
	bool _rotate_enabled = false;
	int _fill_color = 0;
	int _fill_red = 0;
	int _fill_green = 0;
	int _fill_blue = 0;
	int _fill_alpha = 255;
	int _stroke_color = 0;
	int _stroke_alpha = 255;
	int _stroke_weight = 1;
	int _image_mode = CORNER;
	int _rect_mode = CORNER;
	int _text_align = LEFT;
	int _normal_text_style;
	int _bold_text_style;
	int _italic_text_style;
	int _bold_italic_text_style;
	int _now_text_style = NULL;
	int _angle_mode = RADIANS;
	double _angle = 0.0;
	std::vector< SpritePtr > _sprites;
	std::vector< ImagePtr > _images;
	std::vector< int > _pixels;
	CameraPtr _camera;
};

class Sound {
public:
	Sound( std::string filename );
	virtual ~Sound( );
	void play( );
	void pause( );
	void loop( );
	int isPlaying( );
private:
	int _handle;
};

class Video {
public:
	Video( const char* filename, CameraPtr camera );
	virtual ~Video( );
public:
	void image( int x, int y );
	void pause( );
	void loop( );
	void hide( );
	int getWidth( ) const;
	int getHeight( ) const;
	void loadPixels( );
	int getPixel( int index ) const;
	void setPixel( int index, int color );
	void updatePixels( );
private:
	int _handle;
	bool _pause;
	bool _hide;
	int _x;
	int _y;
	std::vector< int > _pixels;
	int _canvas_width;
	int _canvas_height;
	CameraPtr _camera;
};

class Sprite : public std::enable_shared_from_this< Sprite > {
public:
	Sprite( int x, int y, CameraPtr camera );
	virtual ~Sprite( );
public:
	void draw( );
	void update( );
	void addImage( const ImagePtr image );
	void addImage( const char* label, const ImagePtr image );
	bool isDelete( ) const;
	int getTypeNumber( ) const;
	int getIndex( ) const;
	Global::Vec getVelocity( )const;
	Global::Vec getPos( )const;
	Global::Vec getBeforePos( )const;
	Global::Vec getImageSize( )const;
	const char* getAnimationLabel( ) const;

	void setPos( int x, int y );
	void setVelocity( double velocityX, double velocityY );
	void remove( );
	void onMousePressed( Instance* _inst, void( Instance::* func )( ) );
	void onMousePressed( Instance* _inst, void( Instance::* func )( SpritePtr myself ) );
	void callOnMousePressed( );
	void setScale( double scale );
	double getScale( ) const;
	void setTypeNumber( int num );
	void setIndex( int index );
	void setLife( int life );
	void addAnimation( const char* label, AnimationPtr animation );
	void changeImage( const char* label );
	void changeAnimation( const char* label );

	void overlap( GroupPtr group, Instance* _inst, void( Instance::* func )( SpritePtr myself, SpritePtr group_menber ) );
private:
	int _image = -1;
	AnimationPtr _animation;
	std::map< const char*, int > _image_list;
	std::map< const char*, AnimationPtr > _animation_list;
	std::map< int, const char* > _label_list;
	int _life = 0;
	bool _delete;
	bool _on_mouse_clicked = false;
	bool _on_mouse_pushed = false;
	void ( Instance::* _func_on_mouse_pressed )( );
	void ( Instance::* _func_on_mouse_pressed_with_arguments )( SpritePtr myself );
	void ( Instance::* _func_overlap )( SpritePtr myself, SpritePtr group_menber );
	Instance* _instance;
	double _scale;
	int _type_num;
	int _index;
	std::vector< int > _handle;
	Global::Vec _pos;
	Global::Vec _before_pos;
	Global::Vec _velocity;
	Global::Vec _image_size;
	CameraPtr _camera;
};

class Image {
public:
	Image( int handle, int canvas_width, int canvas_height );
	virtual ~Image( );
public:
	void updatePixels( );
	void loadPixels( );
	void setPixel( int index, int color );
	void setPos( int x, int y );
	int getHandle( ) const;
	int getWidth( ) const;
	int getHeight( ) const;
	int getPixel( int index ) const;
	Global::Vec getPos( )const;

private:
	int _handle;
	int _x;
	int _y;
	std::vector< int > _pixels;
	int _canvas_width;
	int _canvas_height;
	Global::Vec _pos;
};

class Animation {
public:
	Animation( );
	virtual ~Animation( );
	void add( const char* filename );
	int getHandle( );
	int AnimationCounter( );
	void frameDelay( int delay );
private:
	std::vector< int >  _handles;
	int _count = 0;
	int _delay = 5;
};

class Group {
public:
	Group( );
	virtual ~Group( );
public:
	void add( SpritePtr sprite );
	int getSize( ) const;
	SpritePtr getSprite( int idx ) const;
	void remove( );
	void remove( int idx );
	void collide( SpritePtr sprite );
private:
	std::vector<SpritePtr >_sprite_list;
};

class Camera {
public:
	Camera( );
	~Camera( );
public:
	Global::Vec getPos( ) const;
	void setPos( Global::Vec pos );
	void off( );
	void on( );
	bool isCameraOn( );
private:
	Global::Vec _pos;
	bool _camera_on;
};

#define MAGIC_BEGIN \
class Instance : public Global { \
public: \
	Instance( ) : Global( ) { } \
	virtual ~Instance( ) { }

#define MAGIC_END \
} __instance__;
