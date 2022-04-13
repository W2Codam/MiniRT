/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 14:00:33 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/12 13:58:29 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//= Function count: 56 =//
//= NOTE: Only malloc(), free() & write() are allowed/necessary!!! =//
//= TODO: Add dynamic sizeable strings & arrays =//

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# define BUFF_SIZE	5120
# define FD_MAX		1024

//= Types =//

typedef struct s_fd_data
{
	char	*data;
	bool	read;
}	t_fd_data;

// Single linked list.
typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

// The different types of commonly used bases.
typedef enum e_base
{
	BINARY = 2,
	OCTAL = 8,
	DECIMAL = 10,
	HEXADECIMAL = 16
}	t_base;

//= GNL =//

/**
 * Reads the given file for a single line. Each next call gives the next line.
 * @param fd The file descriptor to read from.
 * @returns NULL if nothing read or error, else the line.
 */
char	*ft_get_next_line(int32_t fd);

//= Character Utils =//

/** 
 * Checks whether a given char is a valid ASCII character.
 * @param c The character to test.
 * @returns Whether c is a valid ASCII character or not.
 */
bool	ft_isascii(int32_t c);

/** 
 * Checks whether a given char is a valid alphabetical character.
 * @param c The character to test.
 * @returns Whether c is a valid alphabetical character or not.
 */
bool	ft_isalpha(int32_t c);

/** 
 * Checks whether a given char is a valid digit.
 * @param c The character to test.
 * @returns Whether c is a digit character or not.
 */
bool	ft_isdigit(int32_t c);

/** 
 * Checks whether a given character is a valid alphanumeric character.
 * @param c The character to test.
 * @returns Whether c is an alphanumeric character or not.
 */
bool	ft_isalnum(int32_t c);

/** 
 * Checks whether a given character is any whitespace character.
 * @param c The character to test.
 * @returns Whether c is a whitespace character.
 */
bool	ft_isspace(int32_t c);

/** 
 * Checks whether a given character is a valid, printable character.
 * @param c The character to test.
 * @returns Whether c is a valid, printable character.
 */
bool	ft_isprint(int32_t c);

/** 
 * Checks whether a given character is in uppercase
 * @param c The character to test.
 * @returns Whether c is in uppercase.
 */
bool	ft_isupper(int32_t c);

/** 
 * Checks whether a given character is in lowercase
 * @param c The character to test.
 * @returns Whether c is in lowercase.
 */
bool	ft_islower(int32_t c);

/** 
 * Converts the given alphabetical character to uppercase.
 * @param c The character to convert.
 * @returns The character in uppercase.
 */
int32_t	ft_toupper(int32_t c);

/** 
 * Converts the given alphabetical character to lowercase.
 * @param c The character to convert.
 * @returns The character in lowercase.
 */
int32_t	ft_tolower(int32_t c);

//= Int Utils =//

/** 
 * Returns the number of digits depending on the base in a given base.
 * @param n The int to test.
 * @param base The base to use.
 * @returns The int converted to a string, or Null.
 */
int32_t	ft_intlen(int32_t n, t_base base);

//= Converters =//

/** 
 * Converts a given string to an integer, any failure will return 0.
 * @param str The string to convert.
 * @returns The string converted to an int, or 0.
 */
int32_t	ft_atoi(const char *str);

/** 
 * Converts a given integer to a string, any failure will return Null.
 * @note nbr = (nbr * 10) + (str[i++] - '0');
 * @param n The int to convert.
 * @returns The int converted to a string, or Null.
 */
char	*ft_itoa(int32_t n);

/** 
 * Converts a given integer to a string, any failure will return Null.
 * @note Take num % base, then /= base, remainder is index, reverse loop!
 * @see https://bit.ly/2UA4CmX
 * @param n The int to convert.
 * @param base The base to use for conversion.
 * @returns The int converted to a string, or Null.
 */
char	*ft_itoa_base(int32_t n, t_base base);

//= String Utils =//

/** 
 * Appens s2 to s1 (assuming they are heap allocated!).
 * @param s1 A heap allocated string.
 * @param s2 A heap allocated string.
 * @returns s1 with s2 appended to it, in a new string.
 */
char	*ft_strapp(char const *s1, char const *s2);

/** 
 * Iterates over the string and makes every possible char to uppercase.
 * @param str The string.
 * @returns The string itself.
 */
void	ft_strtoupper(char *str);

/** 
 * Iterates over the string and makes every possible char to lowercase.
 * @param str The string.
 * @returns The string itself.
 */
void	ft_strtolower(char *str);

/** 
 * Retrieves the length of a given string.
 * @param str The string.
 * @returns The size of the given string.
 */
size_t	ft_strlen(const char *str);

/** 
 * Retrieves the length of a given string up to a given character.
 * @param str The string.
 * @param c The char to count up until to.
 * @returns The size of the given string.
 */
size_t	ft_strclen(const char *str, char c);

/** 
 * Returns ptr to the first occurence of the given char. Starting from the front.
 * @param s The string.
 * @param c The character to look for.
 * @returns Pointer to the first occurence of the given char.
 */
char	*ft_strchr(const char *s, int32_t c);

