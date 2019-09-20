/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyluu <cyluu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 22:32:37 by cyluu             #+#    #+#             */
/*   Updated: 2019/09/04 11:20:28 by cyluu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**function is similar, except it only compares the first (at most) n bytes of
**s1 and s2.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sn1;
	unsigned char	*sn2;

	sn1 = (unsigned char *)s1;
	sn2 = (unsigned char *)s2;
	i = 0;
	while (sn1[i] && sn2[i] && sn1[i] == sn2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (sn1[i] - sn2[i]);
}
