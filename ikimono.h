#ifndef IKIMONO_H_
#define IKIMONO_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>//"./minilibx-linux/mlx.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define ERROR   	-1
#define NOERROR 	1

#define KIYOE		0
#define LEADER		1
#define	HOCCHI		2

#define	NORMAL		0
#define	SING		1
#define HOS			2
#define CASTLE		3

#define	WALL		0
#define	FIELD		1
#define	HOSPITAL	2
#define	CASTLE		3

#define UP1			0
#define UP2			1
#define DOWN1		2
#define DOWN2		3
#define RIGHT1		4
#define RIGHT2		5
#define LEFT1		6
#define LEFT2		7

#define	CHARA_NUM	3
#define VER_NUM		4
#define DIRE_NUM	8
#define OBJ_NUM		4

#define	WIN_UNIT	20

typedef struct  s_vars
{
    void    *mlx;
    void    *win;
}               t_vars;

typedef struct  s_data
{
    char    **map;
    int     kiyoe_ver[2];
    int     leader_ver[2];
    int     hocchi_ver[2];
    int     TV_ver;
	int		width;
	int		height;
}               t_data;

typedef struct	s_image
{
	void	*image;
	char	*path;
	int		width;
	int		height;
	int		*addr;
	int		bit;
	int		size;
	int		endian;
}				t_image;

/* typedef struct	s_player
{
	t_image	normal[4];
	t_image	sing[4];
	t_image	hos[4];
	t_image	castle[4];
}				t_player; */

typedef struct	s_characters
{
	t_image		player[CHARA_NUM][VER_NUM][DIRE_NUM];
	/* t_player	kiyoe;
	t_player	leader;
	t_player	hocchi; */

	t_image		obj[4];
	t_image		TV[4];
}				t_characters;

//libft1
void    ft_putstr(char *array);
int     ft_strlen(char *array);
void    ft_bzero(void *array, int n);
void    ft_strcopy(char *ret, char *array);
//libft2
void    safe_free(char *array);
char    *ft_strjoin_free(char *array1, char *array2);
int     ft_len2nl(char *array);
int     count_nl(char *array);
char	*ft_strdup(char *s);
//error
void    print_arg_error(void);
void    print_malloc_error(void);
//read_map
char    *read_map(char *argv);
//init_data
void    init_data(t_data *data, char *array);
//init_character_path
void	init_characters_path(t_characters *characters);
//init_characters_image
void	init_characters_image(t_characters characters, t_vars vars);
//run_animation
void	run_animation(t_data data);

#endif