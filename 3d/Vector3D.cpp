#include "Vector3D.h"
#include <cmath>

using namespace std;

Vector3D::Vector3D(double const& x, double const& y, double const& z) : m_x(x),m_y(y),m_z(z){
	
}

double Vector3D::getX() const{
	return m_x;
}
double Vector3D::getY() const{
	return m_y;
}
double Vector3D::getZ() const{
	return m_z;
}
Vector3D& Vector3D::operator+=(Vector3D const& v){
	m_x+=v.m_x;
	m_y+=v.m_y;
	m_z+=v.m_z;
	
	return *this;
}
Vector3D& Vector3D::operator-=(Vector3D const& v){
	m_x-=v.m_x;
	m_y-=v.m_y;
	m_z-=v.m_z;
	
	return *this;
}
Vector3D& Vector3D::operator*=(double const& lambda){
	m_x*=lambda;
	m_y*=lambda;
	m_z*=lambda;
	
	return *this;
}
double Vector3D::scalar(Vector3D const& v) const{
	return m_x*v.m_x + m_y*v.m_y + m_z*v.m_z;
}
Vector3D Vector3D::cross(Vector3D const& v) const{
	return Vector3D(m_y*v.m_z-m_z*v.m_y, m_z*v.m_x - m_x*v.m_z, m_x*v.m_y - m_y*v.m_x);
}
double Vector3D::norm() const{
	return sqrt(this->scalar(*this));
}
Vector3D Vector3D::unit() const{
	Vector3D result(*this);
	result*=result.norm();
	
	return result;
}


Vector3D operator+(Vector3D const& u, Vector3D const& v){
	Vector3D result(u);
	result+=v;
	
	return result;
}
Vector3D operator-(Vector3D const& u, Vector3D const& v){
	Vector3D result(u);
	result-=v;
	
	return result;
}
Vector3D operator^(Vector3D const& u, Vector3D const& v){
	return u.cross(v);
}
double operator*(Vector3D const& u, Vector3D const& v){
	return u.scalar(v);
}
Vector3D operator*(Vector3D const& v, double const& lambda){
	Vector3D result(v);
	result*=lambda;
	
	return result;
}
