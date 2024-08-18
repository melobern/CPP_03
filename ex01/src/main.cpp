/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:16:27 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/18 16:39:42 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

static void   scavLoopAttack(ScavTrap *att, ScavTrap *def, std::string name) {
    for (int i = 0; i < 10; i ++) {
        att->attack(name);
        if (att->getHitPoints() > 0)
            def->takeDamage(att->getAttackDamage());
        def->beRepaired(1);
    }
}

int    main(void) {
    ClapTrap jim("Jim");
    ClapTrap bob("Bob");
    ScavTrap clover("Clover");
    ScavTrap alex("Alex");
    ScavTrap alex2(alex);

    clover.guardGate();
    scavLoopAttack(&alex, &alex2, "its copy : Alex2");
    scavLoopAttack(&alex2, &alex, "the original Alex");
    alex2.guardGate();
    jim.attack("Bob");
    return (0);
}