/** 
 * Returns ptr to the first occurence of the given char. Starting from the back.
 * @param s The string.
 * @param c The character to look for.
 * @returns Pointer to the first occurence of the given char.
 */
char	*ft_strrchr(const char *s, int32_t c);

/** 
 * Counts the number of occurences of a given char in a string.
 * @param str The string
 * @param c The char to count for.
 * @returns The number of occurences of the given delimiter.
 */
int32_t	ft_strchrn(const char *str, char c);

/** 
 * Compares the two given strings up until n.
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n Limiter, as in, compare up to n chars.
 * @returns 0 if equal > or < than 0 if not equal.
 */
int32_t	ft_strncmp(const char *s1, const char *s2, size_t n);

/** 
 * Copy the string from src to dst, secure from buffer overflows 
 * using the full size of the destination string as a size parameter.
 * @param dst The destination string to copy to.
 * @param src The source string to copy from.
 * @param size The size of dst.
 * @returns The total length of the string they tried to create.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/** 
 * Concatonate the string from src to dst, secure from buffer overflows 
 * using the full size of the destination string as a size parameter.
 * @param dst The destination string to copy to.
 * @param src The source string to copy from.
 * @param size The size of dst.
 * @returns The total length of the string they tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/** 
 * Searches for the first occurence of the little string in big.
 * @param big The source string to search in.
 * @param little The string we are searching for in big.
 * @param ln Length of big.
 * @returns Ptr to the first occurence of little in big, else null.
 */
char	*ft_strnstr(const char *big, const char *little, size_t ln);

/** 
 * Duplicates a given string, with an allocation.
 * @param s1 The string to duplicate.
 * @returns Ptr to the newly allocated duplicate string.
 */
char	*ft_strdup(const char *s1);

/** 
 * Reverses a string by modifying it.
 * @param str The string to reverse.
 * @returns Ptr to the string itself.
 */
char	*ft_strrev(char *str);

/** 
 * Allocates and returns a substring from the string ’s’.
 * @param s The string from which to create the substring.
 * @param start  The start index of the substring in the string ’s’
 * @param len The maximum length of the substring.
 * @returns The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, uint32_t start, size_t len);

/** 
 * Allocates and returns a new string, which is the result of 
 * the concatenation of ’s1’ and ’s2’.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @returns The string result of the concatenation of the two strings.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/** 
 * Allocates and returns a copy of ’s1’ with the characters specified in ’set’,
 * removed from the beginning and the end of the string.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @returns The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * Checks if a string is just empty spaces.
 * 
 * @param str The string to check.
 * @return True if the string is only spaces, false otherwise.
 */
bool	ft_isempty(const char *str);

/** 
 * Allocates and returns an array of strings obtained by 
 * splitting ’s’ using the character ’c’ as a delimiter. 
 * 
 * NOTE:
 *  - Malloc N amount of char*'s per string that is between a delimiter.
 *  - Malloc N amount of chars per that string's length.
 *  - Return out.
 * 
 * The array ends with a NULL pointer.
 * @param s The string to be split.
 * @param c The char delimiter.
 * @returns A string array.
 */
char	**ft_split(char const *s, char c);

/** 
 * Applies the function ’f’ to each character of the 
 * string ’s’ to create a new string resulting 
 * from successive applications of ’f’.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @returns The string created from the successive applications of ’f’. 
 * Returns NULL if the allocation fails.
 */
char	*ft_strmap(char const *s, char (*f)(char));

/** 
 * Applies the function ’f’ to each character of the 
 * string ’s’ to create a new string resulting 
 * from successive applications of ’f’.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @returns The string created from the successive applications of ’f’. 
 * Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(uint32_t, char));

/** 
 * Applies the function f to each character of the 
 * string passed as argument, and passing its index as first argument. 
 * Each character is passed by address to f to be modified if necessary.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striter(char *s, void (*f)(char *));

/** 
 * Applies the function f to each character of the 
 * string passed as argument, and passing its index as first argument. 
 * Each character is passed by address to f to be modified if necessary.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(uint32_t, char *));

//= IO Utils =//

/** 
 * Prints out a given char to standart output.
 * @param c The character to write.
 */
void	ft_putchar(char c);

/** 
 * Prints out a given char to a given file descriptor.
 * @param c The character to write.
 * @param fd The file descriptor.
 */
void	ft_putchar_fd(char c, int32_t fd);

/** 
 * Prints out a given number to standart output.
 * @param n The number to write.
 */
void	ft_putnbr(int32_t n);

/** 
 * Prints out a given number to a given file descriptor.
 * @param n The number to write.
 * @param fd The file descriptor.
 */
void	ft_putnbr_fd(int32_t n, int32_t fd);

/** 
 * Prints out a given string to standart output.
 * @param s The string to write.
 */
void	ft_putendl(const char *s);

/** 
 * Prints out a given string to a given file descriptor with a newline.
 * @param s The string to write.
 * @param fd The file descriptor.
 */
void	ft_putendl_fd(const char *s, int32_t fd);

/** 
 * Prints out a given char to standart output.
 * @param s The string to write.
 */
