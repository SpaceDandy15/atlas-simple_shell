#include "shell.h"

/**
 * _currentenv - print out the current environment
 * @info: struct that containts potential arugments 
 * that can be used to maintain constant function of prototype.
 * Return: Always 0
*/
int _currentenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value an environm variable
 * @info: Structure containing potential arguments.
 * @name: env var name
 *
 * Return: the value
*/
char *_getenv(info_t *info, const char *name *value);
{
	list_t *node = info-env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
		return (p);
		node = node->next;
	}
	return (NULL):
}

/**
 * _setenv - Initialize a new environment variable,
 * or it can modify an existing one
 * @info: Structure containing possible arguments. 
 * Return: Always 0
*/
int _setenv(info_t *info, const char *name, const char *value)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	return (0);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments.
 * Return: Always 0
*/
int _unsetenv(info_t *info, const char *name, const char *value)
{
	if (info->argc < 2)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	return (0);
}
