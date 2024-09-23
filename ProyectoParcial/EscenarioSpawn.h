#pragma once
#include "EscenarioPadre.h"


class EscenarioSpawn : public EscenarioPadre
{
public:

    Rectangle rectanguloSuperiorIzquierdo;
    Rectangle rectanguloSuperiorDerecho;
    Rectangle rectanguloInferiorIzquierdo;
    Rectangle rectanguloInferiorDerecho;

    Rectangle ZonaTepeoIzquierda;
    Rectangle ZonaTepeoArriba;
    Rectangle ZonaTepeoDerecha;

    EscenarioSpawn(int anchoCuadrados = 40, int altoCuadrados = 7)
        : EscenarioPadre(altoCuadrados, anchoCuadrados, anchoCuadrados, altoCuadrados)
    {
        Alto = 50;
        Ancho = 150;
        AnchoCuadradosInteriores = anchoCuadrados;
        AltoCuadradosInteriores = altoCuadrados;

        rectanguloSuperiorIzquierdo = DibujarCuadrados(10, 5);
        rectanguloSuperiorDerecho = DibujarCuadrados(100, 5);
        rectanguloInferiorIzquierdo = DibujarCuadrados(10, 30);
        rectanguloInferiorDerecho = DibujarCuadrados(100, 30);

        ZonaTepeoIzquierda = Rectangle(13, 20, 6, 3);
        ZonaTepeoArriba = Rectangle(73, 5, 6, 3);
        ZonaTepeoDerecha = Rectangle(132, 20, 6, 3);
    }


    void DibujarZonasParaCambiarEscenario()
    {
        DibujarZonasDeTepeo(13, 20);
        DibujarZonasDeTepeo(73, 5);
        DibujarZonasDeTepeo(132, 20);

    }

    void DibujarAsteriscosMarcadores()
    {
        DibujarAsteriscosDeCuadrado(10, 5, AnchoCuadradosInteriores / 2, AltoCuadradosInteriores);
        DibujarAsteriscosDeCuadrado(100, 5, AnchoCuadradosInteriores / 2, AltoCuadradosInteriores);
        DibujarAsteriscosDeCuadrado(10, 30, AnchoCuadradosInteriores / 2, AltoCuadradosInteriores);
        DibujarAsteriscosDeCuadrado(100, 30, AnchoCuadradosInteriores / 2, AltoCuadradosInteriores);
    }

    void IniciarSpawn()
    {
        Console::SetWindowSize(Ancho, Alto);
        DibujarZonasParaCambiarEscenario();
        DibujarAsteriscosMarcadores();

    }

    bool VerificarColisionConCuadradosInteriores(Rectangle personaje) {

        if (personaje.IntersectsWith(rectanguloSuperiorIzquierdo) ||
            personaje.IntersectsWith(rectanguloSuperiorDerecho) ||
            personaje.IntersectsWith(rectanguloInferiorIzquierdo) ||
            personaje.IntersectsWith(rectanguloInferiorDerecho)) {
            return true;
        }
        return false;
    }

    bool EnZonaTepeoIzquierda(Rectangle personaje)
    {
        return personaje.IntersectsWith(ZonaTepeoIzquierda);
    }

    bool EnZonaTepeoArriba(Rectangle personaje)
    {
        return personaje.IntersectsWith(ZonaTepeoArriba);
    }

    bool EnZonaTepeoDerecha(Rectangle personaje)
    {
        return personaje.IntersectsWith(ZonaTepeoDerecha);
    }

};