void	ft_putstr(const char *s);

/** 
 * Prints out a given string to a given file descriptor.
 * @param s The string to write.
 * @param fd The file descriptor.
 */
void	ft_putstr_fd(const char *s, int32_t fd);

//= Math Utils =//

/** 
 * Returns the absolute value of a given integer.
 * @param val The value.
 * @returns The value as a positive.
 */
int32_t	ft_abs(int32_t val);

/** 
 * return ((val < 0) * (val) + (val >= 0) * (-val));
 * Returns the negative value of a given integer.
 * @param val The value.
 * @returns The value as a negative.
 */
int32_t	ft_neg(int32_t val);

/** 
 * Returns the minimum value of two given integers.
 * @param valA The left value.
 * @param valB The right value.
 * @returns The smallest value of the two.
 */
int32_t	ft_min(int32_t valA, int32_t valB);

/** 
 * Returns the maximum value of two given integers.
 * @param valA The left value.
 * @param valB The right value.
 * @returns The biggest value of the two.
 */
int32_t	ft_max(int32_t valA, int32_t valB);

/** 
 * Calculates the base multiplied n times depending on the exponent.
 * @param base The base value to calculate the power.
 * @param exp The exponent.
 * @returns The given base by the power of the exponent.
 */
int32_t	ft_pow(int32_t base, int32_t exp);

/** 
 * Calculates the square root of an int.
 * 
 * @param num The number to retrieve the square root from.
 * @returns The square root of num or 0 if irrational.
 */
int32_t	ft_sqrt(int32_t num);

//= Memory Magic =//

/** 
 * Sets all bytes in source to a specified value
 * @param s The source.
 * @param n Size of source.
 */
void	*ft_memset(void *b, int32_t c, size_t len);

/** 
 * Sets all bytes in source to Null.
 * @param s The source.
 * @param n Size of source, in bytes.
 */
void	ft_bzero(void *s, size_t n);

/** 
 * Re-sizes a given memory buffer of a given size to a new size. 
 * Attempts to copy as much as the new size allows it to. 
 * Frees the old buffer.
 * @param ptr The pointer to the buffer.
 * @param old The current size of the buffer.
 * @param new The new desired size for the buffer.
 * @returns The new location for the buffer.
 */
void	*ft_realloc(void *ptr, size_t old, size_t new);

/** 
 * Allocates memory of num objects of size and initializes all bytes to zero.
 * @param num The count of objects to allocate for.
 * @param size The size of the memory that needs to be allocated.
 * @returns The allocated memory area.
 */
void	*ft_calloc(size_t num, size_t size);

/** 
 * Copies no more than n amount of bytes from src to dst.
 * @param dst The destination buffer to which the bytes are copied to.
 * @param src The source buffer from which the bytes are copied from.
 * @param n   The size of source.
 * @returns Ptr to dst buffer.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/** 
 * Moves/copies bytes from src to dst while avoiding overlapping memory. 
 * It does so by checking wether to copy from front or back.
 * @see: https://cs50.stackexchange.com/questions/14615/memory-overlap-in-c
 * @param dst The destination buffer to which the bytes are copied to.
 * @param src The source buffer from which the bytes are copied from.
 * @param len The size of source.
 * @returns Ptr to dst buffer.
 */
void	*ft_memmove(void *dst, const void *src, size_t len);

/**
 * Compares two memory regions against each other.
 * @param s1 Source.
 * @param s2 Target.
 * @param n Size of s1.
 * @returns The difference between the bytes, 0 if equal.
 */
int32_t	ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * Searches & returns for the first occurence of a given byte in source.
 * @param s The source.
 * @param c The byte to search for (will be casted to unsigned char).
 * @param n Up to how many bytes can/should be read.
 * @returns Ptr to the first occurence in source.
 */
void	*ft_memchr(const void *s, int32_t c, size_t n);

//= Linked List =//

/** 
 * Allocates and returns a new element.
 * The variable 'content' is initialized 
 * with the value of the parameter 'content'.
 * The variable 'next' is initialized to NULL.
 * 
 * @param content The data to assign to the node.
 * @returns Pointer to the new list.
 */
t_list	*ft_lstnew(void *content);

/** 
 * Retrieves the size of the list aka
 * count of nodes.
 * @param lst The list.
 */
int32_t	ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

/** 
 * Adds the element 'new' at the beginning of the list.
 * New->A->B->C->D->?
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/** 
 * Adds the element 'new' at the end of the list.
 * ?->A->B->C->D->New
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/** 
 * Deletes the the given element using del.
 * @param lst The list
 * @param del The function used to delete.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/** 
 * Deletes and frees the given element and every 
 * successor of that element, using the function 'del' 
 * and free(3). 
 * Finally, the pointer to the list must be set to NULL.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/** 
 * Iterates the list 'lst' and applies the function 
 * 'f' to the content of each element.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/** 
 * Horrible description...
 * 
 * Iterates the list 'lst' and applies the function 
 * 'f' to the content of each element.
 * 
 * Creates a new list resulting of the successive applications of 
 * the function 'f'.  
 * 
 * The 'del' function is used to delete the content of an element if needed.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
