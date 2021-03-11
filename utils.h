enum ACTION
{
	SPIN_THE_WHEEL = 1,
	BUY_VOWEL,
	GUESS,
	INCORRECT_ACTION
};
enum LETTER
{
	VOWEL,
	CONSONANT
};
enum PLAYER
{
	COMPUTER_PLAYER_1,
	COMPUTER_PLAYER_2,
	HUMAN_PLAYER
};
int count_letters(const char tab[]);
void guess_puzzle(const char tab[], const char category[], char tab2[], enum PLAYER player);
enum ACTION choose_action(const char tab[], int money, enum PLAYER player);
char choose_letter(const char tab[], enum LETTER kind, enum PLAYER player);
int absl(char c);
int litera(char c);
int samogl(char c);
char *hidden_key(char key[]);

