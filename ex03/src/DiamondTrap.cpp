/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:03:07 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/19 14:56:01 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define RESET "\033[0m"

DiamondTrap::DiamondTrap(void) {
    std::cout << BLUE << "💎  DiamondTrap Anonymous :";
    std::cout << "Default constructor called" << RESET << std::endl;
    return;
}

DiamondTrap::DiamondTrap(const std::string name)
    :ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    this->_name = name;
    this->_hitPoints = fragtrap.getHitPoints();
    this->_energyPoints = scavtrap.getEnergyPoints();
    this->_attackDamage = fragtrap.getAttackDamage();
    std::cout << BLUE "💎  DiamondTrap " << name << " : ";
    std::cout << "constructor called" << RESET << std::endl;
    return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap)
    :ClapTrap(diamondtrap),
     ScavTrap(diamondtrap), FragTrap(diamondtrap) {
    std::cout << BLUE << "💎  DiamondTrap : ";
    std::cout << "Copy constructor called" <<  RESET << std::endl;
    *this = diamondtrap;
    return;
}

DiamondTrap::~DiamondTrap() {
    std::cout << BLUE << "💎  DiamondTrap " << this->_name << " : ";
    std::cout <<"Destructor called" << RESET << std::endl;
    return;
}

DiamondTrap   &DiamondTrap::operator=(const DiamondTrap &diamondtrap) {
    std::cout << BLUE << "💎  Copy assignment operator called" << RESET;
    std::cout << std::endl;
    if (this != &diamondtrap) {
        this->_name = diamondtrap.getName();
        this->ClapTrap::_name = diamondtrap.ClapTrap::_name;
        this->_hitPoints = diamondtrap.getHitPoints();
        this->_energyPoints = diamondtrap.getEnergyPoints();
        this->_attackDamage = diamondtrap.getAttackDamage();
    }
    return (*this);
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << BLUE << "💎  My name is " << this->_name;
    std::cout << " and my ClapTrap name is " << this->ClapTrap::_name;
    std::cout << "  💎" << RESET;
    std::cout << std::endl;
}
