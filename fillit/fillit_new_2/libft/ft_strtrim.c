/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkayla <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:15:44 by hkayla            #+#    #+#             */
/*   Updated: 2019/09/25 19:24:44 by hkayla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*result;
	unsigned int	start;
	unsigned int	size;
	unsigned int	ws_cnt;

	if (!s)
		return (NULL);
	size = (unsigned int)ft_strlen((char*)s);
	ws_cnt = ft_strcntstartchar((char*)s, " \n\t");
	start = ws_cnt;
	if (size > ws_cnt)
		ws_cnt += ft_strcntendchar((char*)s, " \n\t");
	size -= ws_cnt;
	if (!(result = ft_memalloc((size_t)size + 1)))
		return (NULL);
	result = ft_strncpy(result, (char*)s + start, size);
	return (result);
}
