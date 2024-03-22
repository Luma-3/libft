/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:09:00 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/22 13:34:53 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}					t_list;

/* ################	*/
/*	 Queue Struct	*/
/* ################	*/

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct s_queue
{
	t_node	*first;
	t_node	*last;
}			t_queue;

/* ################	*/
/*	List function	*/
/* ################	*/

/**
 * @brief Creates a new list node with the specified content.
 *
 * @param content The content to be stored in the new node.
 * @return A pointer to the newly created list node.
 */
t_list				*ft_lstnew(void *content);

/**
 * @brief Adds a new node to the front of the list.
 *
 * @param lst A pointer to the pointer to the list.
 * @param new The new node to be added to the front.
 */
void				ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Returns the number of elements in the list.
 *
 * @param lst The list to be counted.
 * @return The number of elements in the list.
 */
int					ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of the list.
 *
 * @param lst The list.
 * @return A pointer to the last element of the list.
 */
t_list				*ft_lstlast(t_list *lst);

/**
 * @brief Adds a new node to the back of the list.
 *
 * @param lst A pointer to the pointer to the list.
 * @param new The new node to be added to the back.
 */
void				ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Deletes the specified node using the provided deletion function.
 *
 * @param lst A pointer to the pointer to the list.
 * @param node The node to be deleted.
 * @param del The deletion function to be applied to the node's content.
 */
void				ft_lstdelone(t_list **lst, t_list *node,
						void (*del)(void *));

/**
 * @brief Clears the entire list using the provided deletion function.
 *
 * @param lst A pointer to the pointer to the list.
 * @param del The deletion function to be applied to each node's content.
 */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates over the list, applying the provided
 * function to each node's content.
 *
 * @param lst The list to be iterated over.
 * @param f The function to be applied to each node's content.
 */
void				ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Creates a new list resulting from applying the
 * provided function to each node's content.
 *
 * @param lst The list to be mapped.
 * @param f The mapping function to be applied to each node's content.
 * @param del The deletion function to be applied to the
 * content of any node in case of failure.
 * @return A pointer to the newly created list.
 */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* ####################	*/
/*	Compare function	*/
/* ####################	*/

/**
 * @brief Checks if the given character is an alphanumeric character.
 *
 * @param c The character to be checked.
 * @return 1 if the character is alphanumeric, 0 otherwise.
 */
int					ft_isalnum(int c);

/**
 * @brief Checks if the given character is an alphabetic character.
 *
 * @param c The character to be checked.
 * @return 1 if the character is alphabetic, 0 otherwise.
 */
int					ft_isalpha(int c);

/**
 * @brief Checks if the given character is a valid ASCII character.
 *
 * @param c The character to be checked.
 * @return 1 if the character is a valid ASCII character, 0 otherwise.
 */
int					ft_isascii(int c);

/**
 * @brief Checks if the given character is a digit (0-9).
 *
 * @param c The character to be checked.
 * @return 1 if the character is a digit, 0 otherwise.
 */
int					ft_isdigit(int c);

/**
 * @brief Checks if the given character is a printable character.
 *
 * @param c The character to be checked.
 * @return 1 if the character is printable, 0 otherwise.
 */
int					ft_isprint(int c);

/**
 * @brief Checks if the given character is a whitespace character.
 *
 * @param c The character to be checked.
 * @return 1 if the character is a whitespace character, 0 otherwise.
 */
int					ft_iswhitespace(char c);

/* ################	*/
/*	Char function	*/
/* ################	*/

/**
 * @brief Converts a given uppercase letter to lowercase.
 *
 * @param c The character to be converted.
 * @return The lowercase equivalent of the input character,
 *  		or the input character if it's not an uppercase letter.
 */
int					ft_toupper(int c);

/**
 * @brief Converts a given lowercase letter to uppercase.
 *
 * @param c The character to be converted.
 * @return The uppercase equivalent of the input character,
 * 			or the input character if it's not a lowercase letter.
 */
