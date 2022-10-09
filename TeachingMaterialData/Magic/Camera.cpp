#include "../lib/Magic.h"
#include "DxLib.h"

Camera::Camera( ) {
	_pos.x = 0;
	_pos.y = 0;
	_camera_on = true;
}

Camera::~Camera( ) {

}

Global::Vec Camera::getPos( ) const {
	return _pos;
}

void Camera::setPos( Global::Vec pos ) {
	if ( _camera_on ) 	{
		_pos = pos;
	}
}

void Camera::off( ) {
	_camera_on = false;
}

void Camera::on( ) {
	_camera_on = true;
}

bool Camera::isCameraOn( ) {
	return _camera_on;
}