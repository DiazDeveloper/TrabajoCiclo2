#pragma once
#include "EscenarioPadre.h"
#include "EscenarioSpawn.h"

class Escenario1 : public EscenarioPadre
{
 public:



    Rectangle ZonaTepeoDerecha;

    Rectangle NPCGranjero;
    //Rectangle ZonaInteractivaGranjero;

    Rectangle ZonaInteractivaCultivo1; // 1 =  superior izquierda
    Rectangle ZonaInteractivaCultivo2;

    Rectangle ZonaInteractivaCultivo3; // 3 = inferior izqueirda
    Rectangle ZonaInteractivaCultivo4;

    Rectangle ZonaInteractivaCultivo5; // 5 = supeiror derecha
    Rectangle ZonaInteractivaCultivo6;


    bool TieneSemillas = false;

    bool SembroCampo1 = false;
    bool SembroCampo2 = false;
    bool SembroCampo3 = false;
    bool SembroCampo4 = false;
    bool SembroCampo5 = false;
    bool SembroCampo6 = false;

    bool Mundo1completado = false;

    EscenarioSpawn* escenarioSpawn = new EscenarioSpawn;

    Escenario1(int anchoCuadrados = 40, int altoCuadrados = 7)
        : EscenarioPadre(altoCuadrados, anchoCuadrados, anchoCuadrados, altoCuadrados)
    {
        Alto = 50;
        Ancho = 150;
        AnchoCuadradosInteriores = anchoCuadrados;
        AltoCuadradosInteriores = altoCuadrados;

        ZonaTepeoDerecha = Rectangle(132, 20, 6, 3); // volver escenariospawn

        ZonaInteractivaCultivo1 = Rectangle(16, 7, 5, 3);  // Rectangle ( x = posicion x, y , largo en x, largo en y)
        ZonaInteractivaCultivo2 = Rectangle(36, 7, 5, 3);

        ZonaInteractivaCultivo3 = Rectangle(16, 33, 5, 3);
        ZonaInteractivaCultivo4 = Rectangle(36, 33, 5, 3);

        ZonaInteractivaCultivo5 = Rectangle(110, 7, 5, 3);
        ZonaInteractivaCultivo6 = Rectangle(126, 7, 5, 3); 

        NPCGranjero = Rectangle(112, 31, 14, 3); 

    }


    void DibujarZonasCambiarEscenario1()
    {
        DibujarZonasDeTepeo(132, 20);
    }

    void MarcarRectangulosInterioresConAsteriscos()
    {
        DibujarAsteriscosDeCuadrado(10, 5, 20, 7);
        DibujarAsteriscosDeCuadrado(100, 5, 20, 7);
        DibujarAsteriscosDeCuadrado(10, 30, 20, 7);
        DibujarAsteriscosDeCuadrado(100, 30, 20, 7);
    }

    void DibujarEscenario1()
    {
        DibujarZonasCambiarEscenario1();
        MarcarRectangulosInterioresConAsteriscos();
        DibujarNPCgranjero(); 
        DibujarZonasPlantar();
        DibujarTemporizador(9); 
    }

    bool EnZonaTepeoDerecha(Rectangle personaje)
    {
        return personaje.IntersectsWith(ZonaTepeoDerecha);
    }

    void DibujarNPCgranjero()
    {

        Console::SetCursorPosition(120, 32); cout << "\\( * _ * )/";
        Console::SetCursorPosition(120, 33); cout << "   |   |    ";

    }

