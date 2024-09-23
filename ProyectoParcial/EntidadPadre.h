#pragma once
#include "EscenarioSpawn.h"

#define ALTO 50
#define ANCHO 150

class EntidadPadre
{
protected:
	int PosicionX, PosicionY, AnchoPersonaje, AltoPersonaje, Dx, Dy;  
	Rectangle RectanguloPersonaje;

public:
	EntidadPadre()
	{
		Dx = Dy = 1;
	}

	virtual void dibujar() {}

	void borrar()
	{
		for (int i = 0; i < AltoPersonaje; i++)
		{
			for (int j = 0; j < AnchoPersonaje; j++)
			{
				Console::SetCursorPosition(PosicionX + j, PosicionY + i); 
				cout << " ";
			}
		}
	}

	virtual void Mover(){}

	Rectangle GenerarHitBoxPersonaje()
	{
		return Rectangle(PosicionX, PosicionY, AnchoPersonaje, AltoPersonaje);
	}

	int getPosicionX()
	{
		return PosicionX;
	}

	int getPosicionY()
	{
		return PosicionY;
	}

};

