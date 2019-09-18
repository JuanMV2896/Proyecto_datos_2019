
#include "objetoBase.h"
using namespace std;



    objetoBase::~objetoBase() {
    }
    objetoBase* objetoBase::leerData(std::ifstream&){
        return NULL;
    }
    bool objetoBase::operator==(const objetoBase &obj) const {
        return this == &obj;
    }

    ostream& operator<<(ostream &salida, const objetoBase &obj) {
        salida << obj.toString();
        return salida;
    }

