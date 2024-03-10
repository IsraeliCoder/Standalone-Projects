
#include <vector>
#include <memory>

#include "Dog.h"
#include "Common.h"

void main()
{

	std::vector<PDog> dogs;

	for (int i = 0; i < 3; i++)
	{
		
		dogs.push_back(Dog::GenerateDog("dogA", 5, 1.2, 3, 1));
		dogs.push_back(Dog::GenerateDog("dogC", Common::getRandom(1,60), 0.25, Common::getRandom(-5, 5), Common::getRandom(-100, 100)));
		dogs.push_back(Dog::GenerateDog("dogB", 2, 1.9, 1, 1));

	}

	for (auto& dog : dogs)
	{
		dog->Update(Common::getRandom(1, 60));
		printf("%d\n", dog->calculateScore());
	}
	
}