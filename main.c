#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"
enum PLAYER;



int main(void)
{
  char tab[10]={0};
  const char* database = "Titles|Robinson Crusoe|Alice's Adventures in Wonderland|Heart of Darkness|The Lord of the Rings|Game of Thrones|House of Cards^Quotes|Two wrongs don't make a right|When in Rome, do as the Romans|Hope for the best, but prepare for the worst|Keep your friends close and your enemies closer^Names|William Shakespeare|John Kennedy|Sherlock Holmes|Martin Luther King|Friedrich Nietzsche^Proverbs|He who does not advance goes backwards|If you can't beat them, join them|Don't judge a book by its cover|A broken watch is right two times a day|The best defence is a good offence|No man can serve two masters";

  srand(time(NULL));

  char copy[5000];
  strcpy(copy, database);

  char category[4][20][100] = {0};
  char keys[4][50] = {0};
  int counter_keys = 1;
  int counter_category = 0;
  int counter_word = 0;
  char *tok = strtok(copy, "|");

  strcpy(keys[0], tok);
  tok = strtok(NULL, "|");

  while(tok != NULL)
      {
      char *division = strrchr(tok, '^');
      if(division == NULL)
      {
        strcpy(category[counter_category][counter_word], tok);
        counter_word++;
      }
      else
      {
         *division = '\n';
         strcpy(category[counter_category]  [counter_word], tok);
         strcpy(keys[counter_keys], division+1);

         counter_keys++;
         counter_category++;
         counter_word = 0;
      }
      tok = strtok(NULL, "|");
  }

  int len[4] = {0};
  for(int i=0;i<4;i++)
  {
    int j = 0;
    while(category[i][j][0] != 0)j++;
    len[i] = j;
  }
 
    int awards[] = {25, 50, 75, 100, 125, 150, 175, 200, 225, 250, 275, 300, 325, 350, 375, 400, 425, 450, 475, -1, -1, -1,-2,-2};
    int awards_lenght = 24;

   char menu[] = "Wybierz opcje:\n1.Zakrec kolem\n2.Zakup samoglaske\n3.Zgaduj haslo\n";
   int round = 1;
   int player = 0;
   int points[3] = {0};
   int number_players=0;
     printf("\n----Kolo Fortuny----\n\n");
     printf("\nKwoty do uzyskania:25, 50, 75, 100, 125, 150, 175, 200, 225, 250, 275, 300, 325, 350, 375, 400, 425, 450, 475\n\nNa trzech polach kola jest bankrut oraz na dwóch utrata kolejki\n\n");
     printf("podaj liczbe graczy: ");
     if(scanf("%d",&number_players)!=1)
     {
         printf("Incorrect input\n");
         return 1;
     }
     if(number_players<1 || number_players>3)
     {
         printf("\npodaj jeszcze raz liczbe graczy(1,2 lub 3): ");
         scanf("%d",&number_players);
     }
    while(round <= 3)
    {
     int number_category = rand() % 4;
     int number_key = rand() % (len[number_category]);
     char key[100];
     strcpy(key, category[number_category][number_key]);
     char hidden_keys[100];
     strcpy(hidden_keys, key);
     
      int key_guessed = 0;
     while(!key_guessed)
     {
      char drawn_letters[40] = {0};
      hidden_key(hidden_keys);
      printf("\nRunda %d\nKategoria: %s\n\n%s\n\n", round, keys[number_category], hidden_keys);
     
       printf("Punkty: \n");
       for(int i = 0; i < 3; i++) printf("Gracz %d: %d\n",i+1,points[i]);
    
       printf("\nGracz %d\n-------------------\n", player+1);
       int variable=choose_action(tab,0,HUMAN_PLAYER);
       int prize = awards[rand() % 24];
       char check_letter = 0;
       int correct=0;
      switch(variable)
      {
        case SPIN_THE_WHEEL:
            {
                if(prize == -1)
                    {
                        player = (player + 1) % 3;
                        printf("utrata kolejki\n");
                        continue;
                    }
                else if(prize == -2)
                    {
                        printf("Bankrut\n");
                        points[player] = 0;
                        player = (player + 1) % 3;
                        continue;
                    }
        char consonant;
        printf("Nagroda: %d\nPodaj samogloske: ", prize);
        while(!(correct = scanf("%c", &consonant)) ||!correct || !litera(consonant))
          {
            scanf("%*c");
            printf("Podaj litere jeszcze raz\n");
          }
          int valid = 1;
          valid *= !samogl(consonant);
          for(int i = 0; i < 40; i++)
            {
                if(drawn_letters[i]  > 0 && (i == absl(consonant)-'a'))
                    {
                        valid = 0;
                        drawn_letters[i] = 1;
                    }
            }
          if(valid == 0)
            {
                player = (player + 1) % 3;
                printf("koniec kolejki\n");
                continue;
            }
          check_letter = consonant;
        } break;
        case BUY_VOWEL:
        {
          if(points[player] >= 250)
            {
                points[player] -= 250;
            if(prize == -1)
                {
                    player = (player + 1) % 3;
                    printf("utrata kolejki\n");
                    continue;
                }
            else if(prize == -2)
                {   
                    printf("Bankrut\n");
                    points[player] = 0;
                    player = (player + 1) % 3;
                    continue;
                }
            char vowel;
            printf("Podaj samogloske: ");
            while(!(correct = scanf("%c", &vowel)) || !correct || !litera(vowel) || !samogl(vowel))
            {
              scanf("%*c");
              printf("Podaj litere jeszcze raz\n");
            }
            int valid = 1;
            for(int i = 0; i < 40; i++)
            {
              if(drawn_letters[i]  > 0 && (i == absl(vowel)-'a'))
                {
                    valid = 0;
                    drawn_letters[i] = 1;
                }
            }
            if(valid == 0)
                {
                    player = (player + 1) % 3;
                    printf("koniec kolejki\n");
                    continue;
                }
            check_letter = vowel;
          }
          else
          {
            printf("Nie masz tyle pieniedzy zeby kupic samogloske\n");
            continue;
          }
        }break;
        case GUESS:
        {
          printf("Podaj haslo: ");
          char key_entered[100];
          fgets(key_entered, 100, stdin);
          int k=strlen(key_entered)-1;

          if(key_entered[k] == '\n') key_entered[k] = '\n';

          char copy_key[100];
          strcpy(copy_key, key);
          int l = 0;

          while(copy_key[l] = absl(copy_key[l]), copy_key[k]) k++;
          l = 0;
          while(key_entered[l] = absl(key_entered[l]), key_entered[l]) l++;

          if(strcmp(key_entered, copy_key) == 0)
          {
            points[player] += 1000;
            printf("Haslo odgadniete\n\n");
            key_guessed = 1;
            round++;
          }
          else
          {
            printf("Haslo nie odgadniete\n\n");
              player = (player + 1) % 3;
              printf("koniec kolejki\n\n");
          }
        }
      }
     

      if(check_letter > 0)
      {
        int counter2 = 0;
        int number_instances = 0;
        while(key[counter2] != '\n')
        {
          if(absl(key[counter2]) == absl(check_letter))
          {
            hidden_keys[counter2] = key[counter2];
            number_instances++;
          }
          counter2++;
        }
        if(number_instances > 0)
        {
          points[player] += prize;
        }
        else
        {
            player = (player + 1) % 3;
            printf("koniec kolejki");
        }
        if(strcmp(hidden_keys, key) == 0 && !key_guessed)
        {
          key_guessed = 1;
          printf("Haslo odgadniete\n");
          round++;
        }
      }
    }
  }

  return 0;
}

