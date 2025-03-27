/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:00:00 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/27 18:59:23 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <cmath>
# include <iostream>

class Point
{
  private:
    const Fixed x;
    const Fixed y;

  public:
    Point();
    Point(const Fixed x, const Fixed y);
    Point(const Point &obj);
    Point &operator=(const Point &obj);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
