#include "DxLib.h"
#include "../lib/Magic.h"
#include "mathematics.h"

Global* _instance = NULL;
extern Matrix _mat_transform;

int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd ) {
	// log.txt���\��
	SetOutApplicationLogValidFlag( FALSE );
	// �E�C���h�E���[�h�ɕύX
	ChangeWindowMode( TRUE );
	// �`���𗠉�ʂɕύX
	SetDrawScreen( DX_SCREEN_BACK );
	// �}�E�X�J�[�\����\��
	SetMouseDispFlag( TRUE );

	//�E�B���h�E�ݒ�
	_instance->systemInit( );

	if ( DxLib_Init( ) == -1 ) {
		return -1;
	}

	_instance->initTextStyle( );

	//�E�B���h�E�̍ő�T�C�Y��ݒ�
	int max_width = 5000;
	int max_height = 5000;
	SetGraphMode( max_width, max_height, 32 );
	//�E�B���h�E�T�C�Y�����R�Ȕ䗦�ŕύX�o���悤�ɂ���
	SetWindowSizeChangeEnableFlag( FALSE, FALSE );

	_instance->background( 255 );
	_instance->preload( );
	_instance->setup( );
	while ( true ) {
		if ( ProcessMessage( ) != 0 ) {
			break;
		}
		if ( CheckHitKey( KEY_INPUT_ESCAPE ) != 0 ) {
			break;
		}

		_instance->systemUpdate( );

		_mat_transform = Matrix( );
		_instance->resetSetting( );
		_instance->draw( );
		_instance->deleteSprite( );

		ScreenFlip( );
		DrawGraph( 0, 0, DX_SCREEN_FRONT, FALSE );
	}

	_instance->deleteTextStyle( );

	DxLib_End( );
	return 0; 
}