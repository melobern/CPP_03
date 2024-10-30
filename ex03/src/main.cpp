/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:16:27 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/19 15:24:48 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

static void  LoopAttack(DiamondTrap *att, DiamondTrap *def, std::string name) {
    for (int i = 0; i < 5; i ++) {
        att->attack(name);
        if (att->getHitPoints() > 0)
            def->takeDamage(att->getAttackDamage());
        def->beRepaired(3);
    }
}

int    main(void) {
    DiamondTrap sam("Sam");
    DiamondTrap mandy("Mandy");

    LoopAttack(&sam, &mandy, "Mandy");
    sam.highFivesGuys();
    mandy.highFivesGuys();
    sam.guardGate();
    mandy.guardGate();
    sam.whoAmI();
    return (0);
}
