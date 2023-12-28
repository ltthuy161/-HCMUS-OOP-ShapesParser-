#pragma once
#include <sstream>

#include "Shape.h"
#include "Hexagon.h"
#include "ShapeToStringConvert.h"

using std::stringstream;


class HexagonToStringConvert : public ShapeToStringConvert {
public:
    HexagonToStringConvert() = default;
public:
    string convertData(shared_ptr<Shape>) override;
    string convertDataCalculated(shared_ptr<Shape>) override;
};

