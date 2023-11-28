#ifndef REACTION_H
#define REACTION_H
#include <QString>


class reaction
{
    QString _charge;
    QString _atom;
    int _valency;

public:
    reaction();

    ~reaction();

    reaction(QString charge, QString atom, int valency);

    reaction(reaction&& xClass): _charge(xClass._charge), _atom(xClass._atom), _valency(xClass._valency){
        xClass._charge = xClass._atom = nullptr;
        xClass._valency = 0;
    }

    reaction& operator = (reaction&& xClass);

    auto getCharge(){return _charge;}
    auto getAtom(){return _atom;}
    auto getValency(){return _valency;}
};

#endif // REACTION_H
