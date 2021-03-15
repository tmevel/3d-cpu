#include "Shape3D.h"
#include <iostream>

using namespace std;

Shape3D::Shape3D(Vector3D const& origin, Vector3D const& e1, Vector3D const& e2, QImage const& texture) : m_origin(origin), m_e1(e1), m_e2(e2), m_texture(texture), m_n(e1^e2), m_n1(e2^(e2^e1)*(1/(e1*(e2^(e2^e1))))), m_n2(e1^(e1^e2)*(1/(e2*(e1^(e1^e2))))), m_tmp_n_corrected(e1), m_tmp_co(e1){
	
}

PixelInfo Shape3D::intersect(Vector3D const& camera, Vector3D const& target, PixelInfo const& last) const{ //precompute and avoid div
	double lambda = ((m_origin-camera)*(m_n))/(target*(m_n));
	double mu1 = ((camera-m_origin)*(target^m_e2))/(m_e1*(target^m_e2));
	double mu2 = ((camera-m_origin)*(target^m_e1))/(m_e2*(target^m_e1));
	
	if(mu1<0||mu2<0||mu1>=1||mu2>=1||lambda>last.lambda()||lambda<0){
		return last;
	}
	
	QRgb color = m_texture.pixel(mu1*m_texture.width(), mu2*m_texture.height());
	
	return PixelInfo(color, lambda);
}
void Shape3D::precompute(Vector3D const& camera){
	m_tmp_co = m_origin-camera;
	m_tmp_n_corrected = m_n * (1/(m_tmp_co*m_n));
}
PixelInfo Shape3D::intersect(Vector3D const& target, PixelInfo const& last) const{
	double inv_lambda = target*m_tmp_n_corrected;
	
	if(inv_lambda<last.lambda()||inv_lambda<=0){
		return last;
	}
	
	Vector3D v = (target*(1/inv_lambda)) - m_tmp_co;
	
	double mu1 = v*m_n1;
	double mu2 = v*m_n2;
	
	if(mu1<0||mu2<0||mu1>=1||mu2>=1){
		return last;
	}
	
	QRgb color = m_texture.pixel(mu1*m_texture.width(), mu2*m_texture.height());
	
	return PixelInfo(color, inv_lambda);
}
