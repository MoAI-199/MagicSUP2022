/*
�N���X
	Sprite
�錾
	void addImage( const ImagePtr image );
	void addImage( const char* label, const ImagePtr image );
�T�v
	sprite�ɉ摜��ǂݍ���
����
	label : �摜�ɂ��郉�x����
	image :�@���[�h����摜�A�y�ѓ���t�@�C���̃t�@�C���p�X������ւ̃|�C���^
�߂�l
	�Ȃ�
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
