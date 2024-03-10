#pragma once
#include "Dog.h"

class DogA : public Dog
{

public:

	DogA(int foodCapacity, float height, int barkingVolum, int hairLength);

protected:

	virtual int getScoreBasedOnFood() override;
	virtual int getScoreBasedOnBarking() override;
	virtual void updateBarkingVolume() override;

};

typedef std::shared_ptr<DogA> PDogA;

