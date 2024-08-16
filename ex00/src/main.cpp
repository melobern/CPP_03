/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:16:27 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/16 23:14:49 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"

int main(void) {
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
    for (int i = 0; i < 10; i ++) {
        alex.attack("Bob");
        bob.takeDamage(1);
        bob.beRepaired(1);
    }
    for (int i = 0; i < 10; i ++) {
        clover.attack("Bob");
        bob.takeDamage(1);
        bob.beRepaired(1);
    }
    return (0);
}
