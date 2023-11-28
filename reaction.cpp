#include "reaction.h"

reaction::reaction(){
    _charge = " ";
    _atom = "H";
    _valency = 1;
}

reaction::~reaction(){
    _charge = _atom = nullptr;
    _valency = 0;
}

reaction::reaction(QString charge, QString atom, int valency){
    _charge = charge;
    _atom = atom;
    _valency = valency;
}

reaction& reaction::operator = (reaction&& xClass){

    _charge = std::move(xClass._charge);
    _atom = std::move(xClass._atom);
    _valency = std::move(xClass._valency);

    xClass._charge = xClass._atom = nullptr;
    xClass._valency = 0;

    return *this;
}
