/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:15:55 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/16 23:09:54 by mbernard         ###   ########.fr       */
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

std::string ClapTrap::getName(void) const {
    return (this->_name);
}
int    ClapTrap::getHitPoints(void) const {
    return (this->_hitPoints);
}

int    ClapTrap::getEnergyPoints(void) const {
    return (this->_energyPoints);
}

int    ClapTrap::getAttackDamage(void) const {
    return (this->_attackDamage);
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

void   ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints > 0) {
        std::cout << "ClapTrap " << this->_name;
        std::cout << " attacks ";
        std::cout << target;
        std::cout << ", causing ";
        std::cout << this->_attackDamage;
        std::cout << " points of damage!";
        this->_energyPoints--;
    } else {
        std::cout << "ClapTrap " << this->_name;
        std::cout << " is too tired to attack!";
    }
    std::cout << std::endl;
}

void   ClapTrap::takeDamage(unsigned int amount) {
    unsigned int health = this->getHitPoints();

    if (health > 0 && amount > 0 && amount < health) {
        std::cout << "ClapTrap " << this->_name;
        std::cout << " took ";
        std::cout << amount;
        std::cout << " points of damage!";
        this->_hitPoints-= amount;
    } else if (health > 0 && amount >= health) {
        std::cout << "ClapTrap " << this->_name;
        std::cout << " took ";
        std::cout << amount;
        std::cout << " points of damage and died!";
        std::cout << " RIP ";
        std::cout << this->_name;
        this->_hitPoints = 0;
    } else if (health <= 0) {
        std::cout << "ClapTrap " << this->_name;
        std::cout << " can't take anymore damage. They're already dead!";
    } else {
        std::cout << "ClapTrap " << this->_name;
        std::cout << " was attacked by a force ";
        std::cout << amount;
        std::cout << " attack, but it caused no harm !";
    }
    std::cout << std::endl;
}

void   ClapTrap::beRepaired(unsigned int amount) {
    unsigned int health = this->getHitPoints();
    int mana = this->getEnergyPoints();
    
    std::cout << "ClapTrap " << this->_name;
    if (health <= 0){
        std::cout << " is dead. You can't resurrect the deads :'(";
    } else if (health < 10 && mana > 0) {
        std::cout << " is getting repaired for ";
        if (amount + health <= 10) {
            std::cout << amount;
            this->_hitPoints += amount;
        } else {
            std::cout << (10 - health);
            this->_hitPoints = 10;
        }
        std::cout << " points!";
        this->_energyPoints--;
    } else if (health >= 10) {
        std::cout << " tried to heal, but their health is already at max!";
    } else if (mana <= 0 ){
        std::cout << " tried to heal, but they don't have any energy left!";
    }
    std::cout << std::endl;
}
