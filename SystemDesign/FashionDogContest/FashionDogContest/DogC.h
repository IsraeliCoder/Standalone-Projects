#pragma once
#include "Dog.h"

class DogC : public Dog
{
public:
	virtual void setScore(int score) override;

	static const int MAX_SCORE_VALUE;
	static const int MIN_SCORE_VALUE;

	DogC(int foodCapacity, float height, int barkingVolum, int hairLength);

protected:
	virtual int getScoreBasedOnFood() override;
	virtual int getScoreBasedOnBarking() override;
	virtual void updateBarkingVolume() override;
};

typedef std::shared_ptr<DogC> PDogC;