#ifndef TEST3D_INCLUDED
#define TEST3D_INCLUDED


#include <QThread>
#include <QLabel>
#include "3d/Image3D.h"

class Test3D: public QThread{
	public:
	Test3D(QLabel &label);
	void run() override;
	
	private:
	QLabel& m_label;
};

int main(int argc, char* argv[]);

#endif //TEST3D_INCLUDED
