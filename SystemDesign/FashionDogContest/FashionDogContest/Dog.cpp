#include "Dog.h"

#include <functional>

#include "DogA.h"
#include "DogB.h"
#include "DogC.h"

const int Dog::MAX_SCORE_VALUE = 150;
const int Dog::MIN_SCORE_VALUE = 13;
const int Dog::SCORE_FACTOR = 10;


std::unordered_map<std::string, std::shared_ptr<Dog>(*)(int, float, int, int)> Dog::NAME_TO_FUNCTION = {
	{"dogA", [](int foodCapacity, float height, int barkingVolum, int hairLength) {
		return getDogPointer<DogA>(foodCapacity, height, barkingVolum, hairLength);
	}},
	{"dogB", [](int foodCapacity, float height, int barkingVolum, int hairLength) {
		return getDogPointer<DogB>(foodCapacity, height, barkingVolum, hairLength);
	}},
	{"dogC", [](int foodCapacity, float height, int barkingVolum, int hairLength) {
		return getDogPointer<DogC>(foodCapacity, height, barkingVolum, hairLength);
	}},
};


PDog Dog::GenerateDog(std::string name, int foodCapacity, float height, int barkingVolum, int hairLength)
{
	return NAME_TO_FUNCTION[name](foodCapacity, height, barkingVolum, hairLength);
}

int Dog::calculateScore()
{
	setScore(score_ + getScoreBasedOnFood() + getScoreBasedOnBarking());
	return score_;
}

void Dog::Update(int food)
{
	foodGiven_ += food;
	foodGiven_ -= foodCapacity_;
}

void Dog::setScore(int score)
{
	setScoreHelper(score, MIN_SCORE_VALUE, MAX_SCORE_VALUE);
}

Dog::Dog(int foodCapacity, float height, int barkingVolum, int hairLength) :
	foodCapacity_(foodCapacity), height_(height), barkingVolum_(barkingVolum), hairLenght_(hairLength),
	foodGiven_(0)
{
	setScore(0);
}

void Dog::setScoreHelper(int score, int min, int max)
{
	score_ = std::min(std::max(score, min), max);
}
