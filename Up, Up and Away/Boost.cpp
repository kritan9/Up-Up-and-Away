#include "Boost.h"

unsigned int Boost::strength = 0;
float Boost::velocity = 5000.0f;
Boost::Boost()
{
}
void Boost::addStrength(const unsigned int x)
{
	strength += x;
}
float Boost::Velocity()
{
	velocity += (strength * velocity / 20);
	strength = 0;
	return velocity;
}
unsigned int Boost::Transparency()
{

}
Boost::~Boost()
{
}
