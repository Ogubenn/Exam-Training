#ifndef FT_LIST_SIZE
# define FT_LIST_SIZE

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}   t_list;

int ft_list_size(t_list *begin_list);

#endif
