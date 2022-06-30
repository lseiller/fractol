/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:48:41 by lseiller          #+#    #+#             */
/*   Updated: 2022/06/27 12:44:54 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# if defined (__APPLE__)
#  define PTR_NULL "0x0"
# elif __linux__
#  define PTR_NULL "(nil)"
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdarg.h>

/* ************************************************************************** */

int			ft_toupper(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
int			ft_atoi(const char *nptr);
double		ft_atof(const char *nptr);
void		ft_bzero(void *s, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *const_str1, const char *const_str2);
char		*ft_strnstr(const char *big, const char *little, size_t len);

/* ************************************************************************** */

char		*ft_itoa(int n);
//void	ft_putnbr_fd(int n, int fd);
void		ft_free_split(char **split);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
char		**ft_split_path(char const *s);
char		**ft_free_tab(char **dest, int j);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strncut(char *str, char set, size_t size);
void		ft_striteri(char *s, void (*f) (unsigned int, char*));
char		*ft_strjoin_sep(char const *s1, char const *s2, char sep);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char		*ft_substr_set(char const *s, unsigned int start, char set);

/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list_l;

int			ft_lstsize(t_list_l *lst);
t_list_l	*ft_lstlast(t_list_l *lst);
t_list_l	*ft_lstnew(void *content);
void		ft_lstiter(t_list_l *lst, void (*f)(void *));
void		ft_lstadd_back(t_list_l **alst, t_list_l *new);
void		ft_lstadd_front(t_list_l **alst, t_list_l *new);
void		ft_lstdelone(t_list_l *lst, void (*del)(void*));
void		ft_lstclear(t_list_l **lst, void (*del)(void*));
t_list_l	*ft_lstmap(t_list_l *lst, void *(*f)(void *), void (*del)(void *));

/* ************************************************************************** */

int			ft_printf(const char *format, ...);
int			ft_dprintf(int fd, const char *format, ...);

int			ft_check_base(char *base);
int			ft_putnbr_fd(long n, int fd);
int			ft_putptr_fd(void *ptr, int fd);
int			ft_putnbr_base_fd(long nbr, char *base, int fd);
int			ft_puthex_fd(long v_to_p, const char f, int fd, int is_un);
int			ft_putnbr_base_un_fd(unsigned long nbr, char *base, int fd);

/* ************************************************************************** */

char		*get_next_line(int fd);
char		*fill_nl(char *buffer);
char		*fill_no_nl(char *buffer);
char		*ft_strjoin_free(char *s1, char *s2);
char		*strjoin_gnl(char *s1, char *s2);
void		ft_strrcpy(char *dst, char *src, size_t size);
void		ft_strmcpy(char *dst, char *src, size_t size);
char		*fill_join(char *line, char *buffer, int fd, int read_value);

/* ************************************************************************** */

#endif
