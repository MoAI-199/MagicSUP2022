#pragma once

#include <math.h>

/// <summary>
/// �~����
/// </summary>
const double PI  = 3.1415926535897932384626433832795;
/// <summary>
/// �~��
/// </summary>
const double PI2 = PI * 2;

/// <summary>
/// �O�p��
/// </summary>
const unsigned int VECTOR_RATIO = 1 << 16;
/// <summary>
/// VECTOR_MARGIN�̃r�b�g�̒l��ݒ�
/// </summary>
const unsigned int VECTOR_MARGIN = 1 << 15;

/// <summary>
/// �~�`
/// </summary>
/// <param name="in_value">�l</param>
/// <returns></returns>
inline double round(const double in_value) {
	int in = (int)(in_value * VECTOR_RATIO);
	return (double)in / VECTOR_RATIO;
}

struct Vector {
	double x;
	double y;
	double z;

	/// <summary>
	/// ���_
	/// </summary>
	Vector()
		: x(0)
		, y(0)
		, z(0) {
	}

	/// <summary> 2D�̉~�̒��_ </summary>
	/// <param name="inX"> X���W </param>
	/// <param name="inY"> Y���W </param>
	/// <param name="inZ"> Z���W </param>
	Vector(const double inX, const double inY, const double inZ = 0)
		: x(round(inX))
		, y(round(inY))
		, z(round(inZ)) {
	}

	/// <summary>
	/// �S�Ă̒��_�f�[�^��j��
	/// </summary>
	virtual ~Vector() {

	}

	// �����̂Q��i�v�Z�X�s�[�h����̂��߁j
	/// <summary>
	/// �Εӂ̒���
	/// </summary>
	/// <returns></returns>
	inline double getLength2() const {
		return x * x + y * y + z * z;
	}

	// ����
	/// <summary>
	/// �������擾����
	/// </summary>
	/// <returns></returns>
	inline double getLength() const {
		double s[3] = { fabs(x), fabs(y), fabs(z)};
		double n = s[0];
		for (int i = 1; i < 3; i++) {
			if (n < s[i]) n = s[i];
		}
		if (n == 0.0) {
			return 0;
		}
		double x = this->x / n;
		double y = this->y / n;
		double z = this->z / n;
		return sqrt(x * x + y * y + z * z) * n;
	}

	// �����Z
	inline Vector add(const Vector& inVector) const {
		return Vector(
			x + inVector.x,	
			y + inVector.y,
			z + inVector.z);
	}
	inline Vector operator+(const Vector& inVector) const {
		return add(inVector);
	}
	inline Vector operator+=(const Vector& inVector) {
		*this = *this + inVector;
		return *this;
	}

	// �����Z
	inline Vector sub(const Vector& inVector) const {
		return Vector(
			x - inVector.x,	
			y - inVector.y,
			z - inVector.z);
	}
	inline Vector operator-(const Vector& inVector) const {
		return sub(inVector);
	}
	inline Vector operator-=(const Vector& inVector) {
		*this = *this - inVector;
		return *this;
	}

	// �|���Z
	/// <summary>
	/// ���_�̊|���Z
	/// </summary>
	/// <param name="inValue"> �|����l </param>
	inline Vector multiply(const double inValue) const {
		return Vector(
			x * inValue,	
			y * inValue,
			z * inValue);
	}
	inline Vector operator*(const double inValue) const {
		return multiply(inValue);
	}
	inline Vector operator*=(const double inValue) {
		*this = *this * inValue;
		return *this;
	}

	// �x�N�g�����m�̐�
	inline Vector product(const Vector& inVector) const {
			double x1 = x * inVector.x;
			double x2 = x * inVector.y; 
			double y1 = y * inVector.x;
			double y2 = y * inVector.y; 

			return Vector( x1 - y2, x2 + y1, 0 );
	}
	// �O��
	inline Vector cross(const Vector& inVector) const {
		Vector v1 = (*this).normalize();
		Vector v2 = inVector.normalize();
		Vector vc(
			v1.y * v2.z - v2.y * v1.z,
			v1.z * v2.x - v2.z * v1.x,
			v1.x * v2.y - v2.x * v1.y);
		return vc.normalize();
	}

