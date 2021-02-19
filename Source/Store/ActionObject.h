#pragma once

#include "JuceHeader.h"

const Identifier Args("ARGS");

class ActionObject {
public:
    explicit ActionObject(Identifier type) : type(std::move(type)) {}
    explicit ActionObject(Identifier type, ValueTree args) : type(std::move(type)), args(std::move(args)) {}

    ~ActionObject() {}
       
    Identifier type;
    ValueTree args;
};
