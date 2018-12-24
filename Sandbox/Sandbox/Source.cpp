#include <algorithm>
#include <cmath>

// create extra functions here
struct Point {

	int x;

	int y;

	Point(int a, int b) : x(a), y(b) {}

};

bool comp_angle(Point p1, Point p2)
{
	return std::atan(p1.y / p1.x) < std::atan(p2.y / p2.x);
}

bool is_inside_triangle(Point p1, Point p2, Point p3, Point x)
{
	// fill in your code here
	Point points[4] = { p1, p2, p3, x };

	Point low(1000000000, 1000000000);
	for (int i = 0; i < 4; i++)
	{
		low = low.y < points[i].y || (low.y == points[i].y && low.x < points[i].x) ? low : points[i];
	}

	for (int i = 0; i < 4; i++)
	{
		points[i].x -= low.x; points[i].y -= low.y;
	}

	std::sort(points + 1, points + 4, comp_angle);

	return points[3].x + low.x == x.x && points[3].y + low.y == x.y && points[3].x * points[1].y - points[3].y * points[1].x < 0;
}

int main()
{
	is_inside_triangle({ 0,0 }, { 2,0 }, { 3,2 }, { 1,1 });
}