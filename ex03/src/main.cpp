/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:15:00 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/29 15:53:13 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

void testPoint(const Point &a, const Point &b, const Point &c, const Point &point, const char* description)
{
    std::cout << description << (bsp(a, b, c, point) 
        ? ": Point is inside the triangle!" 
        : ": Point is outside the triangle.") << std::endl;
}

int main()
{
    std::cout << "=== ORIGINAL TEST - Simple Triangle ===\n";
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    Point inside(5.0f, 5.0f);
    Point outside(20.0f, 20.0f);
    Point onEdge(5.0f, 0.0f);
    Point onVertex(0.0f, 0.0f);

    std::cout << "Triangle vertices: A(0,0), B(10,0), C(5,10)\n";
    
    testPoint(a, b, c, inside, "Testing point (5,5)");
    testPoint(a, b, c, outside, "Testing point (20,20)");
    testPoint(a, b, c, onEdge, "Testing point (5,0)");
    testPoint(a, b, c, onVertex, "Testing point (0,0)");

    std::cout << "\n=== INTEGER VALUES TEST ===\n";
    Point a2(-5, -5);
    Point b2(5, -5);
    Point c2(0, 5);
    
    std::cout << "Triangle vertices: A(-5,-5), B(5,-5), C(0,5)\n";
    
    testPoint(a2, b2, c2, Point(0, 0), "Testing point (0,0)");
    testPoint(a2, b2, c2, Point(1, 1), "Testing point (1,1)");
    testPoint(a2, b2, c2, Point(-6, -6), "Testing point (-6,-6)");
    testPoint(a2, b2, c2, Point(0, -5), "Testing point (0,-5)");
    
    std::cout << "\n=== FLOATING-POINT VALUES TEST ===\n";
    Point a3(1.5f, 2.3f);
    Point b3(7.8f, 1.1f);
    Point c3(4.2f, 8.7f);
    
    std::cout << "Triangle vertices: A(1.5,2.3), B(7.8,1.1), C(4.2,8.7)\n";
    
    testPoint(a3, b3, c3, Point(4.0f, 4.0f), "Testing point (4.0,4.0)");
    testPoint(a3, b3, c3, Point(1.5f, 2.3f), "Testing point (1.5,2.3) - vertex");
    testPoint(a3, b3, c3, Point(4.65f, 1.7f), "Testing point (4.65,1.7) - should be on edge");
    testPoint(a3, b3, c3, Point(10.0f, 10.0f), "Testing point (10.0,10.0)");
    
    std::cout << "\n=== SMALL DECIMAL VALUES TEST ===\n";
    Point a4(0.01f, 0.01f);
    Point b4(0.05f, 0.01f);
    Point c4(0.03f, 0.05f);
    
    std::cout << "Triangle vertices: A(0.01,0.01), B(0.05,0.01), C(0.03,0.05)\n";
    
    testPoint(a4, b4, c4, Point(0.03f, 0.02f), "Testing point (0.03,0.02)");
    testPoint(a4, b4, c4, Point(0.01f, 0.01f), "Testing point (0.01,0.01) - vertex");
    testPoint(a4, b4, c4, Point(0.02f, 0.04f), "Testing point (0.02,0.04)");
    testPoint(a4, b4, c4, Point(0.03f, 0.01f), "Testing point (0.03,0.01) - on edge");

    return (0);
}