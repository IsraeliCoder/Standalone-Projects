#pragma once

#include <memory>
#include <string>
#include <unordered_map>

class Dog;
typedef std::shared_ptr<Dog> PDog;

class Dog
{

public:

	Dog(int foodCapacity, float height, int barkingVolum, int hairLength);

	static PDog GenerateDog(std::string name,int foodCapacity, float height, int barkingVolum, int hairLength);
	virtual int calculateScore();
	virtual void Update(int food);

	virtual void setScore(int score);


	static const int MAX_SCORE_VALUE;
	static const int MIN_SCORE_VALUE;
	static const int SCORE_FACTOR;

protected:
	
	int score_;

	int foodGiven_;
	int foodCapacity_;
	float height_;
	int barkingVolum_;
	int hairLenght_;

	static std::unordered_map<std::string, std::shared_ptr<Dog>(*)(int, float, int, int)> NAME_TO_FUNCTION;

	void setScoreHelper(int scoreE, int min, int max);

	virtual int getScoreBasedOnFood() = 0;
	virtual int getScoreBasedOnBarking() = 0;
	virtual void updateBarkingVolume() = 0;

	template <typename T>
	static std::shared_ptr<Dog> getDogPointer(int foodCapacity, float height, int barkingVolum, int hairLength);

private:

};

template <typename T>
std::shared_ptr<Dog> Dog::getDogPointer(int foodCapacity, float height, int barkingVolum, int hairLength)
{
	std::shared_ptr<T> da = std::make_shared<T>(foodCapacity, height, barkingVolum, hairLength);
	std::shared_ptr<Dog> d = std::static_pointer_cast<Dog>(da);
	return d;
}