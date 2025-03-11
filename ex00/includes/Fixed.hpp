/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:15:52 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/11 23:39:30 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	int _raw;
	static const int _nbits = 8;

  public:
	Fixed(void);
	Fixed(const Fixed &obj);
	Fixed &operator=(const Fixed &obj);
	~Fixed(void);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif