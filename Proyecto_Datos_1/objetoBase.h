
#ifndef OBJETOBASE_H
#define OBJETOBASE_H

#include <iostream>

class objetoBase {
public:
    virtual ~objetoBase();
    static objetoBase* leerData(std::ifstream&);
    virtual bool operator==(const objetoBase&) const;
    virtual std::string toString() const = 0;
};

std::ostream& operator<<(std::ostream&, const objetoBase&);



#endif /* OBJETOBASE_H */


