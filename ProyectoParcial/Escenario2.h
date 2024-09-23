#pragma once
#include "EscenarioPadre.h"
#include "EscenarioSpawn.h"

class Escenario2 : public EscenarioPadre
{
public:

    Rectangle ZonaTepeoIzquierda;

    Rectangle TachoBasura; 

    Rectangle ZonaInteractivaBasura1; // 1 =  superior izquierda
    Rectangle ZonaInteractivaBasura2;

    Rectangle ZonaInteractivaBasura3; // 3 = inferior izqueirda
    Rectangle ZonaInteractivaBasura4;

    Rectangle ZonaInteractivaBasura5; // 5 = supeiror derecha
    Rectangle ZonaInteractivaBasura6;

    bool TieneBasura = false;

    bool QuitoBasura1 = false;
    bool QuitoBasura2 = false;
    bool QuitoBasura3 = false;
    bool QuitoBasura4 = false;
    bool QuitoBasura5 = false;
    bool QuitoBasura6 = false;

    bool Mundo2completado = false;


    EscenarioSpawn* escenarioSpawn = new EscenarioSpawn;


    Escenario2(int anchoCuadrados = 40, int altoCuadrados = 7)
        : EscenarioPadre(altoCuadrados, anchoCuadrados, anchoCuadrados, altoCuadrados)
    {
        Alto = 50;
        Ancho = 150;
        AnchoCuadradosInteriores = anchoCuadrados;
        AltoCuadradosInteriores = altoCuadrados;

        ZonaTepeoIzquierda = Rectangle(13, 20, 6, 3); // volver escenariospawn

        ZonaInteractivaBasura1 = Rectangle(16, 7, 5, 3);  // Rectangle ( x = posicion x, y , largo en x, largo en y)
        ZonaInteractivaBasura2 = Rectangle(36, 7, 5, 3);

        ZonaInteractivaBasura3 = Rectangle(16, 33, 5, 3);
        ZonaInteractivaBasura4 = Rectangle(36, 33, 5, 3);

        ZonaInteractivaBasura5 = Rectangle(110, 7, 5, 3);
        ZonaInteractivaBasura6 = Rectangle(126, 7, 5, 3);

        TachoBasura = Rectangle(112, 31, 14, 3);  
    }


    void DibujarZonasCambiarEscenario2()
    {
        DibujarZonasDeTepeo(13, 20);
    }

    void MarcarRectangulosInterioresConAsteriscos()
    {
        DibujarAsteriscosDeCuadrado(10, 5, 20, 7);
        DibujarAsteriscosDeCuadrado(100, 5, 20, 7);
        DibujarAsteriscosDeCuadrado(10, 30, 20, 7);
        DibujarAsteriscosDeCuadrado(100, 30, 20, 7);
    }

    void DibujarEscenario2()
    {
        DibujarZonasCambiarEscenario2();
        MarcarRectangulosInterioresConAsteriscos();
        DibujarTachoBasura();
        DibujarZonasBasura();
        DibujarTemporizador(6);
    }



    bool EnZonaTepeoIzquierda(Rectangle personaje)
    {
        return personaje.IntersectsWith(ZonaTepeoIzquierda);   
    }

    void DibujarTachoBasura()
    {

        Console::SetCursorPosition(120, 32); cout << "\\  _____  /";
        Console::SetCursorPosition(120, 33); cout << " \\_______/ ";

    }
    
    void DibujarZonasBasura()
    {
        Console::SetCursorPosition(16, 8);  cout << "XXX"; // 1
        Console::SetCursorPosition(16, 9);  cout << "XXX";

        Console::SetCursorPosition(38, 8);  cout << "XXX"; // 2
        Console::SetCursorPosition(38, 9);  cout << "XXX";

        Console::SetCursorPosition(16, 33); cout << "XXX"; // 3
        Console::SetCursorPosition(16, 34); cout << "XXX";

        Console::SetCursorPosition(38, 33); cout << "XXX"; // 4
        Console::SetCursorPosition(38, 34); cout << "XXX";

        Console::SetCursorPosition(110, 8); cout << "XXX"; // 5
        Console::SetCursorPosition(110, 9); cout << "XXX";

        Console::SetCursorPosition(128, 8); cout << "XXX"; // 6
        Console::SetCursorPosition(128, 9); cout << "XXX";

    }


