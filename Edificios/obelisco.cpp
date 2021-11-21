#include "obelisco.h"


// ------------------------------------------------------------------------------------------------------------


Obelisco::Obelisco(char identificador, char creador): Edificio(identificador, creador){}

// ------------------------------------------------------------------------------------------------------------


string Obelisco::obtener_tipo_edificio(){
    
    return STR_OBELISCO;
}
