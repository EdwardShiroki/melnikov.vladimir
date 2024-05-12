#ifndef POLYGON_�OMMANDS_H
#define POLYGON_�OMMANDS_H

#include <functional>
#include "Polygon.h"

std::ostream& perms(std::istream& in, std::ostream& out,
    std::vector< Polygon >& polygons);

std::ostream& rightShapes(std::istream& in, std::ostream& out,
    std::vector< Polygon >& polygons);

std::ostream& area(std::istream& in, std::ostream& out,
    std::vector< Polygon >& polygons);

std::ostream& max(std::istream& in, std::ostream& out,
    std::vector< Polygon >& polygons);

std::ostream& min(std::istream& in, std::ostream& out,
    std::vector< Polygon >& polygons);

std::ostream& count(std::istream& in, std::ostream& out,
    std::vector< Polygon >& polygons);



#endif // !POLYGON_�OMMANDS_H
