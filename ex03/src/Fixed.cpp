/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:15:49 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/27 19:36:48 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(void) : _raw(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_raw = n << this->_nbits;
}

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(f * (1 << this->_nbits));
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	// std::cout << "Copy constructor called" << std::endl;
	if (this != &obj)
		this->setRawBits(obj.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->setRawBits(obj.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_raw);
}

void Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)(this->_raw) / (1 << this->_nbits));
}

int Fixed::toInt(void) const
{
	return (this->_raw >> this->_nbits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed &obj) const
{
	return (this->_raw > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->_raw < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->_raw >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->_raw <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->_raw == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->_raw != obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	Fixed result;
	result.setRawBits(this->_raw + obj.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	Fixed result;
	result.setRawBits(this->_raw - obj.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	return (Fixed(this->toFloat() / obj.toFloat()));
}

// Pre-increment
Fixed &Fixed::operator++(void)
{
	this->_raw++;
	return (*this);
}

// Post-increment
Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	++(*this);
	return (old);
}

// Pre-decrement
Fixed &Fixed::operator--(void)
{
	this->_raw--;
	return (*this);
}

// Post-decrement
Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	--(*this);
	return (old);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
