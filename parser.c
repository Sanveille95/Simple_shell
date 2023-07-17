#include "shell.h"
/**
 * is_a_path - checks if the given filename is a path
 * @data: data struct pointer
 * Return: (Success), otherwise (Fail)
 */
int is_a_path(sh_t *data)
{
	if (_strchr(data->args[0], '/') != 0)
	{
		data->cmd = _strdup(data->args[0]);
		return (SUCCESS);
	}
	return (FAIL);
}
#define DELIMITER ":"

/**
 * is_short_form - checks if the given filename is short form
 * @data: data struct pointer
 * Return: (Success), otherwise (Fail)
 */
void is_short_form(sh_t *data)
{
	char *path, *tok, *_path;
	struct stat st;
	int ext_flag = 0;

	path = _getenv("PATH");
	_path = _strdup(path);
	tok = strtok(_path, DELIMITER);
	while (tok)
	{
		data->cmd = _strcat(tok, data->args[0]);
		if (stat(data->cmd, &st) == 0)
		{
			ext_flag += 1;
			break;
		}
		free(data->cmd);
		tok = strtok(NULL, DELIMITER);
	}
	if (ext_flag == 0)
	{
		data->cmd = _strdup(data->args[0]);
	}
	free(_path);
}
#undef DELIMITER

/**
 * cmd_is_builtin - checks if the command is builtin
 * @data: pointer to the data structure
 * Return: 0 (Success), negative number (Fail)
 */
int cmd_is_builtin(sh_t *data)
{
	blt_t blt[] = {
		{"exit", abort_prg},
		{"cd", change_dir},
		{"help", display_help},
		{NULL, NULL}
	};
	int i = 0;

	while ((blt + i)->cmd)
	{
		if (_strcmp(data->args[0], (blt + i)->cmd) == 0)
			return (SUCCESS);
		i++;
	}
	return (NEUTRAL);
}
