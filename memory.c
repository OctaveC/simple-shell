#include "shell-header.h"

void free_prm(prm_t *prm)
{
	while(prm != NULL)
	{
		free(prm->token_array);
		free(prm->buffer);
		free(prm);
	}
}