int					ft_tolower(int c);

/* ################	*/
/*	Memory function	*/
/* ################	*/

/**
 * @brief Sets the first len bytes of the memory area pointed to by s to zero.
 *
 * @param s   A pointer to the memory area to be zeroed.
 * @param len The number of bytes to zero.
 */
void				ft_bzero(void *s, size_t len);

/**
 * @brief Sets the first len bytes of the memory
 *  area pointed to by s to the specified value.
 *
 * @param s   A pointer to the memory area to be set.
 * @param c   The value to set (interpreted as an unsigned char).
 * @param len The number of bytes to set.
 * @return A pointer to the memory area s.
 */
void				*ft_memset(void *s, int c, size_t len);

/**
 * @brief Copies len bytes from the source memory
 *  area src to the destination memory area dst.
 *
 * @param dst A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param len The number of bytes to copy.
 * @return A pointer to the destination memory area dst.
 */
void				*ft_memcpy(void *dst, const void *src, size_t len);

/**
 * @brief Copies len bytes from the source memory
 *  area src to the destination memory area dst.
 *          The memory areas may overlap.
 *
 * @param dst A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param len The number of bytes to copy.
 * @return A pointer to the destination memory area dst.
 */
void				*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Compares the first size bytes of memory
 *  areas s1 and s2.
 *
 * @param s1   A pointer to the first memory area.
 * @param s2   A pointer to the second memory area.
 * @param size The number of bytes to compare.
 * @return     An integer less than, equal to,
 * 				or greater than zero if s1 is found,
 *             respectively, to be less than, to match, or be greater than s2.
 */
int					ft_memcmp(const void *s1, const void *s2, size_t size);

/**
 * @brief Locates the first occurrence of c (converted to an unsigned char)
 * 			in the first size bytes of the memory area pointed to by s.
 *
 * @param s    A pointer to the memory area to be searched.
 * @param c    The value to search for (interpreted as an unsigned char).
 * @param size The number of bytes to search.
 * @return     A pointer to the located byte,
 * 				or NULL if no such byte exists within the given size.
 */
void				*ft_memchr(const void *s, int c, size_t size);

/**
 * @brief Allocates memory for an array of nmemb elements, each of size bytes,
 *        and initializes the allocated memory to zero.
 *
 * @param nmemb The number of elements in the array.
 * @param size  The size of each element in bytes.
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
void				*ft_calloc(size_t nmemb, size_t size);

/* ################	*/
/*	Queue function	*/
/* ################	*/

/**
 * @brief Clears the entire queue using the provided deletion function.
 *
 * @param queue A pointer to the queue to be cleared.
 * @param del   The deletion function to be applied to each node's content.
 */
void				ft_clear_queue(t_queue *queue, void (*del)(void *));

/**
 * @brief Removes the first node from the queue and returns its content.
 *
 * @param queue A pointer to the queue.
 * @return The content of the removed node, or NULL if the queue is empty.
 */
void				*ft_dequeue(t_queue *queue);

/**
 * @brief Displays the content of the queue using the provided display function.
 *
 * @param queue   A pointer to the queue to be displayed.
 * @param display The display function to be applied to each node's content.
 */
void				ft_display_queue(t_queue *queue, void (*display)(void *));

/**
 * @brief Duplicates the given queue.
 *
 * @param queue A pointer to the queue to be duplicated.
 * @return A pointer to the newly duplicated queue.
 */
t_queue				*ft_dup_queue(t_queue *queue);

/**
 * @brief Adds a new node to the back of the queue.
 *
 * @param queue   A pointer to the queue.
 * @param content The content to be added to the queue.
 */
void				ft_enqueue(t_queue *queue, void *content);

/**
 * @brief Initializes a new queue.
 *
 * @return A pointer to the newly initialized queue.
 */
t_queue				*ft_init_queue(void);

