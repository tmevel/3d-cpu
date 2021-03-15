#ifndef IMAGE3D_INCLUDED
#define IMAGE3D_INCLUDED


#include <QImage>
#include "Vector3D.h"
#include "Shape3D.h"
#include "Camera.h"

class Image3D : public QImage{
	public:
	
	Image3D(double const& width, double const& height, Camera& camera);
	void display(Shape3D scene[], int const& nbShapes);
	
	private:
	Camera& m_camera;
};

#endif //IMAGE3D_INCLUDED
