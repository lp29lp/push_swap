/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:47:31 by lpaulo-d          #+#    #+#             */
/*   Updated: 2021/12/10 11:08:34 by lpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nn;

	nn = malloc(nmemb * size);
	if (nn == NULL)
		return (NULL);
	ft_bzero(nn, nmemb * size);
	return (nn);
}
