/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:14:57 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/24 12:02:18 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

Fixed area(Point const &a, Point const &b, Point const &c) {
    return Fixed(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + 
                 b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
                 c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())).abs() / 2.0f;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = area(a, b, c);
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);
    // std::cout << totalArea << std::endl;
    return (totalArea == (area1 + area2 + area3) && area1 != 0 && area2 != 0 && area3 != 0);
}