    void DibujarZonasPlantar()
    {
        Console::SetCursorPosition(16, 8);  cout << "***"; // 1
        Console::SetCursorPosition(16, 9);  cout << "***";

        Console::SetCursorPosition(38, 8);  cout << "***"; // 2
        Console::SetCursorPosition(38, 9);  cout << "***";

        Console::SetCursorPosition(16, 33); cout << "***"; // 3
        Console::SetCursorPosition(16, 34); cout << "***";

        Console::SetCursorPosition(38, 33); cout << "***"; // 4
        Console::SetCursorPosition(38, 34); cout << "***";

        Console::SetCursorPosition(110, 8); cout << "***"; // 5
        Console::SetCursorPosition(110, 9); cout << "***"; 

        Console::SetCursorPosition(128, 8); cout << "***"; // 6
        Console::SetCursorPosition(128, 9); cout << "***";

    }

   
    void AccionDeCultivar(Rectangle personaje)
    {
        char tecla;

        if (_kbhit())
        {
            tecla = getch();

            if (personaje.IntersectsWith(NPCGranjero))            //  Verifica si estas cerca del granjero
            {
                TieneSemillas = true;                             // obtuviste semillals
                Console::SetCursorPosition(0, 3);
                cout << "Has obtenido semillas del granjero.";   
                _sleep(1200);
                Console::SetCursorPosition(0, 3);   
                cout << "                                   ";
            }


            if (tecla == 'M' && TieneSemillas)
            {

                if (personaje.IntersectsWith(ZonaInteractivaCultivo1))
                {
                    Console::SetCursorPosition(0, 4);
                    cout << "Sembrando en la zona 1";                        // mensaje
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                      ";  

                    Console::SetCursorPosition(16, 8);  cout << "www";       // cambia * por w q parece pasto
                    Console::SetCursorPosition(16, 9);  cout << "www"; 

                    TieneSemillas = false;                                  // cambias
                    SembroCampo1 = true;                                    // true xq has sembrado

                }

                else if (personaje.IntersectsWith(ZonaInteractivaCultivo2))
                {
                   
                    Console::SetCursorPosition(0, 4); 
                    cout << "Sembrando en la zona 2"; 
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4); 
                    cout << "                      "; 

                    Console::SetCursorPosition(38, 8);  cout << "www"; 
                    Console::SetCursorPosition(38, 9);  cout << "www"; 

                    TieneSemillas = false;
                    SembroCampo2 = true;
                }

                else if (personaje.IntersectsWith(ZonaInteractivaCultivo3))
                {
                  
                    Console::SetCursorPosition(0, 4); 
                    cout << "Sembrando en la zona 3"; 
                    _sleep(1200); 
                    Console::SetCursorPosition(0, 4);  
                    cout << "                      "; 

                    Console::SetCursorPosition(16, 33);  cout << "www"; 
                    Console::SetCursorPosition(16, 34);  cout << "www"; 

                    TieneSemillas = false;
                    SembroCampo3 = true; 

                }

                else if (personaje.IntersectsWith(ZonaInteractivaCultivo4))
                {
                   
                    Console::SetCursorPosition(0, 4);  
                    cout << "Sembrando en la zona 4"; 
                    _sleep(1200); 
                    Console::SetCursorPosition(0, 4); 
                    cout << "                      "; 

                    Console::SetCursorPosition(38, 33);  cout << "www"; 
                    Console::SetCursorPosition(38, 34);  cout << "www"; 

                    TieneSemillas = false;
                    SembroCampo4 = true;

                }

                else if (personaje.IntersectsWith(ZonaInteractivaCultivo5))
                {
                  
                    Console::SetCursorPosition(0, 4); 
                    cout << "Sembrando en la zona 5"; 
                    _sleep(1200); 
                    Console::SetCursorPosition(0, 4); 
                    cout << "                      "; 

                    Console::SetCursorPosition(110, 8);  cout << "www"; 
                    Console::SetCursorPosition(110, 9);  cout << "www"; 

                    TieneSemillas = false; 
                    SembroCampo5 = true;

                } 

                else if (personaje.IntersectsWith(ZonaInteractivaCultivo6))
                {
                
                    Console::SetCursorPosition(0, 4); 
                    cout << "Sembrando en la zona 6"; 
                    _sleep(1200); 
                    Console::SetCursorPosition(0, 4); 
                    cout << "                      "; 

                    Console::SetCursorPosition(128, 8);  cout << "www"; 
                    Console::SetCursorPosition(128, 9);  cout << "www"; 

                    TieneSemillas = false; 
                    SembroCampo6 = true;

                }

                if (SembroCampo1 && SembroCampo2 && SembroCampo3 && SembroCampo4 && SembroCampo5 && SembroCampo6)  
                { 

                    Console::SetCursorPosition(0, 4); 
                    cout << "COMPLETASTE EL MUNDO 1. Todos los campos han sido sembrados."; 
                    _sleep(1200);
                    Console::SetCursorPosition(0, 4);
                    cout << "                                                            ";

                    Mundo1completado = true;                                                           

                }
            }
        }
    }

    bool getCompletoMundo1()
    {
        return Mundo1completado; 
    }

};

