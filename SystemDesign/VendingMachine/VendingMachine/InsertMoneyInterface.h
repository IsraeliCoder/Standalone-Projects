#pragma once

enum Coins{eTen= 10, eFive=5, eOne=1};

class InsertMoneyInterface
{
	virtual void insertCoin(Coins coin) = 0;
};