/**
 * @brief Checks if the queue is empty.
 *
 * @param queue A pointer to the queue.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int					ft_is_empty_queue(t_queue *queue);

/**
 * @brief Returns the content of the first node in the queue without removing it.
 *
 * @param queue A pointer to the queue.
 * @return The content of the first node, or NULL if the queue is empty.
 */
void				*ft_peek(t_queue *queue);

/* ################	*/
/*  String Function	*/
/* ################ */

/**
 * @brief Copy double tab from start to end
 *
 * @param tab A pointer to the array of string
 * @param start The start index of the copy
 * @param end The end index of the copy
 *
 * @return A pointer to the newly allocated array of substrings.
 */
char				**ft_copy_tab(char **tab, int start, int end);

/**
 * @brief Concatenates four null-terminated strings s1, s2, s3, and s4.
 * 
 * @param s1 A pointer to the first null-terminated string.
 * @param s2 A pointer to the second null-terminated string.
 * @param s3 A pointer to the third null-terminated string.
 * @param s4 A pointer to the fourth null-terminated string.
 * 
 * @return A pointer to the newly allocated concatenated string.
 */
char				*ft_strjoin4(char *s1, char *s2, char *s3, char *s4);

/**
 * @brief Calculates the length of the given null-terminated string.
 *
 * @param s A pointer to the null-terminated string.
 * @return The length of the string.
 */
size_t				ft_strlen(const char *s);

/**
 * @brief Copies up to size - 1 characters from the null-terminated
 * 			string src to dst, ensuring that the result is null-terminated.
 *
 * @param dst  A pointer to the destination string.
 * @param src  A pointer to the source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string it tried to create,
 * 			excluding the null-terminator.
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Appends the null-terminated string src to the end of dst,
 * 			ensuring that the result is null-terminated.
 *
 * @param dst  A pointer to the destination string.
 * @param src  A pointer to the source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string it tried to create,
 * 			excluding the null-terminator.
 */
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Locates the first occurrence of the character c (converted to a char)
 * 			in the string s.
 *
 * @param s A pointer to the null-terminated string to be searched.
 * @param c The character to search for.
 * @return A pointer to the located character,
 * 			or NULL if the character does not appear in the string.
 */
char				*ft_strchr(const char *s, int c);

/**
 * @brief Locates the last occurrence of the character c (converted to a char)
 * 			in the string s.
 *
 * @param s A pointer to the null-terminated string to be searched.
 * @param c The character to search for.
 * @return A pointer to the located character,
 * 			or NULL if the character does not appear in the string.
 */
char				*ft_strrchr(const char *s, int c);

/**
 * @brief Compares at most the first n bytes of two strings s1 and s2.
 *
 * @param s1 A pointer to the first string.
 * @param s2 A pointer to the second string.
 * @param n  The maximum number of bytes to compare.
 * @return   An integer less than, equal to,
	or greater than zero if s1 is found,
 *           respectively, to be less than, to match, or be greater than s2.
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated string to_find
 *  				in the string str,
					where not more than len characters are searched.
 *
 * @param str      A pointer to the string to be searched.
 * @param to_find  A pointer to the null-terminated string to search for.
 * @param len      The maximum number of characters to search.
 * @return         A pointer to the located substring,
 * 					or NULL if the substring is not found.
 */
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);

/* ########################	*/
/*  String Part 2 Function	*/
/* ########################	*/

/**
 * @brief Duplicates the given null-terminated string s.
 *
 * @param s A pointer to the null-terminated string to be duplicated.
 * @return A pointer to the newly allocated duplicate string.
 */
char				*ft_strdup(const char *s);

/**
 * @brief Duplicates the first n bytes of the given null-terminated string s.
 *
 * @param s A pointer to the null-terminated string to be duplicated.
 * @param n The number of bytes to duplicate.
 * @return A pointer to the newly allocated duplicate string.
 */
char				*ft_strndup(const char *s, size_t n);

