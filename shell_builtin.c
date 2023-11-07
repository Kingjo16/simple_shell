#include "memory.h"

int exit_shell(shell_data *data)
{
	int ch_exi;

	if (data->argu_val[1])
	{
		ch_exi = string_to_int(data->argu_val[1]);
		if (ch_exi == -1)
		{
			data->status = 2;
			error_message(data, "Illegal number: ");
			print_str(data->argu_val[1]);
			print_char('\n');
			return (1);
		}
		data->num_error = string_to_int(data->argu_val[1]);
		return (-2);
	}
	data->num_error = -1;
	return (-2);
}

