#include "DogB.h"

DogB::DogB(int foodCapacity, float height, int barkingVolum, int hairLength) : Dog(foodCapacity, height, barkingVolum, hairLength)
{
}

int DogB::getScoreBasedOnFood()
{
	return Dog::SCORE_FACTOR * (foodGiven_);
}

int DogB::getScoreBasedOnBarking()
{
	return Dog::SCORE_FACTOR * (1 - (1.0 / hairLenght_)) * barkingVolum_;
}

void DogB::updateBarkingVolume()
{
	barkingVolum_++;
}
