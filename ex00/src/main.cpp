/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:16:27 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/18 12:44:49 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"

static void   loopAttack(ClapTrap *att, ClapTrap *def, std::string name) {
    for (int i = 0; i < 10; i ++) {
        att->attack(name);
        def->takeDamage(att->getAttackDamage());
    }
}

static void   loopAttackRepair(ClapTrap *att, ClapTrap *def, std::string name) {
    for (int i = 0; i < 10; i ++) {
        att->attack(name);
        def->takeDamage(1);
        def->beRepaired(1);
    }
}

int    main(void) {
    ClapTrap jim("Jim");
    ClapTrap bob("Bob");
    ClapTrap jim2(jim);
    ClapTrap alex("Alex");
    ClapTrap clover("Clover");

    loopAttack(&jim, &bob, "Bob");
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
    loopAttackRepair(&alex, &bob, "Bob");
    loopAttackRepair(&clover, &bob, "Bob");
    return (0);
}
