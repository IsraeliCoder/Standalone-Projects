#pragma once

class MoneySystem;

#include "SelectCanInterface.h"

#include <unordered_map>
#include <string>
#include <iostream>

class CanSystem : public SelectCanInterface
{


protected:
	CanSystem(std::unordered_map<CanType, int> canCount, std::unordered_map<CanType, int> canPrice);
	static CanSystem* _canSystem;

public:

	static CanSystem* GetCanSystem(std::unordered_map<CanType, int> canCount, std::unordered_map<CanType, int> canPrice);

	static CanSystem* GetCanSystem()
	{
		return GetCanSystem({}, {});
	}


	virtual void selectCan(CanType canType);

	virtual void showAndUpdatePrice(CanType canType);

	virtual inline void ReduceCan(CanType canType)
	{
		_canCount[canType]--;
	}

protected:

	std::unordered_map<CanType, int> _canCount;
	std::unordered_map<CanType, int> _canPrice;

	MoneySystem* _moneySystem;

};

