#include "Image3D.h"
#include <iostream>

using namespace std;

Image3D::Image3D(double const& width, double const& height, Camera& camera):QImage(width,height,QImage::Format_RGB32),m_camera(camera){
	
}
void Image3D::display(Shape3D scene[], int const& nbShapes){
	fill(qRgb(0, 0, 0));
	PixelInfo first(qRgb(0, 0, 0), 0);
	
	for(int k=0;k<nbShapes;k++){
		scene[k].precompute(m_camera.position());
	}
	
	for(int x=0;x<width();x++){
		Vector3D px = m_camera.xScreen()*((double)x/width()*2 - 1);
		Vector3D targetx = m_camera.target()+px;
		for(int y=0;y<height();y++){
			Vector3D py = m_camera.yScreen()*((double)y/height()*2 - 1);
			Vector3D target = targetx+py;
			
			PixelInfo pixel = scene[0].intersect(target, first);
			
			for(int k=1;k<nbShapes;k++){
				pixel = scene[k].intersect(target, pixel);
			}
			setPixel(x,y,pixel.color());
		}
	}
}