/**
 * @brief Skip whitespace in the string to the first non-whitespace character.
 *
 * @param prompt A pointer to the null-terminated string to be skipped.
 * @param i The index of the string
 * @return The index of the first non-whitespace character.
 */
int					ft_skip_whitespaces(const char *prompt, int i);

/**
 * @brief Extracts a substring from the given null-terminated string s.
 *
 * @param s     A pointer to the null-terminated string
 * 				to extract the substring from.
 * @param start The starting index of the substring.
 * @param len   The maximum length of the substring.
 * @return A pointer to the newly allocated substring.
 */
char				*ft_substr(const char *s, unsigned int start, size_t len);

/**
 * @brief Concatenates two null-terminated strings s1 and s2.
 *
 * @param s1 A pointer to the first null-terminated string.
 * @param s2 A pointer to the second null-terminated string.
 * @return A pointer to the newly allocated concatenated string.
 */
char				*ft_strjoin(const char *s1, const char *s2);

/**
 * @brief Trims leading and trailing characters from the given
 * 				null-terminated string s based on the characters in the set.
 *
 * @param s   A pointer to the null-terminated string to be trimmed.
 * @param set A pointer to the null-terminated string containing
 * 				the characters to trim.
 * @return A pointer to the newly allocated trimmed string.
 */
char				*ft_strtrim(const char *s, const char *set);

/**
 * @brief free all case of tab alloc by split function
 *
 * @param tab A pointer to the null-terminated array of strind
 */
void				ft_rm_split(char **tab);

/**
 * @brief Splits the given null-terminated string s into an array
 * 			of substrings based on the delimiter c.
 *
 * @param s A pointer to the null-terminated string to be split.
 * @param c The delimiter character.
 * @return A pointer to the newly allocated array of substrings.
 */
char				**ft_split(const char *s, char c);

/**
 * @brief Applies the given function f to each character of
 * 			the null-terminated string s,
 *        creating a new string with the results.
 *
 * @param s A pointer to the null-terminated string to be mapped.
 * @param f The function to apply to each character.
 * @return A pointer to the newly allocated mapped string.
 */
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the given function f to each character of
 * 			the null-terminated string s,
 *        providing the index of each character.
 *
 * @param s A pointer to the null-terminated string to be iterated.
 * @param f The function to apply to each character.
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/* ####################	*/
/*  Integer Function	*/
/* ####################	*/

/**
 * @brief Converts the initial portion of
 * 			the null-terminated string str to a double.
 *
 * @param str A pointer to the null-terminated string to be converted.
 * @return The converted double value or -1 if the conversion fails.
 */
double				ft_strtod(const char *str);

/**
 * @brief Coverts the initial portion of
 * 			the null-terminated string to an long integer
 *
 * @param str A pointer to the null-terminated string to be converted.
 * @return The converted long integer value.
 */
long				ft_atol(const char *str);

/**
 * @brief Converts the initial portion of
 * 			the null-terminated string str to an integer.
 *
 * @param str A pointer to the null-terminated string to be converted.
 * @return The converted integer value.
 */
int					ft_atoi(const char *str);

/**
 * @brief Converts an integer to a null-terminated string.
 *
 * @param nb The integer to be converted.
 * @return A pointer to the newly allocated string representing the integer.
 */
char				*ft_itoa(int nb);

/* ################	*/
/*  Write Function	*/
/* ################	*/

/**
 * @brief Outputs a single character to the specified file descriptor.
 *
 * @param c The character to be printed.
 * @param fd The file descriptor where the character will be written.
 */
void				ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs a string to the specified file descriptor.
 *
 * @param s The string to be printed.
 * @param fd The file descriptor where the string will be written.
 */
void				ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs a string followed by newline to the specified file descriptor.
 *
 * @param s The string to be printed.
 * @param fd The file descriptor where the string and newline will be written.
 */
void				ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs an integer to the specified file descriptor.
 *
 * @param n The integer to be printed.
 * @param fd The file descriptor where the integer will be written.
 */
void				ft_putnbr_fd(int n, int fd);

#endif