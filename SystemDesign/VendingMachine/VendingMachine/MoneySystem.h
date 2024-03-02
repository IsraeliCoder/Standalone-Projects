#pragma once

class ReturnMonneySystem;

#include "InsertMoneyInterface.h"
#include "SelectCanInterface.h"

#include <unordered_map>

class MoneySystem : public InsertMoneyInterface
{

public:

	virtual void changeTargetPrice(int price, CanType canType);
	virtual void insertCoin(Coins coin);

	virtual void checkIfGiveACan();
	virtual std::unordered_map<Coins, int> getChange();

	virtual void reduceCoinVector(std::unordered_map<Coins, int> coinVector);

	static MoneySystem* GetMoneySystem();



protected:

	static MoneySystem* _monneySystem;
	std::unordered_map<Coins, int> _vault;

	int _monneyCollected;
	int _price;
	CanType _canType;

	ReturnMonneySystem* _returnMoneySystem;

	MoneySystem();

};

