#pragma once
#include "pch.h"
#include <iostream>
using namespace System;
using namespace std;


class Pantallas
{
public:

	void DibujarPantallaGano()
	{
		Console::Clear();
		Console::SetCursorPosition(150 / 2, 50 / 2); cout << "Ganaste";
	}

	void DibujarPantallaGano()
	{
		Console::Clear();  
		Console::SetCursorPosition(150 / 2, 50 / 2); cout << "Perdiste";
	}
};

