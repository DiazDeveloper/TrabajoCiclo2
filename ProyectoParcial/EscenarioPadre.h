#pragma once
#include <iostream>
#include <conio.h>

#using <system.drawing.dll>
using namespace std;
using namespace System;
using namespace System::Drawing;

class EscenarioPadre
{

protected:
    int Alto = 50;
    int Ancho = 150;
    int AnchoCuadradosInteriores;
    int AltoCuadradosInteriores;
    int Tiempo = 0;
    int TiempoMilisegundos = 1000;

public:

    EscenarioPadre(int Alto, int Ancho, int AnchoCuadradosInteriores, int AltoCuadradosInteriores)
    {
        this->Alto = Alto;
        this->Ancho = Ancho;
        this->AnchoCuadradosInteriores = AnchoCuadradosInteriores;
        this->AltoCuadradosInteriores = AltoCuadradosInteriores;

    }

    virtual Rectangle DibujarCuadrados(int x, int y)
    {
        return Rectangle(x, y, AnchoCuadradosInteriores, AltoCuadradosInteriores);
    }

    virtual void DibujarZonasDeTepeo(int x, int y)
    {
        Console::SetCursorPosition(x, y);     cout << "******";
        Console::SetCursorPosition(x, y + 1); cout << "******";
        Console::SetCursorPosition(x, y + 2); cout << "******";
    }

    virtual void DibujarAsteriscosDeCuadrado(int posX, int posY, int x, int y)
    {
        for (int i = 0; i < y; i++) {

            Console::SetCursorPosition(posX, posY + i);

            if (i == 0 || i == y - 1) {
                for (int j = 0; j < x; j++) {
                    cout << "* ";
                }
            }

            else {
                cout << "* ";
                for (int j = 0; j < x - 2; j++) {
                    cout << "  ";
                }
                if (x > 1) {
                    cout << "* ";
                }
            }
            cout << endl;
        }
    }

    void DibujarTemporizador(int TiempoRestante)
    {
        Tiempo = TiempoRestante; 
        TiempoMilisegundos = 1000;
        
    }

    void ActualizarTemporizador(int Milisegundos)
    {
        TiempoMilisegundos -= Milisegundos;
        Console::SetCursorPosition(110, 45); 
        cout << "Tiempo restante: " << Tiempo; 
        if (TiempoMilisegundos <= 0)
        {
            Tiempo--;
            TiempoMilisegundos = 1000;
        }

        
    }


    virtual void BorrarEscenario()
    {
        system("cls");
    }

};

