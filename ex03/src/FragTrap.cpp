/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:56:19 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/19 14:20:01 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

FragTrap::FragTrap(void)
    :ClapTrap("Anonymous", 100, 100, 30) {
    std::cout << BLUE << "⚔️   FragTrap Anonymous :";
    std::cout << "Default constructor called" << RESET << std::endl;
    return;
}

FragTrap::FragTrap(const std::string name)
    :ClapTrap(name, 100, 100, 30) {
    std::cout << BLUE "⚔️   FragTrap " << name << " : ";
    std::cout << "constructor called" << RESET << std::endl;
    return;
}

FragTrap::FragTrap(const FragTrap &scavtrap) {
    std::cout << "⚔️   FragTrap : ";
    std::cout << "Copy constructor called" << std::endl;
    *this = scavtrap;
    return;
}

FragTrap::~FragTrap() {
    std::cout << "⚔️   FragTrap " << this->_name << " : ";
    std::cout <<"Destructor called" << std::endl;
    return;
}

FragTrap   &FragTrap::operator=(const FragTrap &scavtrap) {
    std::cout << "⚔️   Copy assignment operator called" << std::endl;
    if (this != &scavtrap) {
        this->_name = scavtrap.getName();
        this->_hitPoints = scavtrap.getHitPoints();
        this->_energyPoints = scavtrap.getEnergyPoints();
        this->_attackDamage = scavtrap.getAttackDamage();
    }
    return (*this);
}

void FragTrap::highFivesGuys(void) {
    if (this->_hitPoints > 0) {
        std::cout << YELLOW << "FragTrap " << this->_name;
        std::cout << " gives a HIGH FIVE" << RESET << "🙌  ";
    } else {
        std::cout << RED << "FragTrap " << this->_name;
        std::cout << " is dead. ";
        std::cout << "Anyway, they high five as high as they can ";
        std::cout << RESET "🙌💀";
    }
    std::cout << std::endl;
}
