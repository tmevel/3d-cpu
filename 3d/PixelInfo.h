#ifndef PIXELINFO_INCLUDED
#define PIXELINFO_INCLUDED

#include <QColor>

class PixelInfo{
	public:
	PixelInfo(QRgb const& color, double const& lambda);
	QRgb color() const;
	double lambda() const;
	
	private:
	QRgb m_color;
	double m_lambda;
};

#endif //PIXELINFO_INCLUDED
