/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:10:00 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/18 18:02:37 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point(const Point &src) : x(src.x), y(src.y)
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &rhs)
{
    (void)rhs;
    return *this;
}

// Getter for x
Fixed Point::getX() const
{
    return x;
}

// Getter for y
Fixed Point::getY() const
{
    return y;
}
