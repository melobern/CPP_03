/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:13:56 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/18 11:24:03 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_INCLUDES_CLAPTRAP_HPP_
#define EX00_INCLUDES_CLAPTRAP_HPP_

#include <iostream>
#include <string>

class ClapTrap {
 public:
  ClapTrap(void);
  explicit ClapTrap(const std::string name);
  explicit ClapTrap(const ClapTrap &claptrap);
  ~ClapTrap(void);
  ClapTrap &operator=(const ClapTrap &num);
  void   attack(const std::string& target);
  void   takeDamage(unsigned int amount);
  void   beRepaired(unsigned int amount);
  std::string getName(void) const;
  int    getHitPoints(void)const;
  int    getEnergyPoints(void)const;
  int    getAttackDamage(void)const;
 private:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;
};
#endif  // EX00_INCLUDES_CLAPTRAP_HPP_
