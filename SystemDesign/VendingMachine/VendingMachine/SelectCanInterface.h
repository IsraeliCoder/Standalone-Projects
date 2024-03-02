#pragma once

enum CanType {eNone=0, eCola=1, eFanta=2};

class SelectCanInterface
{
	virtual void selectCan(CanType) = 0;
};
