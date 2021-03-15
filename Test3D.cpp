#include "Test3D.h"

#include "3d/Vector3D.h"
#include "3d/Shape3D.h"
#include "3d/Camera.h"
#include "3d/Image3D.h"
#include <QApplication>
#include <QTime>
#include <QImage>
#include <iostream>

using namespace std;

Test3D::Test3D(QLabel &label):m_label(label){
	
}
void Test3D::run(){
	QImage brique("texture/brique.jpeg");
	QImage herbe("texture/herbe.jpeg");
	QImage bois("texture/bois.jpeg");
	
	Camera cam(Vector3D(0,0,2),0,0,1,1);
	Image3D i3d(400,400,cam);
	Shape3D sol(Vector3D(-10,-10,1),Vector3D(20,0,0),Vector3D(0,20,0),bois);
	Shape3D jardin(Vector3D(-50,-50,0),Vector3D(100,0,0),Vector3D(0,100,0),herbe);
	Shape3D murD(Vector3D(-10,-10,1),Vector3D(20,0,0),Vector3D(0,0,20),brique);
	Shape3D murF(Vector3D(-10,-10,1),Vector3D(0,20,0),Vector3D(0,0,20),brique);
	Shape3D murG(Vector3D(-10,10,1),Vector3D(20,0,0),Vector3D(0,0,20),brique);
	Shape3D toitD(Vector3D(-10,0,30),Vector3D(20,0,0),Vector3D(0,-10,-10),bois);
	Shape3D toitG(Vector3D(-10,0,30),Vector3D(20,0,0),Vector3D(0,10,-10),bois);
	Shape3D scene[] = {jardin,sol,murD,murG,toitD,toitG, murF};
	
	i3d.display(scene, 7);
	
	
	m_label.setPixmap(QPixmap::fromImage(i3d));
	m_label.show();
	QTime time;
	time.start();
	for(int k=0;k<100;k++){
		this_thread::sleep_for(chrono::milliseconds(10));
		cam.addTheta(0.03);
		i3d.display(scene, 7);
		m_label.setPixmap(QPixmap::fromImage(i3d));
	}
	cout<<"ms per frame: "<<(time.elapsed()/100)<<endl;
}
int main(int argc, char* argv[]){
	QApplication app(argc, argv);
	QLabel label;
	
	
	(new Test3D(label))->start();
	
	
	return app.exec();
}
