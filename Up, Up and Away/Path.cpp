#include "Path.h"

Path::Path()
{
}

void Path::Road(float off)
{
	float temp1 = (WIDTH - Width)*0.5f, temp2 = (WIDTH + Width)*0.5f, temp3 = Length / noOfSpikes;
	for (int i = 0; i < noOfSpikes; i++)
	{
	
			spike[i].setPoint(0, Point(temp1 + curveX(i*temp3 - off), 0.0f, i*temp3 - off).getPosition());
			spike[i + noOfSpikes].setPoint(0, Point(temp2 + curveX(i*temp3 - off), 0.0f, i*temp3 - off).getPosition());
			spike[i].setPoint(1, Point(temp1 + curveX(i*temp3 + temp3 - off), 0.0f, i*temp3 + temp3 - off).getPosition());
			spike[i + noOfSpikes].setPoint(1, Point(temp2 + curveX(i*temp3 + temp3 - off), 0.0f, i*temp3 + temp3 - off).getPosition());
			spike[i].setPoint(2, Point(temp1 + curveX(i*temp3 + temp3 * 0.5f - off), 40.0f, i*temp3 + temp3 * 0.5f - off).getPosition());
			spike[i + noOfSpikes].setPoint(2, Point(temp2 + curveX(i*temp3 + temp3 * 0.5f - off), 40.0f, i*temp3 + temp3 * 0.5f - off).getPosition());
		

		road[i].setPoint(0, Point(temp1 + curveX(i*temp3 - off), 0.0f, i*temp3 - off).getPosition());
		road[i].setPoint(1, Point(temp2 + curveX(i*temp3 - off), 0.0f, i*temp3 - off).getPosition());
		road[i].setPoint(2, Point(temp2 + curveX(i*temp3 + temp3 - off), 0.0f, i*temp3 + temp3 - off).getPosition());
		road[i].setPoint(3, Point(temp1 + curveX(i*temp3 + temp3 - off), 0.0f, i*temp3 + temp3 - off).getPosition());
	}
}

Path::Path(float l, float w,int n):Length(l),Width(w),noOfSpikes(n)
{
	road.resize(noOfSpikes);
	color = sf::Color(171, 172, 239);
	color2 = sf::Color(125, 125, 255,255);
	spike.resize(2 * noOfSpikes); 
	offset = 0;
	for (int i = 0; i < n; i++) 
	{
		spike[i] = sf::ConvexShape(3); spike[i + n] = sf::ConvexShape(3); 
		spike[i].setFillColor(color2); spike[i + n].setFillColor(color2);
			spike[i].setOutlineThickness(1); spike[i + n].setOutlineThickness(1);
		spike[i].setOutlineColor(sf::Color(0,0,0,10)); spike[i + n].setOutlineColor(sf::Color(0,0,0,10));

		road[i] = sf::ConvexShape(4); 
		road[i].setFillColor(color);
		
	}
	Road(offset);
}
void Path::Draw(sf::RenderWindow& window)
{
	
	for (int i = noOfSpikes-1; i >= 0; i--) {
		window.draw(road[i]); window.draw(spike[i]); window.draw(spike[i + noOfSpikes]);
	}
}
void Path::Update(float dt)
{
	offset += velocity * dt;
	if (offset >= Length / noOfSpikes) offset = 0;
	Road(offset);
}

Path::~Path()
{
	spike.clear();
}
