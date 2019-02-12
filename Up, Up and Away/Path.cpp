#include "Path.h"

Path::Path()
{
}

void Path::Spikes(float off)
{
	float temp1 = (WIDTH - Width)*0.5f, temp2 = (WIDTH + Width)*0.5f, temp3 = Length / noOfSpikes;
	for (int i = 0; i < noOfSpikes; i++)
	{
		spike[i].setPoint(0, Point(temp1, 0.0f, i*temp3-off).getPosition()); spike[i + noOfSpikes].setPoint(0, Point(temp2, 0.0f, i*temp3-off).getPosition());
		spike[i].setPoint(1, Point(temp1, 0.0f, i*temp3 + temp3-off).getPosition());  spike[i + noOfSpikes].setPoint(1, Point(temp2, 0.0f, i*temp3 + temp3-off).getPosition());
		spike[i].setPoint(2, Point(temp1, 40.0f, i*temp3 + temp3 * 0.5f-off).getPosition()); spike[i + noOfSpikes].setPoint(2, Point(temp2, 40.0f, i*temp3 + temp3 * 0.5f-off).getPosition());
	}
}

Path::Path(float l, float w,int n):Length(l),Width(w),noOfSpikes(n)
{
	p1 = Point((WIDTH - Width)*0.5f, 0, 0);
	p2 = Point((WIDTH + Width)*0.5f, 0, 0);
	p3 = Point((WIDTH + Width)*0.5f, 0, Length);
	p4 = Point((WIDTH - Width)*0.5f, 0, Length);
	shape = sf::ConvexShape(4);
	shape.setPoint(0, p1.getPosition());
	shape.setPoint(1, p2.getPosition());
	shape.setPoint(2, p3.getPosition());
	shape.setPoint(3, p4.getPosition());
	color = sf::Color(171, 172, 239);
	color2 = sf::Color(151, 150, 250);
	shape.setFillColor(color);
	spike = new sf::ConvexShape[2 * noOfSpikes];
	offset = 0;
	for (int i = 0; i < n; i++) 
	{
		spike[i] = sf::ConvexShape(3); spike[i + n] = sf::ConvexShape(3); 
		spike[i].setFillColor(color2); spike[i + n].setFillColor(color2);
		spike[i].setOutlineThickness(1); spike[i + n].setOutlineThickness(1);
		spike[i].setOutlineColor(sf::Color::Black); spike[i + n].setOutlineColor(sf::Color::Black);
	}
	Spikes(offset);
}
void Path::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
	for (int i = 0; i < 2 * noOfSpikes; i++) window.draw(spike[i]);
}
void Path::Update(float dt)
{
	offset += velocity * dt;
	if (offset >= Length / noOfSpikes) offset = 0;
	Spikes(offset);
}

Path::~Path()
{
	delete[] spike;
}
