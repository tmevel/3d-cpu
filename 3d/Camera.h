#ifndef CAMERA_INCLUDED
#define CAMERA_INCLUDED

#include "Vector3D.h"

class Camera{
	public:
	
	Camera(Vector3D const& position, double const& theta, double const& phi, double const& viewAngle, double const& xyRatio);
	void move(Vector3D const& v);
	void addTheta(double const& theta);
	void addPhi(double const& phi);
	Vector3D position() const;
	Vector3D target() const;
	Vector3D xScreen() const;
	Vector3D yScreen() const;
	
	
	private:
	
	Vector3D m_position;
	Vector3D m_target;
	Vector3D m_xScreen;
	Vector3D m_yScreen;
	double m_theta;
	double m_phi;
	double const m_viewAngle;
	double const m_yxRatio;
	void compute();
};

#endif //CAMERA_INCLUDED
