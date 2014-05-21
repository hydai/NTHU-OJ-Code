#include <stdio.h>
int main() {
	const char mos[][15] = {
			".-", "-...", "-.-.", "-..", ".", "..-.", "- -.", "....", "..", ".- - -",
			"-.-", ".-..", "- -", "-.", "- - -", ".- -.", "- -.-", ".-.", "...", "-",
			"..-", "...-", ".- -", "-..-", "-.- -", "- -..", "- - - - -", ".- - - -",
			"..- - -", "...- -", "....-", ".....", "-....", "- -...", "- - -..", "- - - -.",
			".-.-.-", "- -..- -", "..- -..", ".- - - -.", "-.-.- -", "-..-.", "-.- -.",
			"-.- -.-", ".-...", "- - -...", "-.-.-.", "-...-", ".-.-.", "-....-", "..- -.-",
			".-..-.", ".- -.-."
	};
	const char ascii[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
			'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4',
			'5', '6', '7', '8', '9', '.', ',', '?', '\''. '!', '/', '(', ')', '&', ':', ';', '=',
			'+', '-', '_', '\"', '@'
	};
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Message #%d\n", i);
		char tmp[15];
		scanf("%s", tmp);
		for (int j = 0; j < 53; j++) {
			if (!strcmp(tmp, mos[j])) {
				putchar(ascii[j]);
				break;
			}
		}

		if (getchar() == '\n')
			break;
	}
}
