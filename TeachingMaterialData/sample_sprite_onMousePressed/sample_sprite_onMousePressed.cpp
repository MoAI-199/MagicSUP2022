/*
�N���X
	Sprite
�錾
	void onMousePressed( Instance* _inst, void( Instance::* func )( ) )
	void onMousePressed( Instance* _inst, void( Instance::* func )( SpritePtr myself ) )
�T�v
	�X�v���C�g���������Ƃ��ɏ��������֐���o�^�ł���
����
	Instance* _inst        : this�ƋL�����Ă�������
	void( Instance::*func ): �o�^����֐�
�߂�l
	�Ȃ�
*/

#include "Magic.h"
MAGIC_BEGIN
SpritePtr sprite;
SpritePtr sprite2;

void setup( ) {
	sprite = createSprite( 200, 0 );
	sprite2 = createSprite( 400, 0 );
	sprite->setVelocity( sprite->getVelocity( ).x, 0.5 );
	sprite2->setVelocity( sprite2->getVelocity( ).x, 0.5 );
	sprite->onMousePressed( this, &Instance::deleted2 );
	sprite2->onMousePressed( this, &Instance::deleted2 );
}

void draw( ) {
	background( 255 );
	drawSprites( );
}

void deleted1( ) {
	sprite->setPos( 0, ( int )sprite->getPos( ).y );
}

void deleted2( SpritePtr myself ) {
	myself->setPos( ( int )myself->getPos( ).x, 0 );
}

MAGIC_END
