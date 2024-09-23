#pragma once
#include "EscenarioPadre.h"
#include "EscenarioSpawn.h"

class Escenario3 : public EscenarioPadre
{
public:


    Rectangle ZonaTepeoAbajo;

    Rectangle ZonaLaguna;


    Rectangle ZonaInteractivaRiego1; // 1 =  superior izquierda
    Rectangle ZonaInteractivaRiego2;

    Rectangle ZonaInteractivaRiego3; // 3 = inferior izqueirda
    Rectangle ZonaInteractivaRiego4;

    Rectangle ZonaInteractivaRiego5; // 5 = supeiror derecha
    Rectangle ZonaInteractivaRiego6;

    EscenarioSpawn* escenarioSpawn = new EscenarioSpawn;


    bool TieneAgua = false;

    bool RegoCampo1 = false;
    bool RegoCampo2 = false;
    bool RegoCampo3 = false;
    bool RegoCampo4 = false;
    bool RegoCampo5 = false;
    bool RegoCampo6 = false;

    bool Mundo3Completado = false;

    Escenario3(int anchoCuadrados = 40, int altoCuadrados = 7)
        : EscenarioPadre(altoCuadrados, anchoCuadrados, anchoCuadrados, altoCuadrados)
    {
        Alto = 50;
        Ancho = 150;
        AnchoCuadradosInteriores = anchoCuadrados;
        AltoCuadradosInteriores = altoCuadrados;

        ZonaTepeoAbajo = Rectangle(73, 42, 6, 3); // volver escenariospawn  

        ZonaInteractivaRiego1 = Rectangle(16, 7, 5, 3);  // Rectangle ( x = posicion x, y , largo en x, largo en y)
        ZonaInteractivaRiego2 = Rectangle(36, 7, 5, 3);

        ZonaInteractivaRiego3 = Rectangle(16, 33, 5, 3);
        ZonaInteractivaRiego4 = Rectangle(36, 33, 5, 3);

        ZonaInteractivaRiego5 = Rectangle(110, 7, 5, 3);
        ZonaInteractivaRiego6 = Rectangle(126, 7, 5, 3);

        ZonaLaguna = Rectangle(112, 31, 14, 3);

    }


    void DibujarZonasCambiarEscenario3()
    {
        DibujarZonasDeTepeo(73, 42);
    }

    void MarcarRectangulosInterioresConAsteriscos()
    {
        DibujarAsteriscosDeCuadrado(10, 5, 20, 7);
        DibujarAsteriscosDeCuadrado(100, 5, 20, 7);
        DibujarAsteriscosDeCuadrado(10, 30, 20, 7);
        DibujarAsteriscosDeCuadrado(100, 30, 20, 7);
    }

    void DibujarEscenario3()
    {
        DibujarZonasCambiarEscenario3();
        MarcarRectangulosInterioresConAsteriscos();
        DibujarTemporizador(6);
        DibujarLaguna();
        DibujarZonasRiego();
    }

    bool EnZonaTepeoAbajo(Rectangle personaje) 
    {
        return personaje.IntersectsWith(ZonaTepeoAbajo); 
    }

    void DibujarLaguna() 
    {

        Console::SetCursorPosition(120, 32); cout << "~~~~~~~~~~~~";
        Console::SetCursorPosition(120, 33); cout << "~~~~~~~~~~~~";

    }

    void DibujarZonasRiego()
    {
        Console::SetCursorPosition(16, 8);  cout << "vvv"; // 1
        Console::SetCursorPosition(16, 9);  cout << "vvv";

        Console::SetCursorPosition(38, 8);  cout << "vvv"; // 2
        Console::SetCursorPosition(38, 9);  cout << "vvv";

        Console::SetCursorPosition(16, 33); cout << "vvv"; // 3
        Console::SetCursorPosition(16, 34); cout << "vvv";

        Console::SetCursorPosition(38, 33); cout << "vvv"; // 4
        Console::SetCursorPosition(38, 34); cout << "vvv";

        Console::SetCursorPosition(110, 8); cout << "vvv"; // 5
        Console::SetCursorPosition(110, 9); cout << "vvv";

        Console::SetCursorPosition(128, 8); cout << "vvv"; // 6
        Console::SetCursorPosition(128, 9); cout << "vvv";
    }

