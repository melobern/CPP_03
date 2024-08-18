/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:16:27 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/18 11:44:14 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"

static void   loopAttack(ClapTrap& attacker, ClapTrap& victim, std::string name) {
    for (int i = 0; i < 10; i ++) {
        attacker.attack(name);
        victim.takeDamage(attacker.getAttackDamage());
}

static void   loopAttackRepair(ClapTrap& attacker, ClapTrap& victim, std::string name) {
    for (int i = 0; i < 10; i ++) {
        attacker.attack(name);
        victim.takeDamage(1);
        victim.beRepaired(1);
    }
}

int    main(void) {
    ClapTrap jim("Jim");
    ClapTrap bob("Bob");
    ClapTrap jim2(jim);
    ClapTrap alex("Alex");
    ClapTrap clover("Clover");

    for (int i = 0; i < 10; i ++) {
        jim.attack("Bob");
        bob.takeDamage(jim.getAttackDamage());
    }
    jim.attack("Bob");
    jim2.attack("Jim");
    jim.takeDamage(jim2.getAttackDamage());
    bob.beRepaired(0);
    jim.beRepaired(1);
    jim.attack("Bob");
    jim.attack("Jim");
    jim.takeDamage(10);
    jim.beRepaired(10);
    jim.takeDamage(1);
    jim.attack("Bob");
    loopAttackRepair(alex, bob, "Bob");
    loopAttackRepair(clover, bob, "Bob");
    return (0);
}
