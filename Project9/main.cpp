//HM_ex_1_7.05.2023
#include <iostream>

using namespace std;
struct Rectangle 
{
	double width;
	double height;
	double x;
	double y;
};

void moveRectangle(Rectangle& rect, double offsetX, double offsetY) 
{
	rect.x += offsetX;
	rect.y += offsetY;
}


void resizeRectangle(Rectangle& rect, double newWidth, double newHeight) 
{
	rect.width = newWidth;
	rect.height = newHeight;
}


void printRectangle(const Rectangle& rect) 
{
	std::cout << "Rectangle Details:" << std::endl;
	std::cout << "Width: " << rect.width << std::endl;
	std::cout << "Height: " << rect.height << std::endl;
	std::cout << "Position (x, y): (" << rect.x << ", " << rect.y << ")" << std::endl;
}


int main() 
{
    Rectangle rect;
	rect.width = 5.0;
	rect.height = 3.0;
	rect.x = 2.0;
	rect.y = 1.0;
	printRectangle(rect);
	moveRectangle(rect, 3.0, -2.0);
	resizeRectangle(rect, 7.0, 4.0);
	printRectangle(rect);
	return 0;
}
//HM_ex_2_7.05.2023
#include <iostream>
#include <cmath>
using namespace std;
struct Point 
{
	double x;
	double y;
};
double calculateDistance(const Point& p1, const Point& p2) 
{
	double distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
	return distance;
}
int main() 
{
	Point p1, p2;
	p1.x = 2.0;
	p1.y = 3.0;
	p2.x = -1.0;
	p2.y = 5.0;
	double distance = calculateDistance(p1, p2);
	std::cout << "Distance between the two points: " << distance << std::endl;
	return 0;
}
//HM_ex_3_7.05.2023
#include <iostream>
using namespace std;
struct Fraction {
	int numerator;   // чисельник
	int denominator; // знаменник
};
// функція для знаходження найбільшого спільного дільника двох чисел
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}
// функція для скорочення дробу
void simplify(Fraction& f) 
{
	int divisor = gcd(f.numerator, f.denominator);
	f.numerator /= divisor;
	f.denominator /= divisor;
}
// функція для перетворення неправильного дробу на простий
void toProper(Fraction& f) 
{
	if (f.numerator >= f.denominator) 
	{
		int whole = f.numerator / f.denominator;
		f.numerator -= whole * f.denominator;
		f.numerator %= f.denominator;
		f.numerator += whole * f.denominator;
	}
}
// функція для додавання двох дробів
Fraction add(Fraction f1, Fraction f2)
{
	Fraction result;
	result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	result.denominator = f1.denominator * f2.denominator;
	simplify(result);
	toProper(result);
	return result;
}
// функція для віднімання двох дробів
Fraction subtract(Fraction f1, Fraction f2) 
{
	Fraction result;
	result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
	result.denominator = f1.denominator * f2.denominator;
	simplify(result);
	toProper(result);
	return result;
}
// функція для множення двох дробів
Fraction multiply(Fraction f1, Fraction f2) 
{
	Fraction result;
	result.numerator = f1.numerator * f2.numerator;
	result.denominator = f1.denominator * f2.denominator;
	simplify(result);
	toProper(result);
	return result;
}
// функція для ділення двох дробів
Fraction divide(Fraction f1, Fraction f2) 
{
	Fraction result;
	result.numerator = f1.numerator * f2.denominator;
	result.denominator = f1.denominator * f2.numerator;
	simplify(result);
	toProper(result);
	return result;
}