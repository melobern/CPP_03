/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:15:55 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/16 14:27:46 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name)
    :_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
    std::cout << "Copy constructor called" << std::endl;
    *this = claptrap;
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
    return (*this);
}

void   attack(const std::string& target) {
    if (this->_energyPoints > 0) {
        std::cout << "ClapTrap ";
        std::cout << this->_name;
        std::cout << "attacks";
        std::cout << target;
        std::cout << ", causing ";
        std::cout << this->_attackDamage;
        std::cout << "points of damage!";
    } else {
        std::cout << "ClapTrap ";
        std::cout << this->_name;
        std::cout << "is too tired to attack!";
    }
}

void   takeDamage(unsigned int amount) {
    
    std::cout << "ClapTrap ";
    std::cout << this->_name;
    std::cout << "took";
    std::cout << amount;
    std::cout << "points of damage!";
}

void   beRepaired(unsigned int amount) {
    std::cout << "ClapTrap ";
    std::cout << this->_name;
    std::cout << "attacks";
    std::cout << target;
    std::cout << ", causing ";
    std::cout << this->_attackDamage;
    std::cout << "points of damage!";
}
