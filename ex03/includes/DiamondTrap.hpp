/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:03:07 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/19 14:23:00 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_INCLUDES_DIAMONDTRAP_HPP_
#define EX03_INCLUDES_DIAMONDTRAP_HPP_

#include <iostream>
#include <string>
#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  DiamondTrap(void);
  explicit DiamondTrap(const std::string name);
  explicit DiamondTrap(const DiamondTrap &diamontrap);
  ~DiamondTrap(void);
  DiamondTrap &operator=(const DiamondTrap &diamontrap);
  void   whoAmI();
  void   attack(const std::string& target);
 private:
  std::string _name;
  ScavTrap    scavtrap;
  FragTrap    fragtrap;
};
#endif  // EX03_INCLUDES_DIAMONDTRAP_HPP_
