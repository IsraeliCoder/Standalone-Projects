#include "ReturnMonneySystem.h"
#include <iostream>

#include "CanSystem.h"
#include "MoneySystem.h"

ReturnMonneySystem* ReturnMonneySystem::_returnMonneySystem = nullptr;

ReturnMonneySystem* ReturnMonneySystem::GetReturnMoneySystem()
{
	if (_returnMonneySystem == nullptr)
	{
		_returnMonneySystem = new ReturnMonneySystem();
		_returnMonneySystem->_canSystem = CanSystem::GetCanSystem();
		_returnMonneySystem->_moneySystem = MoneySystem::GetMoneySystem();
	}
	return _returnMonneySystem;
}

void ReturnMonneySystem::returnMoney()
{
	_moneySystem->changeTargetPrice(0, CanType::eNone);
	auto changeVector = _moneySystem->getChange();
	CoinRealReturn(changeVector);
}

void ReturnMonneySystem::CoinRealReturn(std::unordered_map<Coins, int> returnCoinVector )
{
	std::cout << "return the following coins : " << std::endl;
	for (auto it = returnCoinVector.cbegin(); it != returnCoinVector.cend(); ++it)
	{
		std::cout << it->first << " -> " << it->second << std::endl;
	}
	
	_moneySystem->reduceCoinVector(returnCoinVector);
}

void ReturnMonneySystem::giveCan(CanType canType)
{
	_canSystem->ReduceCan(canType);

	std::cout << "Gave can " << canType << std::endl;
}

ReturnMonneySystem::ReturnMonneySystem()
{
}
