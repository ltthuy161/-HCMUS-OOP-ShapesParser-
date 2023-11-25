#include "ParserFactory.h"
#include "CircleParser.h"
#include "RectangleParser.h"
#include "SquareParser.h"

ParserFactory::ParserFactory() {
    _prototype = {
        {"Circle", make_shared<CircleParser>()},
        {"Rectangle", make_shared<RectangleParser>()},
        {"Square", make_shared<SquareParser>()},
    };
}

shared_ptr<Parser> ParserFactory::select(string type) {
    shared_ptr<Parser> parser = 0;

    if (_prototype.contains(type))
    {
        parser = _prototype[type];
    }

    return parser;
}

const unique_ptr<ParserFactory>& ParserFactory::getInstance() {
    if (_instance == 0) {
        _instance = std::unique_ptr<ParserFactory>(new ParserFactory);
    }
    return _instance;
}