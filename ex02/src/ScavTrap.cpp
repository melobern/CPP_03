/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:24:03 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/19 14:28:38 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

ScavTrap::ScavTrap(void)
    :ClapTrap("Anonymous", 100, 50, 20) {
    std::cout << "ScavTrap Anonymous :";
    std::cout << "Default constructor called" << std::endl;
    return;
}

ScavTrap::ScavTrap(const std::string name)
    :ClapTrap(name, 100, 50, 20) {
    std::cout << "ScavTrap " << name << " : ";
    std::cout << "constructor called" << std::endl;
    return;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) {
    std::cout << "ScavTrap : ";
    std::cout << "Copy constructor called" << std::endl;
    *this = scavtrap;
    return;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->_name << " : ";
    std::cout <<"Destructor called" << std::endl;
    return;
}

ScavTrap   &ScavTrap::operator=(const ScavTrap &scavtrap) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &scavtrap) {
        this->_name = scavtrap.getName();
        this->_hitPoints = scavtrap.getHitPoints();
        this->_energyPoints = scavtrap.getEnergyPoints();
        this->_attackDamage = scavtrap.getAttackDamage();
    }
    return (*this);
}

void   ScavTrap::attack(const std::string& target) {
    int mana = this->_energyPoints;
    int health = this->_hitPoints;

    if (health <= 0) {
        std::cout << RED << "ScavTrap " << this->_name;
        std::cout << " is dead. They can't attack!" << RESET << " 💀";;
    } else if (mana > 0 && health > 0) {
        std::cout << "🗡️  " << RED << "ScavTrap " << this->_name;
        std::cout << " attacks ";
        std::cout << target;
        std::cout << ", causing ";
        std::cout << this->_attackDamage;
        std::cout << " points of damage!" << RESET;
        this->_energyPoints--;
    } else if (health > 0) {
        std::cout << YELLOW << "ScavTrap " << this->_name;
        std::cout << " is too tired to attack!" << RESET;
    }
    std::cout << std::endl;
}

void    ScavTrap::guardGate(void) {
    if (this->_hitPoints > 0) {
        std::cout << "🛡️  " << BLUE << "ScavTrap " << this->_name;
        std::cout << " entered guardgate mode " << RESET << "🛡️";
    } else {
        std::cout << "🛡️  " << BLUE << "ScavTrap " << this->_name;
        std::cout << " is dead. Corpses can't enter guardgate mode ";
        std::cout << RESET "💀";
    }
    std::cout << std::endl;
}