    void AccionDeQuitarBasura(Rectangle personaje)
    {
        char tecla;

        if (_kbhit())
        {
            tecla = getch();

            if (personaje.IntersectsWith(TachoBasura) && TieneBasura)        
            {                           
                Console::SetCursorPosition(0, 3);
                cout << "Depositando basura en el tacho, buen trabajo";
                _sleep(1200);
                Console::SetCursorPosition(0, 3);
                cout << "                                            ";
                TieneBasura = false;
            }


            if (tecla == 'M' && !TieneBasura)
            {

                if (personaje.IntersectsWith(ZonaInteractivaBasura1))
                {
                    Console::SetCursorPosition(0, 4);
                    cout << "Quitando basura en la zona 1";                       
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                             ";

                    Console::SetCursorPosition(16, 8);  cout << "www";       
                    Console::SetCursorPosition(16, 9);  cout << "www";

                    TieneBasura = true;                               
                    QuitoBasura1 = true;                                   

                }

                else if (personaje.IntersectsWith(ZonaInteractivaBasura2))
                {

                    Console::SetCursorPosition(0, 4);
                    cout << "Quitando basura en la zona 2";
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                             ";

                    Console::SetCursorPosition(38, 8);  cout << "www";
                    Console::SetCursorPosition(38, 9);  cout << "www";

                    TieneBasura = true;
                    QuitoBasura2 = true;
                }

                else if (personaje.IntersectsWith(ZonaInteractivaBasura3))
                {

                    Console::SetCursorPosition(0, 4);
                    cout << "Quitando basura en la zona 3";
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                             ";

                    Console::SetCursorPosition(16, 33);  cout << "www";
                    Console::SetCursorPosition(16, 34);  cout << "www";

                    TieneBasura = true;
                    QuitoBasura3 = true;

                }

                else if (personaje.IntersectsWith(ZonaInteractivaBasura4))
                {

                    Console::SetCursorPosition(0, 4);
                    cout << "Quitando basura en la zona 4";
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                             ";

                    Console::SetCursorPosition(38, 33);  cout << "www";
                    Console::SetCursorPosition(38, 34);  cout << "www";

                    TieneBasura = true;
                    QuitoBasura4 = true;

                }

                else if (personaje.IntersectsWith(ZonaInteractivaBasura5))
                {

                    Console::SetCursorPosition(0, 4);
                    cout << "Quitando basura en la zona 5";
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                             ";

                    Console::SetCursorPosition(110, 8);  cout << "www";
                    Console::SetCursorPosition(110, 9);  cout << "www";

                    TieneBasura = true;
                    QuitoBasura5 = true;

                }

                else if (personaje.IntersectsWith(ZonaInteractivaBasura6))
                {

                    Console::SetCursorPosition(0, 4);
                    cout << "Quitando basura en la zona 6";
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                             ";

                    Console::SetCursorPosition(128, 8);  cout << "www";
                    Console::SetCursorPosition(128, 9);  cout << "www";

                    TieneBasura = true;
                    QuitoBasura6 = true;

                }

                if (QuitoBasura1 && QuitoBasura2 && QuitoBasura3 && QuitoBasura4 && QuitoBasura5 && QuitoBasura6)
                {

                    Console::SetCursorPosition(0, 4);
                    cout << "COMPLETASTE EL MUNDO 2. Ningun campo ahora tiene basura.";
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                                                        ";

                    Mundo2completado = true;

                }

            }
        }
    }

    bool getCompletoMundo2()
    {
        return Mundo2completado;
    }

};

