/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:56:19 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/19 14:24:04 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_INCLUDES_FRAGTRAP_HPP_
#define EX03_INCLUDES_FRAGTRAP_HPP_

#include <iostream>
#include <string>
#include "../includes/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 public:
  FragTrap(void);
  explicit FragTrap(const std::string name);
  explicit FragTrap(const FragTrap &scavtrap);
  ~FragTrap(void);
  FragTrap &operator=(const FragTrap &num);
  void highFivesGuys(void);
};
#endif  // EX03_INCLUDES_FRAGTRAP_HPP_
