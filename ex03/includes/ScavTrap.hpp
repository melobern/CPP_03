/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:24:03 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/19 13:47:12 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_INCLUDES_SCAVTRAP_HPP_
#define EX03_INCLUDES_SCAVTRAP_HPP_

#include <iostream>
#include <string>
#include "../includes/ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap(void);
  explicit ScavTrap(const std::string name);
  explicit ScavTrap(const ScavTrap &scavtrap);
  ~ScavTrap(void);
  ScavTrap &operator=(const ScavTrap &num);
  void guardGate(void);
  void   attack(const std::string& target);
};
#endif  // EX03_INCLUDES_SCAVTRAP_HPP_
