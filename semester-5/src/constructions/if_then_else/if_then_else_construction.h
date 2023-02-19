#ifndef IF_THEN_ELSE_CONSTRUCTION_H
#define IF_THEN_ELSE_CONSTRUCTION_H

#include "../base_construction.h"
#include "../../actions/if_then_else_action.h"

using namespace std;

template<class T>
class IfThenElseConstruction : public BaseConstruction<T> {
protected:
    IfThenElseAction<T>* action;
};

#endif