	// ����
	inline double dot(const Vector& inVec) const {
		double x = this->x * inVec.x;
		double y = this->y * inVec.y;
		double z = this->z * inVec.z;
		return x + y + z;
	}

	// ���K��	
	inline Vector normalize() const {
		double norm = getLength();
		if (norm == 0) {
			norm = 1; // �傫�����Ȃ��̂ŁA�P�őΉ�
		}
		return Vector(
			x / norm,
			y / norm,
			z / norm);
	}

	// �Q�x�N�g���Ԃ̊p�x�i���W�A���j�����߂�
	// �G���[��-1
	inline double angle(const Vector& in_vec) const {
		Vector v1 = normalize();
		Vector v2 = in_vec.normalize();
		double d = v1.dot(v2);

		if (d >= 1) {
			return 0;
		}
		
		if (d <= -1) {
			return PI;
		}

		return acos(d);
	}

	/// <summary>
	/// ���_�m�F
	/// </summary>
	inline bool isOrigin() const {
		return
			x == 0 &&
			y == 0 &&
			z == 0;
	}

	// �C�R�[��
	inline bool operator==(const Vector& inVec) const {
		int sx = (int)(this->x * VECTOR_MARGIN);
		int sy = (int)(this->y * VECTOR_MARGIN);
		int sz = (int)(this->z * VECTOR_MARGIN);
		int dx = (int)(inVec.x * VECTOR_MARGIN);
		int dy = (int)(inVec.y * VECTOR_MARGIN);
		int fz = (int)(inVec.z * VECTOR_MARGIN);
		return
			sx == dx &&
			sy == dy &&
			sz == fz;
	}
	inline bool operator!=(const Vector& inVec) const {
		return !(*this == inVec);
	}
};


struct Vector2 {
	double x;
	double y;

	/// <summary>
	/// ���_
	/// </summary>
	Vector2( )
		: x( 0 )
		, y( 0 ) {
	}

	/// <summary> 2D�̉~�̒��_ </summary>
	/// <param name="inX"> X���W </param>
	/// <param name="inY"> Y���W </param>
	/// <param name="inZ"> Z���W </param>
	Vector2( const double inX, const double inY )
		: x( round( inX ) )
		, y( round( inY ) ) {
	}

	/// <summary>
	/// �S�Ă̒��_�f�[�^��j��
	/// </summary>
	virtual ~Vector2( ) {

	}

	// �����̂Q��i�v�Z�X�s�[�h����̂��߁j
	/// <summary>
	/// �Εӂ̒���
	/// </summary>
	/// <returns></returns>
	inline double getLength2( ) const {
		return x * x + y * y;
	}

	// ����
	/// <summary>
	/// �������擾����
	/// </summary>
	/// <returns></returns>
	inline double getLength( ) const {
		double s[ 2 ] = { fabs( x ), fabs( y ) };
		double n = s[ 0 ];
		for ( int i = 1; i < 2; i++ ) {
			if ( n < s[ i ] ) n = s[ i ];
		}
		if ( n == 0.0 ) {
			return 0;
		}
		double x = this->x / n;
		double y = this->y / n;
		return sqrt( x * x + y * y ) * n;
	}

	// �����Z
	inline Vector2 add( const Vector2& inVector2 ) const {
		return Vector2(
			x + inVector2.x,
			y + inVector2.y );
	}
	inline Vector2 operator+( const Vector2& inVector2 ) const {
		return add( inVector2 );
	}
	inline Vector2 operator+=( const Vector2& inVector2 ) {
		*this = *this + inVector2;
		return *this;
	}

	// �����Z
	inline Vector2 sub( const Vector2& inVector2 ) const {
		return Vector2(
			x - inVector2.x,
			y - inVector2.y );
	}
	inline Vector2 operator-( const Vector2& inVector2 ) const {
		return sub( inVector2 );
	}
	inline Vector2 operator-=( const Vector2& inVector2 ) {
		*this = *this - inVector2;
		return *this;
	}

