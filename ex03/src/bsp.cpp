/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+    :+:   */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:05:00 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/18 18:30:00 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

// Calculate the area of triangle using cross product
static Fixed calculateArea(Point const &a, Point const &b, Point const &c)
{
    // Area = 1/2 * |((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))|
    Fixed area = ((a.getX() * (b.getY() - c.getY())) +
                 (b.getX() * (c.getY() - a.getY())) +
                 (c.getX() * (a.getY() - b.getY()))) / 2;
    
    // We need the absolute value of the area
    if (area < 0)
        return area * -1;
    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // Calculate the area of the triangle ABC
    Fixed areaABC = calculateArea(a, b, c);
    
    // If the triangle has no area, point can't be inside
    if (areaABC == 0)
        return false;
    
    // Calculate the areas of triangles formed by the point and each side of the triangle
    Fixed areaPAB = calculateArea(point, a, b);
    Fixed areaPBC = calculateArea(point, b, c);
    Fixed areaPAC = calculateArea(point, a, c);
    
    // If the point is on an edge or vertex, at least one of the areas will be 0
    if (areaPAB == 0 || areaPBC == 0 || areaPAC == 0)
        return false;
    
    // If point is inside, the sum of the three areas should equal the total triangle area
    Fixed sumOfAreas = areaPAB + areaPBC + areaPAC;
    
    // Due to floating-point precision, we check if they're very close
    return (sumOfAreas == areaABC);
}
