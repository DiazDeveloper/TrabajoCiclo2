#pragma once
#include "EntidadPadre.h"
#include "EscenarioSpawn.h"
#include "Escenario1.h"
#include "Escenario2.h"
#include "Escenario3.h"


class PersonajePrincipal : public EntidadPadre

{
public:

	EscenarioSpawn* Spawn = new EscenarioSpawn;
	Escenario1* escenario1 = new Escenario1;
	Escenario2* escenario2 = new Escenario2;
	Escenario3* escenario3 = new Escenario3; 


	Rectangle HitBoxPersonajePrincipal;

	bool enSpawn = true;
	bool enEscenario1 = false;
	bool enEscenario2 = false;
	bool enEscenario3 = false;


	int vidas = 3;
	int MundosCompletados = 0; 

	PersonajePrincipal() :EntidadPadre()
	{
		AltoPersonaje = 2;
		AnchoPersonaje = 4;
		Dx = 2;
		Dy = 2;
		PosicionX = (ANCHO - AnchoPersonaje) / 2; 
		PosicionY = (ALTO - AltoPersonaje) / 2;
		
		HitBoxPersonajePrincipal = Rectangle (PosicionX, PosicionY, AnchoPersonaje, AltoPersonaje);

	}


	void dibujarPersonaje()
	{
		Console::SetCursorPosition(PosicionX, PosicionY);      cout << "-**-";
		Console::SetCursorPosition(PosicionX, PosicionY + 1);  cout << " || ";

	}


	bool EsMovimientoValido(int nuevoX, int nuevoY)
	{
		if (nuevoX >= Console::WindowLeft && nuevoX + AnchoPersonaje <= Console::WindowWidth &&
			nuevoY >= Console::WindowTop && nuevoY + AltoPersonaje <= Console::WindowHeight)
		{
			Rectangle nuevoHitbox = Rectangle(nuevoX, nuevoY, AnchoPersonaje, AltoPersonaje);

			if (enEscenario1) {
				return true;
			}
			else if (enEscenario2) {
				return true;
			}
			else if (enEscenario3) {
				return true;
			}
			else if (enSpawn) {
				return !Spawn->VerificarColisionConCuadradosInteriores(nuevoHitbox);
			}
		}
		return false;
	}

	void MoverPersonaje()

		/*
		AQUI ADRIAAAN 
		DSDSD
		DSDS
		*/
	{
		char tecla;
		if (_kbhit()) {
			tecla = toupper(getch());

			if (tecla == 'W' && EsMovimientoValido(PosicionX,PosicionY - Dy)) {
				PosicionY -= Dy;  
			}

			if (tecla == 'S' && EsMovimientoValido(PosicionX, PosicionY + Dy)) {
				PosicionY += Dy;
			}

			if (tecla == 'A' && EsMovimientoValido(PosicionX - Dx, PosicionY)) {
				PosicionX -= Dx;   
			}

			if (tecla == 'D' && EsMovimientoValido(PosicionX + Dx, PosicionY)) {
				PosicionX += Dx; 
			}

			HitBoxPersonajePrincipal.X = PosicionX;
			HitBoxPersonajePrincipal.Y = PosicionY;

			VerificarTepeo(tecla);
			if (enEscenario1)
			{
				escenario1->AccionDeCultivar(HitBoxPersonajePrincipal);  
			}

			if (enEscenario2)
			{
				escenario2->AccionDeQuitarBasura(HitBoxPersonajePrincipal);
			}
			
			if (enEscenario3)
			{
				escenario3->AccionDeRegar(HitBoxPersonajePrincipal);   
			}

		}
	}

	void InicializarPersonaje()
	{
		while (true)
		{
			Console::CursorVisible = false ;
			borrar();
			MoverPersonaje();
			dibujarPersonaje();
			_sleep(100);
			DibujarHUD();

			if (!enSpawn)
			{
				if (enEscenario1)
				{
					escenario1->ActualizarTemporizador(100);
					
				}

				else if (enEscenario2)
				{
					escenario2->ActualizarTemporizador(100);
				}

				else if (enEscenario3)
				{
					escenario3->ActualizarTemporizador(100);   
				}
			}
			
		}


	}



