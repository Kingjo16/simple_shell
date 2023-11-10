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
int comd_line(shell_data *data)
{
	int get_r;
	char *str,*m, buf[1024];

	str = getcwd(buf, 1024);

	if (!str)
		_prints("TODO: >>getcwd failure emsg here<<\n");
	if (!data->argu_val[1])
	{
		m = env_check(data, "HOME=");
		if (!m)
			get_r = /*think of something to add */
				chdir((m = env_check(data, "PWD=")) ? m : "/");
		else
			get_r = chdir(m);
	}
	else if (compar_str(data->argu_val[1], "-") == 0)
	{
		if (!env_check(data, "OLDPWD="))
		{
			_prints(str);
			_printchar('\n');
			return (1);
		}
		_prints(env_check(data, "OLDPWD=")),_printchar('\n');
		get_r = /*sth to add */
			chdir((m = env_check(data, "OLDPWD=")) ? m : "/");
	}
	else
		get_r = chdir(data->argu_val[1]);
	if (get_r == -1)
	{
		error_message(data, "can't cd to ");
		print_str(data->argu_val[1]), print_char('\n');
	}
	else
	{
		env_set(data, "OLDPWD", env_check(data, "PWD="));
		env_set(data, "PWD", getcwd(buf, 1024));;
	}
	return (0);

}
char *env_check(shell_data *data, const char *inputs)
{
	node_list *knob = data->envir;
	char *q;

	while (knob)
	{
		q = _starting(knob->str_t, inputs);
		if (q && *q)
			return (q);
		knob = knob->next;
	}
	return (NULL);
}
int help_center(shell_data *data)
{
	char **given_a;

	given_a = data->argu_val;
	_prints("help call works.FUunction not yet implemented \n");
	if (0)
		_prints(*given_a);
	return (0);
}
