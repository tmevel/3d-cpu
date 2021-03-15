#include "PixelInfo.h"

PixelInfo::PixelInfo(QRgb const& color, double const& lambda):m_color(color),m_lambda(lambda){
}
QRgb PixelInfo::color() const{
	return m_color;
}
double PixelInfo::lambda() const{
	return m_lambda;
}