    void AccionDeRegar(Rectangle personaje)
    {
        char tecla;

        if (_kbhit())
        {
            tecla = getch();

            if (personaje.IntersectsWith(ZonaLaguna))            //  Verifica si estas cerca del granjero
            {
                TieneAgua = true;                             // obtuviste semillals
                Console::SetCursorPosition(0, 3);
                cout << "Has obtenido agua de la laguna.";
                _sleep(1200);
                Console::SetCursorPosition(0, 3);
                cout << "                               ";
            }


            if (tecla == 'M' && TieneAgua)
            {

                if (personaje.IntersectsWith(ZonaInteractivaRiego1))
                {
                    Console::SetCursorPosition(0, 4);
                    cout << "Regando en la zona 1";                        // mensaje
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                        ";

                    Console::SetCursorPosition(16, 8);  cout << "VVV";       // cambia * por w q parece pasto
                    Console::SetCursorPosition(16, 9);  cout << "VVV";

                    TieneAgua = false;                                  // cambias
                    RegoCampo1 = true;                                    // true xq has sembrado

                }

                else if (personaje.IntersectsWith(ZonaInteractivaRiego2))
                {

                    Console::SetCursorPosition(0, 4);
                    cout << "Regando en la zona 2";
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                        ";

                    Console::SetCursorPosition(38, 8);  cout << "VVV";
                    Console::SetCursorPosition(38, 9);  cout << "VVV";

                    TieneAgua = false;
                    RegoCampo2 = true;
                }

                else if (personaje.IntersectsWith(ZonaInteractivaRiego3))
                {

                    Console::SetCursorPosition(0, 4);
                    cout << "Regando en la zona 3";
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                        ";

                    Console::SetCursorPosition(16, 33);  cout << "VVV";
                    Console::SetCursorPosition(16, 34);  cout << "VVV";

                    TieneAgua = false;
                    RegoCampo3 = true;

                }

                else if (personaje.IntersectsWith(ZonaInteractivaRiego4))
                {

                    Console::SetCursorPosition(0, 4);
                    cout << "Regando en la zona 4";
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                        ";

                    Console::SetCursorPosition(38, 33);  cout << "VVV";
                    Console::SetCursorPosition(38, 34);  cout << "VVV";

                    TieneAgua = false;
                    RegoCampo4 = true;

                }

                else if (personaje.IntersectsWith(ZonaInteractivaRiego5))
                {

                    Console::SetCursorPosition(0, 4);
                    cout << "Regando en la zona 5";
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                        ";

                    Console::SetCursorPosition(110, 8);  cout << "VVV";
                    Console::SetCursorPosition(110, 9);  cout << "VVV";

                    TieneAgua = false;
                    RegoCampo5 = true;

                }

                else if (personaje.IntersectsWith(ZonaInteractivaRiego6))
                {

                    Console::SetCursorPosition(0, 4);
                    cout << "Regando en la zona 6";
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                        ";
                     
                    Console::SetCursorPosition(128, 8);  cout << "VVV";
                    Console::SetCursorPosition(128, 9);  cout << "VVV";

                    TieneAgua = false;
                    RegoCampo6 = true;

                }

                if (RegoCampo1 && RegoCampo2 && RegoCampo3 && RegoCampo4 && RegoCampo5 && RegoCampo6)
                {

                    Console::SetCursorPosition(0, 4);
                    cout << "COMPLETASTE EL MUNDO 3. Todos los campos han sido regados.";
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                                                            ";

                    Mundo3Completado = true;

                }





            }
        }
    }

    bool getCompletoMundo3()
    {
        return Mundo3Completado;
    }

};

