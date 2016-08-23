#include <stdlib.h>

const double epsilon = 1e-7;

class Vector2d;
class Line2d;

class Point2d
{
	Point2d() : mX(0.0), mY(0.0) {};
	Point2d(const Point2d& vec) : mX(vec.mX), mY(vec.mY) {};
	Point2d(double x, double y) : mX(x), mY(y) {};
	double distanceTo(const Point2d&);

	friend class Vector2d;
	friend class Line2d;

private:
	double mX;
	double mY;
};

double Point2d::distanceTo(const Point2d& pt)
{
	double xDiff = x - p.x;
    double yDiff = y - p.y;
    return sqrt(xDiff*xDiff + yDiff*yDiff);
}

class Vector2d
{
	Vector2d() : mX(0.0), mY(0.0) {};
	Vector2d(const Vector2d& vec) : mX(vec.mX), mY(vec.mY) {};
	Vector2d(double x, double y) : mX(x), mY(y) {};

	Vector2d operator+(const Vector2d&);
	Vector2d operator-(const Vector2d&);

	double length() const;
	Vector2d normal() const;
	Vector2d& normalize();
	double dotProduct(const Vector2d&) const;
	Vector2d crossProduct(const Vector2d&) const;

	double angleTo(const Vector2d&) const;
	bool isParallelTo(const Vector2d& v) const; 
	Vector2d& negate();

private:
	double mX;
	double mY;
};

Vector2d Vector2d::operator+(const Vector2d& vec)
{
	return Vector2d(x+vec.x, y+vec.y);
}

Vector2d Vector2d::operator-(const Vector2d& vec)
{
	return Vector2d(x-vec.x, y-vec.y);
}

double Vector2d::length() const
{
	return sqrt(x*x + y*y);
}

Vector2d Vector2d::normal() const
{
	if(length() < epsilon)
		return Vector2d(0.0, 0.0);
	else
	{
		double lengthInv = 1.0 / length();
		return Vector2d(mX*lengthInv, mY*lengthInv);
	}
}

Vector2d& Vector2d::normal()
{
	double lengthInv;
	if(length() < epsilon)
		lengthInv = 0.0;
	else
	{
		lengthInv = 1.0 / length();
		mX *= lengthInv;
		mY *= lengthInv;
	}

	return *this;
}

double Vector2d::dotProduct(const Vector2d& vec) const
{
	return mX*vec.mX + mY*vec.mY;
}

Vector2d Vector2d::crossProduct(const Vector2d& vec) const
{
	return Vector2d(mX*vec.mY - mY*vec.mX));
}

double Vector2d::angleTo(const Vector2d& vec) const
{
	double cosVal = dotProduct(vec)/(length() * vec.length());

	double angle = 0.0;
	if (cosVal > 1.0) // Account for any noise
        angle = 0.0;
    else 
    	angle = acos(cosVal);

    return angle;
}

Vector2d& Vector2d::negate()
{
	mX *= -1;
	mY *= -1;
	return *this;
}

bool Vector2d::isParallelTo(const Vector2d& vec)
{
	Vector2d  v1 = normal(), v2 = v.normal(), v3;
	if (v1.dotProduct(v2) < 0.0)
	    v2.negate(); 
    v3 = v1 - v2;

    return (v3.length() <= epsilon);
}

class Line2d
{
	Line2d() : mOrigin(), mDirection();
	Line2d(const Point2d&, const Point2d&);

	double distanceTo(const Point2d&) const;  
	Point2d closestPointTo(const Point2d&) const; 

private:
	Point2d mOrigin;
	Vector2d mDirection;
}

Line2d::Line2d(const Point2d& pt1, const Point2d& pt2)
{
	mOrigin = pt1;
    mDirection = (pt1 - pt2).normalize();
}

Point2d Line2d::closestPointTo(const Point2d&) const
{

}
