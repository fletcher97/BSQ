
int main(int argc, char const *argv[])
{
	int i;

	i = 0;
	if (argc == 1)
		solve(1);
	else if (argc >= 2)
		while (++i < argc)
			solve(open(argv[i]));
	return 0;
}
