#pragma once
class Boost
{
	unsigned static int strength;
	float static velocity;
public:
	Boost();
	static void addStrength(const unsigned int);
	static float Velocity();
	static unsigned int Transparency();
	
	~Boost();
};

