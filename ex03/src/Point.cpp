/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:10:00 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/27 18:55:33 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y)
{
}

Point::Point(const Point &obj) : x(obj.getX()), y(obj.getY())
{
}

Point &Point::operator=(const Point &obj)
{
    (void)obj;
    return (*this);
}

Point::~Point()
{
}

Fixed Point::getX() const
{
    return (x);
}

Fixed Point::getY() const
{
    return (y);
}