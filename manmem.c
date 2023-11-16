#include "shell.h"

/**
 *_reallocate -  Reallocates A Memory Block Using Malloc And Free
 *@pointer: Pointer
 *@small_amount: Previous Size Of The Pointer
 *@big_amount: New Size Of The Pointer
 *This function reallocates a memory block
 * pointed to by `ptr` to a new size `new_size`.
 * It transfers the data from the old
 * memory block to the new one and frees the old memory block.
 *Return: Void Pointer Rellocated Memory
 */
void *_reallocate(void *pointer, unsigned int small_amount, unsigned int big_amount)
{
	void *result;

	if (big_amount == small_amount)
		return (pointer);
	if (big_amount == 0 && pointer)
	{
		free(pointer);
		return (NULL);
	}
	result = malloc(big_amount);
	if (result == NULL)
		return (NULL);
	if (pointer == NULL)
	{
		occupy_array(result, '\0', big_amount);
		free(pointer);
	}
	else
	{
		mem_duplicate(result, pointer, small_amount);
		free(pointer);
	}
	return (result);

}
/**
 * release_all - Free Array Of Char Pointer And Char Pointer
 * @cmd:Array Pointer
 * @line:Char Pointer
 * This function frees the memory occupied by the
 * array of char pointers (`cmd`) and the char pointer(line)
 * Return: Void
 */
void release_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * mem_duplicate - Copy Byte From Source To Destination
 * @est: Destination Pointer
 * @srcy: Source Pointer
 * @m: Size (How Much You Will Copy)
 * This function copies `n` bytes from the source memory area
 *Return: Void Pointer
 */
char *mem_duplicate(char *est, char *srcy, unsigned int m)
{
	unsigned int i;

	for (i = 0; i < m; i++)
	{
		est[i] = srcy[i];
	}
	return (est);
}
/**
 * occupy_array - Fill An Array By Constant Byte
 * @z:Void Pointer
 * @ty: Int
 * @width:Length Int
 * This function fills the array pointed to by
 * `a` with the constant byte value `el`.
 *Return: Void Pointer
 */
void *occupy_array(void *z, int ty, unsigned int width)
{
	char *p = z;
	unsigned int i = 0;

	while (i < width)
	{
		*p = ty;
		p++;
		i++;
	}
	return (z);
}
/**
 * _calloc -  Allocates Memory For An Array, Using Malloc.
 * @size: Size
 *  This function allocates memory for an array of
 *  `size` bytes using `malloc`.
 * The allocated memory is filled with zeros.
 * Return: Void Pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
