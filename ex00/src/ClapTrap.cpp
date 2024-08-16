/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:15:55 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/16 11:04:25 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() {
    this->_fixedComma = 0;
    std::cout << "Default constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(const ClapTrap &num) {
    std::cout << "Copy constructor called" << std::endl;
    *this = num;
    return;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
    return;
}

ClapTrap   &ClapTrap::operator=(const ClapTrap &num) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &num) {
        this->_name = num.getName();
        this->_hitPoints = num.getHitPoints();
        this->_energyPoints = num.getEnergyPoints();
        this->_attackDamage = num.getAttackDamage();
    }
    return *this;
}
