/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:24:03 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/18 14:56:19 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_INCLUDES_SCAVTRAP_HPP_
#define EX01_INCLUDES_SCAVTRAP_HPP_

#include <iostream>
#include <string>
#include "../includes/ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap(void);
  explicit ScavTrap(const std::string name);
  explicit ScavTrap(const ScavTrap &scavtrap);
  ~ScavTrap(void);
  ScavTrap &operator=(const ScavTrap &num);
  void guardGate(void);
  void   attack(const std::string& target);
};
#endif  // EX01_INCLUDES_SCAVTRAP_HPP_