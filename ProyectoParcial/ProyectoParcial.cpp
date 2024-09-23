#include "pch.h"
#include "EscenarioSpawn.h"
#include "PersonajePrincipal.h"


using namespace std;
using namespace System;

int main()
{
    
    PersonajePrincipal* personaje = new PersonajePrincipal;
    EscenarioSpawn* Escenario = new EscenarioSpawn;

    Escenario->IniciarSpawn(); 


    while (true) 
    {
        personaje->InicializarPersonaje();
    }
}
