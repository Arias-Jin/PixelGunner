#pragma once
#include "CFramework.h"

class CGame : public CFramework
{
public:
	CGame();
	~CGame();

public:
	virtual void OnInit();
	virtual void OnRender();
	virtual void OnUpdate();
	virtual void OnRelease();
};