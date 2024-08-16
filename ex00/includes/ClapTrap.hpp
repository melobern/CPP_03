/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:13:56 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/16 14:15:23 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_INCLUDES_CLAPTRAP_HPP_
#define EX00_INCLUDES_CLAPTRAP_HPP_

#include <iostream>

class ClapTrap {
 public:
  explicit ClapTrap(const std::string name);
  explicit ClapTrap(const ClapTrap &claptrap);
  ~ClapTrap(void);
  ClapTrap &operator=(const ClapTrap &num);
  void   attack(const std::string& target);
  void   takeDamage(unsigned int amount);
  void   beRepaired(unsigned int amount);
 private:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;
};
#endif  // EX00_INCLUDES_CLAPTRAP_HPP_
