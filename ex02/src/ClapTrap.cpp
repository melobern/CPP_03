/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:15:55 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/20 11:35:51 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include <climits>

#define GREEN "\033[32m"
#define RESET "\033[0m"

ClapTrap::ClapTrap(void)
    :_name("Anonymous"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(const std::string name, int health, int mana, int strength)
    :_name(name),
     _hitPoints(health), _energyPoints(mana), _attackDamage(strength) {
    std::cout << "ClapTrap " << name;
    std::cout << " : constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(const std::string name)
    :_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << name;
    std::cout << " : constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
    std::cout << "Copy constructor called" << std::endl;
    *this = claptrap;
    return;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->_name;
    std::cout <<" : Destructor called" << std::endl;
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
    int mana = this->_energyPoints;
    int health = this->_hitPoints;

    if (health <= 0) {
        std::cout << "ClapTrap " << this->_name;
        std::cout << " is dead. Dead claptraps can't attack!";
    } else if (mana > 0) {
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

    std::cout << this->_name;
    if (health > 0 && amount > 0 && amount < health) {
        std::cout << " took ";
        std::cout << amount;
        std::cout << " points of damage!";
        this->_hitPoints-= amount;
    } else if (health > 0 && amount >= health) {
        std::cout << " took ";
        std::cout << amount;
        std::cout << " points of damage and died! RIP ";
        std::cout << this->_name << " ✝️";
        this->_hitPoints = 0;
    } else if (health <= 0) {
        std::cout << " can't take anymore damage. They're already dead!";
    } else {
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
    if (health <= 0) {
        std::cout << " is dead. You can't resurrect the deads :'(";
    } else if (health < INT_MAX && mana > 0) {
        std::cout << GREEN << " is getting repaired for ";
        if (amount < INT_MAX && amount + health <= INT_MAX) {
            std::cout << amount;
            this->_hitPoints += amount;
        } else {
            std::cout << (INT_MAX - health);
            this->_hitPoints = INT_MAX;
        }
        std::cout << " points!";
        std::cout << " They now have ";
        std::cout << this->_hitPoints;
        std::cout << " health points! 💚" << RESET;
        this->_energyPoints--;
    } else if (health == INT_MAX && mana > 0) {
        std::cout << " tried to heal, but their health is already at max!";
        this->_energyPoints--;
    } else if (mana <= 0) {
        std::cout << " tried to heal, but they don't have any energy left!";
    }
    std::cout << std::endl;
}
