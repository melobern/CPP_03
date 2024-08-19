/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:16:27 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/19 14:50:18 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

static void  LoopAttack(DiamondTrap *att, DiamondTrap *def, std::string name) {
    for (int i = 0; i < 10; i ++) {
        att->attack(name);
        if (att->getHitPoints() > 0)
            def->takeDamage(att->getAttackDamage());
        def->beRepaired(1);
    }
}

int    main(void) {
    DiamondTrap sam("Sam");
    DiamondTrap mandy("Mandy");

    LoopAttack(&sam, &mandy, "Mandy");
    sam.highFivesGuys();
    sam.guardGate();
    sam.whoAmI();
    return (0);
}
