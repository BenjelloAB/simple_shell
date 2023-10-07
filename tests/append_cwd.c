#include "main.h"

void append_cwd(char *cmd)
{
	char cwd[MAX_PATH_LEN];
	int i, j;

	/* If the first character is '.', the path is already relative */
	if (cmd[0] == '.')
	{
		return;
	}

	getcwd(cwd, sizeof(cwd));

	for (i = 0; cwd[i] != '\0'; i++)
		;

	cwd[i++] = '/';

	for (j = 0; cmd[j] != '\0'; j++)
	{
		cwd[i + j] = cmd[j];
	}

	cwd[i + j] = '\0';

	for (i = 0; cwd[i] != '\0'; i++)
	{
		cmd[i] = cwd[i];
	}

	cmd[i] = '\0';
}
