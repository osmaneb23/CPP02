/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:15:00 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/27 19:37:06 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

void testPoint(const Point &a, const Point &b, const Point &c, const Point &point, const char* description)
{
    std::cout << description << ": ";
    if (bsp(a, b, c, point))
        std::cout << "Point is inside the triangle!" << std::endl;
    else
        std::cout << "Point is outside the triangle." << std::endl;
}

int main()
{
    // Create three points for triangle vertices
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Test cases
    Point inside(5.0f, 5.0f);
    Point outside(20.0f, 20.0f);
    Point onEdge(5.0f, 0.0f);
    Point onVertex(0.0f, 0.0f);

    std::cout << "Triangle vertices: A(0,0), B(10,0), C(5,10)" << std::endl;
    
    // Run tests
    testPoint(a, b, c, inside, "Testing point (5,5)");
    testPoint(a, b, c, outside, "Testing point (20,20)");
    testPoint(a, b, c, onEdge, "Testing point (5,0)");
    testPoint(a, b, c, onVertex, "Testing point (0,0)");

    return 0;
}