	// �|���Z
	/// <summary>
	/// ���_�̊|���Z
	/// </summary>
	/// <param name="inValue"> �|����l </param>
	inline Vector2 multiply( const double inValue ) const {
		return Vector2(
			x * inValue,
			y * inValue );
	}
	inline Vector2 operator*( const double inValue ) const {
		return multiply( inValue );
	}
	inline Vector2 operator*=( const double inValue ) {
		*this = *this * inValue;
		return *this;
	}

	// ��]
	inline Vector2 rotate( double angle ) const {
		return Vector2(
			x * cos( angle ) - y * sin( angle ),
			x * sin( angle ) + y * cos( angle ) );
	}

	// �O��
	inline double cross( const Vector2& inVec2 ) const {
		return x * inVec2.y - y * inVec2.x;
	}

	// ����
	inline double dot( const Vector2& inVec2 ) const {
		double x = this->x * inVec2.x;
		double y = this->y * inVec2.y;
		return x + y;
	}

	// ���K��	
	inline Vector2 normalize( ) const {
		double norm = getLength( );
		if ( norm == 0 ) {
			norm = 1; // �傫�����Ȃ��̂ŁA�P�őΉ�
		}
		return Vector2(
			x / norm,
			y / norm );
	}

	// �Q�x�N�g���Ԃ̊p�x�i���W�A���j�����߂�
	// �G���[��-1
	inline double angle( const Vector2& in_vec2 ) const {
		Vector2 v1( x, y );
		Vector2 v2 = in_vec2;

		double d = v1.dot( v2 );

		if ( d >= 1 ) {
			return 0;
		}

		if ( d <= -1 ) {
			return PI;
		}

		double n = v1.getLength( ) * v2.getLength( );
		double cos_theta = d / n;
		if ( cos_theta >= 1.0 ) {
			return 0;
		}

		return acos( cos_theta );
	}

	/// <summary>
	/// ���_�m�F
	/// </summary>
	inline bool isOrigin( ) const {
		return
			x == 0 &&
			y == 0;
	}

	// �C�R�[��
	inline bool operator==( const Vector2 inVec2 ) const {
		int sx = ( int )( this->x * VECTOR_MARGIN );
		int sy = ( int )( this->y * VECTOR_MARGIN );
		int dx = ( int )( inVec2.x * VECTOR_MARGIN );
		int dy = ( int )( inVec2.y * VECTOR_MARGIN );
		return
			sx == dx &&
			sy == dy;
	}
	inline bool operator!=( const Vector2& inVec2 ) const {
		return !( *this == inVec2 );
	}

};

struct Matrix {
	double data[ 4 ][ 4 ];

	/// <summary>
	/// �s��̃f�[�^���쐬
	/// </summary>
	Matrix( ) {
		// Matrix�����ꂽ��A�P�ʍs����쐬����
		for ( int i = 0; i < 4; i++ )
			for ( int j = 0; j < 4; j++ ) {
				data[ i ][ j ] = 0;
			}
		for ( int i = 0; i < 4; i++ ) {
			data[ i ][ i ] = 1;
		}
	}

	/// <summary>
	/// �s��̃f�[�^��j��
	/// </summary>
	virtual ~Matrix( ) {
	}

	inline static Matrix makeTransformTranslation( const Vector& inTrans ) {
		// ���s�ړ��̕ϊ��s������
		Matrix mat;

		mat.data[ 3 ][ 0 ] = inTrans.x;
		mat.data[ 3 ][ 1 ] = inTrans.y;
		mat.data[ 3 ][ 2 ] = inTrans.z;

		return mat;
	}

	inline static Matrix makeTransformTranslation( const Vector2& inTrans ) {
		// ���s�ړ��̕ϊ��s������
		Matrix mat;

		mat.data[ 3 ][ 0 ] = inTrans.x;
		mat.data[ 3 ][ 1 ] = inTrans.y;
		mat.data[ 3 ][ 2 ] = 0;

		return mat;
	}

	inline static Matrix makeTransformScaling( const Vector& inScale ) {
		// �g��k���̕ϊ��s������
		Matrix mat;

		mat.data[ 0 ][ 0 ] = inScale.x;
		mat.data[ 1 ][ 1 ] = inScale.y;
		mat.data[ 2 ][ 2 ] = inScale.z;

		return mat;
	}

