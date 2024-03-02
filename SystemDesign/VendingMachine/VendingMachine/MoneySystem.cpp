#include "MoneySystem.h"

#include <vector>
#include <iostream>

#include "ReturnMonneySystem.h"

MoneySystem* MoneySystem::_monneySystem = nullptr;

MoneySystem::MoneySystem() : _price(-1), _canType(CanType::eNone), _monneyCollected(0)
{

	_vault[Coins::eTen] = 100;
	_vault[Coins::eFive] = 100;
	_vault[Coins::eOne] = 100;

}

void MoneySystem::changeTargetPrice(int price, CanType canType)
{
	_price = price;
	_canType = canType;
}

void MoneySystem::insertCoin(Coins coin)
{
	_monneyCollected += int(coin);
	_vault[coin]++;
	checkIfGiveACan();
}

void MoneySystem::checkIfGiveACan()
{
	if (_canType != CanType::eNone && _monneyCollected >= _price)
	{
		std::unordered_map<Coins, int> changeToReturn = getChange();

		if (changeToReturn.empty())
			return;

		_returnMoneySystem->CoinRealReturn(changeToReturn);
		_returnMoneySystem->giveCan(_canType);

		_monneyCollected = 0;
		_canType = CanType::eNone;
	}
}

std::unordered_map<Coins, int> MoneySystem::getChange()
{
	int monneyToReturn = _monneyCollected - _price;
	std::unordered_map<Coins, int> toReturn;

	std::vector<Coins> possibeCoins = { eTen, eFive, eOne };

	for (int i = 0; i < possibeCoins.size(); i++)
	{
		while (monneyToReturn >= possibeCoins[i] && _vault[possibeCoins[i]] > toReturn[possibeCoins[i]])
		{
			monneyToReturn -= possibeCoins[i];
			toReturn[possibeCoins[i]]++;
		}
	}

	if (monneyToReturn != 0)
	{
		std::cout << "Not enough change!" << std::endl;
		return {};
	}

	return toReturn;

}

void MoneySystem::reduceCoinVector(std::unordered_map<Coins, int> coinVector)
{
	_vault[Coins::eOne] -= coinVector[Coins::eOne];
	_vault[Coins::eFive] -= coinVector[Coins::eFive];
	_vault[Coins::eTen] -= coinVector[Coins::eTen];
}

MoneySystem* MoneySystem::GetMoneySystem()
{
	if (_monneySystem == nullptr)
	{
		_monneySystem = new MoneySystem();
		_monneySystem->_returnMoneySystem = ReturnMonneySystem::GetReturnMoneySystem();
	}
	return _monneySystem;
}


