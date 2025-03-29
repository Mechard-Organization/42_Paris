/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 09:09:21 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 09:09:21 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Traite une ligne lue et met à jour la liste.
 */
static int process_line(char *line, t_cub *cub, t_list **list,
                          int *reading_map, int *header_found)
{
    t_list *tmp;
    if (!(*reading_map) && is_header_line(line))
    {
        *header_found = 1;
        if (parse_header_line(line, cub)) {
            free(line);
            return (1);
        }
    }
    else if (ft_strlen(line) > 0)
    {
        *reading_map = 1;
        tmp = ft_lstnew(ft_strdup(line));
        if (!tmp) {
            free(line);
            return (1);
        }
        ft_lstadd_back(list, tmp);
    }
    free(line);
    return (0);
}

/*
 * Lit le fichier et remplit la liste de lignes.
 */
static int read_file_lines(char *filename, t_cub *cub, 
                             t_list **list, int *header_found)
{
    int     fd;
    int     reading_map;
    char    *line;

    reading_map = 0;
    *list = NULL;
    *header_found = 0;
    if (!is_valid_extension(filename))
        return (ft_putendl_fd("Extension invalide", 2), 1);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (ft_putendl_fd("Erreur d'ouverture", 2), 1);
    while ((line = get_next_line(fd)) != NULL)
    {
        if (process_line(line, cub, list, &reading_map, header_found))
        {
            close(fd);
            return (1);
        }
    }
    close(fd);
    return (0);
}

/*
 * Parse le fichier .cub et construit la map.
 */
int parse_file(char *filename, t_cub *cub)
{
    t_list *list;
    int header_found;
    int ret;

    ret = read_file_lines(filename, cub, &list, &header_found);
    if (ret != 0)
        return (ret);
    if (!header_found && list == NULL)
    {
        ft_putendl_fd("Fichier vide ou mal formé", 2);
        return (-1);
    }
    return (convert_map_list(list, cub));
}
