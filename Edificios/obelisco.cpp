#include "obelisco.h"


// ------------------------------------------------------------------------------------------------------------


Obelisco::Obelisco(char identificador, Jugador_t creador): Edificio(identificador, creador){}

// ------------------------------------------------------------------------------------------------------------


string Obelisco::obtener_tipo_edificio(){
    
    return STR_OBELISCO;
    
}
