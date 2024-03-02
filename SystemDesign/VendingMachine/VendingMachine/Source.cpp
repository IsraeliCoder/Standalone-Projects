
#include "CanSystem.h"
#include "MoneySystem.h"
#include "ReturnMonneySystem.h"

void main()
{
	
	CanSystem* canSystem = CanSystem::GetCanSystem({ { eCola, 100 }, {eFanta, 10} }, 
		{ {eCola, 5}, {eFanta, 7} });
	MoneySystem* moneySystem = MoneySystem::GetMoneySystem();
	ReturnMonneySystem* returnMoney = ReturnMonneySystem::GetReturnMoneySystem();

	canSystem->selectCan(eFanta);
	moneySystem->insertCoin(eTen);

	std::cout << "Finished" << std::endl;

}