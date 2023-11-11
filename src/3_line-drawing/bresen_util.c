/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:07:16 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/11 07:53:59 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// @returns		0 if equal, 1 if nbr1 is smaller, -1 if nbr2 is smaller
int	smaller_than(int nbr1, int nbr2)
{
	if (nbr1 < nbr2)
		return (1);
	if (nbr1 > nbr2)
		return (-1);
	return (0);
}