    void VerificarTepeo(char tecla)
    {
        if (toupper(tecla) == 'M') {

            // Si estamos en el Spawn
            if (enSpawn) {
                if (Spawn->EnZonaTepeoIzquierda(HitBoxPersonajePrincipal)) {
                    system("cls");
                    cout << "Bienvenido al escenario 1";
                    enSpawn = false;
                    enEscenario1 = true;  // Cambiamos al escenario 1
                    escenario1->DibujarEscenario1();
                    PosicionX = (ANCHO - AnchoPersonaje) / 2;
                    PosicionY = (ALTO - AltoPersonaje) / 2;
                }

				else if (Spawn->EnZonaTepeoDerecha(HitBoxPersonajePrincipal)) {
					system("cls");
					cout << "Estas en escenario 2";
					enSpawn = false;
					enEscenario2 = true;
					escenario2->DibujarEscenario2();
					PosicionX = (ANCHO - AnchoPersonaje) / 2;
					PosicionY = (ALTO - AltoPersonaje) / 2; 
				}

				else if (Spawn->EnZonaTepeoArriba(HitBoxPersonajePrincipal)) {
					system("cls");
					cout << "Estas en escenario 3";
					enSpawn = false;
					enEscenario3 = true;
					escenario3->DibujarEscenario3();
					PosicionX = (ANCHO - AnchoPersonaje) / 2;  
					PosicionY = (ALTO - AltoPersonaje) / 2;   
				}
            }

            // Si estamos en el Escenario 1

			else if (enEscenario1) {  
				if (escenario1->EnZonaTepeoDerecha(HitBoxPersonajePrincipal)) {  
					system("cls"); 
					cout << "Volviste al spawn";
					enEscenario1 = false;
					enSpawn = true;  // Regresamos al Spawn 
					Spawn->IniciarSpawn();
					PosicionX = (ANCHO - AnchoPersonaje) / 2;
					PosicionY = (ALTO - AltoPersonaje) / 2;
				}
			}

			// Si estamos en el Escenario 2

			else if (enEscenario2) {

				if (escenario2->EnZonaTepeoIzquierda(HitBoxPersonajePrincipal)) {
					system("cls"); 
					cout << "Volviste al spawn";
					enEscenario2 = false; 
					enSpawn = true;
					Spawn->IniciarSpawn();
					PosicionX = (ANCHO - AnchoPersonaje) / 2;  
					PosicionY = (ALTO - AltoPersonaje) / 2; 
					
				}

			}

			// Si estamos en el Escenario 3

			else if (enEscenario3) {
				if (escenario3->EnZonaTepeoAbajo(HitBoxPersonajePrincipal))
				{
					system("cls");
					cout << "Volviste al spawn";
					enEscenario3 = false;
					enSpawn = true;
					Spawn->IniciarSpawn();
					PosicionX = (ANCHO - AnchoPersonaje) / 2; 
					PosicionY = (ALTO - AltoPersonaje) / 2; 
				}
			}

        }
    }

	void DibujarHUD()
	{
		Console::SetCursorPosition(0, 1);  cout << "Vidas: " << vidas;  
		Console::SetCursorPosition(20, 1); cout << "Misiones completadas: " << AniadirMisionesCompletadas();
	}

	int AniadirMisionesCompletadas()
	{
		int mundosCompletos = 0;
		if (GetMundo1Completado()) mundosCompletos++;
		if (GetMundo2Completado()) mundosCompletos++;
		if (GetMundo3Completado()) mundosCompletos++; 

		return mundosCompletos; 
	}

	bool GetMundo1Completado()  
	{
		return escenario1->getCompletoMundo1(); 
	}

	bool GetMundo2Completado()
	{
		return escenario2->getCompletoMundo2();   
	}

	bool GetMundo3Completado()
	{
		return escenario3->getCompletoMundo3();  
	}

};

