#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"

int count_letters(const char tab[])
{
	return 0;
}
void guess_puzzle(const char tab[], const char category[], char tab2[], enum PLAYER player)
{
    strcpy(tab2,tab);
}
enum ACTION choose_action(const char tab[], int money,enum PLAYER player)
{
  int a=0,flag=0;

  if(player==HUMAN_PLAYER)
  {
    while(flag==0)
    {
      printf("Wybierz opcje:\n1.Zakrec kolem\n2.Zakup samoglaske\n3.Zgaduj haslo\n");
      if(scanf("%d",&a)!=1) while(getchar()!='\n');

      else if(a<SPIN_THE_WHEEL || a>GUESS)
      {
        printf("Wybrano niepoprawna akcje\n");
        continue;
      }
      else if(a==BUY_VOWEL && money<250)
      {
        printf("Brak wystarczajacych pieniedzy\n");
        continue;
      }
      else flag=1;
    }
    getchar();
  }
  
  return a;
}
char choose_letter(const char tab[], enum LETTER kind, enum PLAYER player)
{
    return 0;
}
int litera(char c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int absl(char c)
{
  if(c >= 'A' && c <= 'Z') return (c - 'A') + 'a';
}

int samogl(char c)
{
  c = absl(c);
  return c == 'a' || c == 'o' || c == 'e' || c == 'u' || c == 'i' || c == 'y';
}
char *hidden_key(char key[])
{
    for(int i = 0; i < strlen(key); i++)
    {
       if(litera(key[i]))
       {
         key[i] = '_';
       }
     }
     return key;
}
