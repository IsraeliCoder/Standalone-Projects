#include "CanSystem.h"

#include "ReturnMoneyInterface.h"
#include "MoneySystem.h"

CanSystem* CanSystem::_canSystem = nullptr;

CanSystem::CanSystem(std::unordered_map<CanType, int> canCount, std::unordered_map<CanType, int> canPrice)
{
	_canCount = canCount;
	_canPrice = canPrice;
}

CanSystem* CanSystem::GetCanSystem(std::unordered_map<CanType, int> canCount, std::unordered_map<CanType, int> canPrice)
{
	if (_canSystem == nullptr)
	{
		_canSystem = new CanSystem(canCount, canPrice);
		_canSystem->_moneySystem = MoneySystem::GetMoneySystem();
	}
	return _canSystem;
}

void CanSystem::selectCan(CanType canType)
{

	if (_canCount[canType] > 0)
	{
		showAndUpdatePrice(canType);

	}
	else
	{

		std::cout << "Not enough cans from type " << std::to_string(canType) << std::endl;

	}

}

void CanSystem::showAndUpdatePrice(CanType canType)
{
	std::cout << "Can price is " << _canPrice[canType];
	_moneySystem->changeTargetPrice(_canPrice[canType], canType);
}
