/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:00:00 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/18 18:01:58 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
  private:
    const Fixed x;
    const Fixed y;

  public:
    Point(); // Default constructor
    Point(const float x, const float y); // Constructor with parameters
    Point(const Point &src); // Copy constructor
    Point &operator=(const Point &rhs); // Assignment operator
    ~Point(); // Destructor

    Fixed getX() const; // Getter for x
    Fixed getY() const; // Getter for y
};

// BSP function declaration
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
