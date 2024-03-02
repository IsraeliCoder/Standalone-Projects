#pragma once

class CanSystem;
class MoneySystem;

#include "InsertMoneyInterface.h"
#include "ReturnMoneyInterface.h"
#include "SelectCanInterface.h"

#include <unordered_map>

class ReturnMonneySystem : public ReturnMoneyInterface
{
public:

	static ReturnMonneySystem* GetReturnMoneySystem();

	virtual void returnMoney();

	virtual void CoinRealReturn(std::unordered_map<Coins, int> returnCoinVector);

	virtual void giveCan(CanType canType);

protected:

	static ReturnMonneySystem* _returnMonneySystem;

	ReturnMonneySystem();

	CanSystem* _canSystem;
	MoneySystem* _moneySystem;

};

