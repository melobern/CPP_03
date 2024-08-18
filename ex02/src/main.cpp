/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:16:27 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/18 18:00:22 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

static void  LoopAttack(FragTrap *att, FragTrap *def, std::string name) {
    for (int i = 0; i < 10; i ++) {
        att->attack(name);
        if (att->getHitPoints() > 0)
            def->takeDamage(att->getAttackDamage());
        def->beRepaired(1);
    }
}

int    main(void) {
    FragTrap jim("Jim");
    FragTrap bob("Bob");

    jim.highFivesGuys();
    LoopAttack(&jim, &bob, "Bob");
    bob.highFivesGuys();
    return (0);
}
