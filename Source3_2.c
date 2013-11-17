#include <stdio.h>

#define MAX_CHARS 1000

void escape(char s [], char t [])
{
	int i = 0, j = 0;
	while (t[i] != '\0')
	{
		switch (t[i])
		{
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		default:
			s[j++] = t[i];
		}
		i++;
	}
	s[j] = '\0';
}

void unEscape(char t [], char s [])
{
	int i = 0, j = 0;
	while (s[i] != '\0')
	{
		switch (s[i])
		{
		case '\\':
			if (s[i + 1] == 'n')
				t[j] = '\n';
			else if (s[i + 1] == 't')
				t[j] = '\t';
			else
			{
				t[j] = '\\';
				i--;
			}
			j++;
			i += 2;
			break;
		default:
			t[j++] = s[i++];
			break;
		}
	}
	t[j] = '\0';
}

/*
    Exercise 3 - 2. Write a function escape(s, t) that converts characters like newline and tab into
  	visible escape sequences like \n and \t as it copies the string t to s.Use a switch.
  	Write a function for the other direction as well, converting escape sequences into the real characters.
*/
void ex3_2()
{
	char s[MAX_CHARS], t[MAX_CHARS];
	int c = 0, i = 0;
	while ((c = getchar()) != EOF)
	{
		t[i++] = c;
	}
	t[i] = '\0';

	escape(s, t);
	printf("escaped string:\n%s\n", s);
	unEscape(t, s);
	printf("unescapes string:\n%s\n", t);
}

main()
{
	ex3_2();
	printf("\nPress ENTER to continue. . .\n");
	getchar();
}
