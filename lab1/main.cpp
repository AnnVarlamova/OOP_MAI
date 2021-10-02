#include "figure.h"
#include "octagon.h"
#include "triangle.h"
#include "square.h"

int main()
{
    std::cout << "Enter triangle (points):\n";
    Triangle trngl(std::cin);
    trngl.Print(std::cout);
    std::cout << "The number of vertexes: " << trngl.VertexesNumber() << "\n";
    std::cout << "Area: " << trngl.Area() << "\n\n";

    std::cout << "Enter square (points):\n";
    Square sqr(std::cin);
    sqr.Print(std::cout);
    std::cout << "The number of vertexes: " << sqr.VertexesNumber() << "\n";
    std::cout << "Area: " << sqr.Area() << "\n\n";

    std::cout << "Enter octagon (points):\n";
    Octagon oct(std::cin);
    oct.Print(std::cout);
    std::cout << "The number of vertexes: " << oct.VertexesNumber() << "\n";
    std::cout << "Area: " << oct.Area() << "\n";
    return 0;
}