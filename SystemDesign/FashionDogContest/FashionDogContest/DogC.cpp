#include "DogC.h"
#include "Common.h"

const int DogC::MAX_SCORE_VALUE = 1000;
const int DogC::MIN_SCORE_VALUE = -1000;

DogC::DogC(int foodCapacity, float height, int barkingVolum, int hairLength) :
	Dog(foodCapacity, height, barkingVolum, hairLength)
{
}

void DogC::setScore(int score)
{
	setScoreHelper(score, DogC::MIN_SCORE_VALUE, DogC::MAX_SCORE_VALUE);
}

int DogC::getScoreBasedOnFood()
{
	return Common::getRandom(-Dog::SCORE_FACTOR, Dog::SCORE_FACTOR);
}

int DogC::getScoreBasedOnBarking()
{
	return Common::getRandom(-Dog::SCORE_FACTOR, Dog::SCORE_FACTOR);
}

void DogC::updateBarkingVolume()
{
	barkingVolum_ += Common::getRandom(-Dog::SCORE_FACTOR, Dog::SCORE_FACTOR);
}
