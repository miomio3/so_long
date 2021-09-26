#include "ikimono.h"


static void	init_player(t_image player[CHARA_NUM][VER_NUM][DIRE_NUM], int who, int version, char *up1_path, char *up2_path, char *down1_path, char *down2_path, \
char *right1_path, char *right2_path, char *left1_path,char *left2_path)
{
	player[who][version][UP1].path = ft_strdup(up1_path);
	player[who][version][UP2].path = ft_strdup(up2_path);
	player[who][version][DOWN1].path = ft_strdup(down1_path);
	player[who][version][DOWN2].path = ft_strdup(down2_path);
	player[who][version][RIGHT1].path = ft_strdup(right1_path);
	player[who][version][RIGHT2].path = ft_strdup(right2_path);
	player[who][version][LEFT1].path = ft_strdup(left1_path);
	player[who][version][LEFT2].path = ft_strdup(left2_path);
}

void	init_obj(t_image *obj, char *path)
{
	(*obj).path = ft_strdup(path);
}

void	init_characters_path(t_characters *characters)
{
	init_player((*characters).player, KIYOE, NORMAL, "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm");
	init_player((*characters).player, LEADER, NORMAL, "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm");
	init_player((*characters).player, HOCCHI, NORMAL, "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm", "./image/kureshin.xpm");
	init_obj(&(*characters).obj[WALL], "./image/test.xpm");
	init_obj(&(*characters).obj[FIELD], "./image/test.xpm");
	init_obj(&(*characters).obj[HOSPITAL], "./image/test.xpm");
	init_obj(&(*characters).obj[CASTLE], "./image/test.xpm");
}
