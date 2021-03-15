#ifndef VECTOR3D_INCLUDED
#define VECTOR3D_INCLUDED


class Vector3D{
	public:
	
	Vector3D(double const& x, double const& y, double const& z);
	
	double getX() const;
	double getY() const;
	double getZ() const;
	
	Vector3D& operator+=(Vector3D const& v);
	Vector3D& operator-=(Vector3D const& v);
	Vector3D& operator*=(double const& lambda);
	
	double scalar(Vector3D const& v) const;
	Vector3D cross(Vector3D const& v) const;
	double norm() const;
	Vector3D unit() const;
	
	
	private:
	
	double m_x;
	double m_y;
	double m_z;
};

Vector3D operator+(Vector3D const& u, Vector3D const& v);
Vector3D operator-(Vector3D const& u, Vector3D const& v);
Vector3D operator^(Vector3D const& u, Vector3D const& v);
double operator*(Vector3D const& u, Vector3D const& v);
Vector3D operator*(Vector3D const& v, double const& lambda);

#endif //VECTOR3D_INCLUDED
