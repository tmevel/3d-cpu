#ifndef SHAPE3D_INCLUDED
#define SHAPE3D_INCLUDED


#include "Vector3D.h"
#include "PixelInfo.h"
#include <QImage>

class Shape3D{
	public:
	
	Shape3D(Vector3D const& origin, Vector3D const& e1, Vector3D const& e2, QImage const& texture);
	
	PixelInfo intersect(Vector3D const& camera, Vector3D const& target, PixelInfo const& last) const;
	void precompute(Vector3D const& camera);
	PixelInfo intersect(Vector3D const& target, PixelInfo const& last) const;
	
	private:
	
	Vector3D const m_origin;
	Vector3D const m_e1;
	Vector3D const m_e2;
	Vector3D const m_n;
	Vector3D const m_n1;
	Vector3D const m_n2;
	Vector3D m_tmp_co;
	Vector3D m_tmp_n_corrected;
	QImage const& m_texture;
};

#endif //SHAPE3D_INCLUDED