	inline static Matrix makeTransformScaling( const Vector2& inScale ) {
		// �g��k���̕ϊ��s������
		Matrix mat;

		mat.data[ 0 ][ 0 ] = inScale.x;
		mat.data[ 1 ][ 1 ] = inScale.y;
		mat.data[ 2 ][ 2 ] = 1;

		return mat;
	}

	inline static Matrix makeTransformRotation( const double inRadian ) {
		return makeTransformRotation( Vector( 0, 0, 1 ), inRadian );
	}

	inline static Matrix makeTransformRotation( const Vector& inAxis, const double inRadian ) {
		// �C�ӎ���]�̕ϊ��s������
		Matrix mat;
		Vector v = inAxis.normalize( );
		double c = ( 1 - cos( inRadian ) );

		mat.data[ 0 ][ 0 ] = v.x * v.x * c + cos( inRadian );
		mat.data[ 0 ][ 1 ] = v.x * v.y * c - v.z * sin( inRadian );
		mat.data[ 0 ][ 2 ] = v.z * v.x * c + v.y * sin( inRadian );

		mat.data[ 1 ][ 0 ] = v.x * v.y * c + v.z * sin( inRadian );
		mat.data[ 1 ][ 1 ] = v.y * v.y * c + cos( inRadian );
		mat.data[ 1 ][ 2 ] = v.y * v.z * c - v.x * sin( inRadian );

		mat.data[ 2 ][ 0 ] = v.z * v.x * c - v.y * sin( inRadian );
		mat.data[ 2 ][ 1 ] = v.y * v.z * c + v.x * sin( inRadian );
		mat.data[ 2 ][ 2 ] = v.z * v.z * c + cos( inRadian );

		return mat;
	}

	inline Matrix multiply( const Matrix& inMat ) const {
		Matrix mat;
		for ( int n = 0; n < 4; n++ ) {
			for ( int m = 0; m < 4; m++ ) {
				mat.data[ n ][ m ] = 0;
				for ( int i = 0; i < 4; i++ ) {
					mat.data[ n ][ m ] += data[ n ][ i ] * inMat.data[ i ][ m ];
				}
			}
		}
		return mat;
	}

	inline Matrix operator*( const Matrix& inMat ) const {
		return this->multiply( inMat );
	}

	inline Vector multiply( const Vector& inVector ) const {
		return Vector(
			data[ 0 ][ 0 ] * inVector.x + data[ 1 ][ 0 ] * inVector.y + data[ 2 ][ 0 ] * inVector.z + data[ 3 ][ 0 ] * 1,
			data[ 0 ][ 1 ] * inVector.x + data[ 1 ][ 1 ] * inVector.y + data[ 2 ][ 1 ] * inVector.z + data[ 3 ][ 1 ] * 1,
			data[ 0 ][ 2 ] * inVector.x + data[ 1 ][ 2 ] * inVector.y + data[ 2 ][ 2 ] * inVector.z + data[ 3 ][ 2 ] * 1 );
	}

	inline Vector operator*( const Vector& inVector ) const {
		return this->multiply( inVector );
	}

	inline Vector2 multiply( const Vector2& inVector ) const {
		return Vector2(
			data[ 0 ][ 0 ] * inVector.x + data[ 1 ][ 0 ] * inVector.y + data[ 2 ][ 0 ] * 1 + data[ 3 ][ 0 ] * 1,
			data[ 0 ][ 1 ] * inVector.x + data[ 1 ][ 1 ] * inVector.y + data[ 2 ][ 1 ] * 1 + data[ 3 ][ 1 ] * 1 );
	}

	inline Vector2 operator*( const Vector2& inVector ) const {
		return this->multiply( inVector );
	}
};

struct Quaternion {
	double x;
	double y;
	double z;
	double w;

	inline Quaternion makeTransformRotation( const Vector& dir, double angle ) {
		Vector v = dir.normalize( );
		x = v.x * sin( angle / 2 );
		y = v.y * sin( angle / 2 );
		z = v.z * sin( angle / 2 );
		w =       cos( angle / 2 );
	}
};
