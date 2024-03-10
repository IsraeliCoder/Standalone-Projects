#include "DogA.h"

DogA::DogA(int foodCapacity, float height, int barkingVolum, int hairLength) :
	Dog(foodCapacity, height, barkingVolum, hairLength)
{
}

int DogA::getScoreBasedOnFood()
{
	
	if (foodGiven_ < 0)
		return -Dog::SCORE_FACTOR;

	
	int foodNeeded = height_ / 0.2;

	if (foodNeeded <= foodGiven_)
		return 0;

	return Dog::SCORE_FACTOR * (1 - (foodGiven_ / foodNeeded));

}

int DogA::getScoreBasedOnBarking()
{
	return barkingVolum_ * hairLenght_;
}

void DogA::updateBarkingVolume()
{
	barkingVolum_ -= 1;
	barkingVolum_ = std::max(barkingVolum_, 0);
}
