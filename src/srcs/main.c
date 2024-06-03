#include "bof.h"

t_pin	get_pin()
{
	FILE	*urandom;
	t_pin	pin;

	urandom = fopen("/dev/urandom", "r");
	if (urandom == NULL) {
		printf("Failed to open /dev/urandom\n");
		exit(1);
	}

	if (fread(pin.b, sizeof(char), 4, urandom) != 4) {
		printf("Failed to read from /dev/urandom\n");
		fclose(urandom);
		exit(1);
	}
	fclose(urandom);

	return (pin);
}

int	check_pin(u_int32_t pin)
{
	if (pin == get_pin().u)
	{
		puts("Access granted.\n");
		system("/bin/sh");
		return (0);
	}
	puts("Access denied.\n");
	return (1);
}

int	main(void)
{
	char	user[64];
	t_pin	password;

	memset(user, 0, sizeof(user));
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);


	printf("Shoutout at the user of the day: user_%llx\n", main);

	printf("Enter your username: ");
	read(0, user, 0x64);

	printf("Hello %s, what's your pin?\n", user);
	read(0, password.b, 0x64);
	
	check_pin(password.u);

	return (0);
}
