/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyniemit <jyniemit@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:23:08 by jyniemit          #+#    #+#             */
/*   Updated: 2025/05/04 14:58:19 by jyniemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GAME_H
# define GAME_H
# define MIN(a, b) ((a) < (b) ? (a) : (b))
typedef struct s_spell
{
	int dmg;
	int cost;
} t_spell;

#endif
