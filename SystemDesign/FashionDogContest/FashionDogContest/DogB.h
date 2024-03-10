#pragma once

#include "Dog.h"

class DogB : public Dog
{

public:

	DogB(int foodCapacity, float height, int barkingVolum, int hairLength);

protected:


	virtual int getScoreBasedOnFood() override;
	virtual int getScoreBasedOnBarking() override;
	virtual void updateBarkingVolume() override;

};

typedef std::shared_ptr<DogB> PDogB;