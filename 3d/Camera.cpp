#include "Camera.h"
#include <cmath>

using namespace std;

Camera::Camera(Vector3D const& position, double const& theta, double const& phi, double const& viewAngle, double const& xyRatio):m_position(position),m_theta(theta),m_phi(phi),m_viewAngle(viewAngle),m_yxRatio(1/xyRatio),m_target(position),m_xScreen(position),m_yScreen(position){
	compute();
}

void Camera::move(Vector3D const& v){
	m_position+=v;
}
void Camera::addTheta(double const& theta){
	m_theta+=theta;
	compute();
}
void Camera::addPhi(double const& phi){
	m_phi+=phi;
	compute();
}
Vector3D Camera::position() const{
	return Vector3D(m_position);
}
Vector3D Camera::target() const{
	return Vector3D(m_target);
}
Vector3D Camera::xScreen() const{
	return Vector3D(m_xScreen);
}
Vector3D Camera::yScreen() const{
	return Vector3D(m_yScreen);
}
void Camera::compute(){
	m_target = Vector3D(cos(m_theta)*cos(m_phi), sin(m_theta)*cos(m_phi), sin(m_phi));
	m_xScreen = m_target^Vector3D(0,0,1)*tan(m_viewAngle/2);
	m_yScreen = m_target^m_xScreen*m_yxRatio;
}
