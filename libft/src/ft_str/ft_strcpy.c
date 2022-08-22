/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreno <lmoreno@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:19:23 by LeoMoreno         #+#    #+#             */
/*   Updated: 2022/08/22 12:29:12 by lmoreno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, char *src)
{
	if (!src && !dst)
		return (NULL);
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}
