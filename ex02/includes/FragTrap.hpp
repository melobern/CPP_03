/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:56:19 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/19 14:26:30 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_INCLUDES_FRAGTRAP_HPP_
#define EX02_INCLUDES_FRAGTRAP_HPP_

#include <iostream>
#include <string>
#include "../includes/ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
  FragTrap(void);
  explicit FragTrap(const std::string name);
  explicit FragTrap(const FragTrap &scavtrap);
  ~FragTrap(void);
  FragTrap &operator=(const FragTrap &num);
  void highFivesGuys(void);
};
#endif  // EX02_INCLUDES_FRAGTRAP_HPP_
