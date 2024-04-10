#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "generic_vector.h"
#include "AVL.h"

GENERIC_VECTOR *create_dictionary(void);
void string_destroy(ITEM *phString);
ITEM string_init_copy(ITEM hArg);
void clear_keyboard_buffer(void);
int prompt_get_word_length(GENERIC_VECTOR *dictionary);
int prompt_number_guesses(void);
Boolean prompt_running_total(void);
char make_guess(void);
void play_evil_hangman(void);
Boolean prompt_play_again(void);

int main(int agrc, char *argv[])
{

  play_evil_hangman();

	/*MY_STRING old_key1 = my_string_init_c_string("---");
     MY_STRING word1 = my_string_init_c_string("the");
     MY_STRING new_key1 = my_string_init_default();
     get_word_key_value(old_key1, new_key1, word1, 'T');
     printf("%s\n", my_string_c_str(new_key1)); 
    
     MY_STRING old_key2 = my_string_init_c_string("-----");
     MY_STRING word2 = my_string_init_c_string("Truck");
     MY_STRING new_key2 = my_string_init_default();
     get_word_key_value(old_key2, new_key2, word2, 'r');
     printf("%s\n", my_string_c_str(new_key2)); 
     
     MY_STRING old_key3 = my_string_init_c_string("--ppy");
     MY_STRING word3 = my_string_init_c_string("happy");
     MY_STRING new_key3 = my_string_init_default();
     get_word_key_value(old_key3, new_key3, word3, 'h');
     printf("%s\n", my_string_c_str(new_key3));
     
     MY_STRING old_key4 = my_string_init_c_string("--e---e");
     MY_STRING word4 = my_string_init_c_string("awesome");
     MY_STRING new_key4 = my_string_init_default();
     get_word_key_value(old_key4, new_key4, word4, 'z');
     printf("%s\n", my_string_c_str(new_key4)); 
     
     
     my_string_destroy(&new_key1);
     my_string_destroy(&old_key1);
     my_string_destroy(&word1);
     
     my_string_destroy(&new_key2);
     my_string_destroy(&old_key2);
     my_string_destroy(&word2);
     
     my_string_destroy(&new_key3);
     my_string_destroy(&old_key3);
     my_string_destroy(&word3);
     
     my_string_destroy(&new_key4);
     my_string_destroy(&old_key4);
     my_string_destroy(&word4);*/
    

	return 0;
}

void play_evil_hangman(void)
{
	do
	{
		int i;

		// Cool logo for game intro
		printf("╔═══╗───╔╗─╔╗─╔╗\n");
		printf("║╔══╝───║║─║║─║║\n");
		printf("║╚══╦╗╔╦╣║─║╚═╝╠══╦═╗╔══╦╗╔╦══╦═╗\n");
		printf("║╔══╣╚╝╠╣║─║╔═╗║╔╗║╔╗╣╔╗║╚╝║╔╗║╔╗╗\n");
		printf("║╚══╬╗╔╣║╚╗║║─║║╔╗║║║║╚╝║║║║╔╗║║║║\n");
		printf("╚═══╝╚╝╚╩═╝╚╝─╚╩╝╚╩╝╚╩═╗╠╩╩╩╝╚╩╝╚╝\n");
		printf("─────────────────────╔═╝║\n");
		printf("─────────────────────╚══╝\n");

		printf("\n\nWelcome to Evil Hangman!\n\n");

		GENERIC_VECTOR *dictionary = create_dictionary();
		TREE hTree = tree_init_default();
		MY_STRING guesses = my_string_init_c_string(" ");
		MY_STRING current_word_family = my_string_init_default();

		int word_length = prompt_get_word_length(dictionary);
		int guesses_left = prompt_number_guesses();
		Boolean running_total = prompt_running_total();

		for (i = 0; i < word_length; i++)
		{
			my_string_push_back(current_word_family, '-');
		}

		// Tell user amount of guesses they have and how long the word is
		printf("The game will now start!\n");
		printf("You have %d guesses!\n", guesses_left);
		printf("The word is %d letters long!\n", word_length);

		while (guesses_left > 0)
		{
			char guess = make_guess();

			// check if that letter has already been guessed
			for (int i = 0; i < my_string_get_size(guesses); i++)
			{
				if (guess == *my_string_at(guesses, i))
				{
					printf("That letter has already been guess pick another\n");
					guess = make_guess();
				}
			}
			guesses_left--;
			my_string_push_back(guesses, guess);

			for (i = 0; i < generic_vector_get_size(dictionary[word_length]); i++)
			{

				MY_STRING key = my_string_init_default();
				get_word_key_value(current_word_family, key, generic_vector_at(dictionary[word_length], i), guess);
				tree_push(hTree, key, generic_vector_at(dictionary[word_length], i));
				my_string_destroy(&key);
			}

			GENERIC_VECTOR largest_family = get_largest_family(hTree);
			int largest_family_size = generic_vector_get_size(largest_family);

			if (running_total == TRUE)
			{
				printf("The computer has %d possibilities remaining!\n\n", largest_family_size);
			}

			printf("You have %d guesses left\n", guesses_left);

			generic_vector_destroy(&dictionary[word_length]);
			dictionary[word_length] = generic_vector_init_default(my_string_init_copy, my_string_destroy);

			for (i = 0; i < largest_family_size; i++)
			{
				generic_vector_push_back(dictionary[word_length], generic_vector_at(largest_family, i));
			}

			MY_STRING new_key = my_string_init_default();
			get_word_key_value(current_word_family, new_key, generic_vector_at(dictionary[word_length], 0), guess);

			if (my_string_compare(new_key, current_word_family) == 0)
			{
				printf("You guessed incorectly!\n");
				printf("The letter %c was not in the word\n", guess);
				printf("Word: %s\n", my_string_c_str(new_key));
			}
			else
			{
				printf("You guessed correctly!\n");
				printf("Word: %s\n", my_string_c_str(new_key));
				my_string_assignment(current_word_family, new_key);
			}

			printf("Used letters:");
			for (int i = 0; i < my_string_get_size(guesses); i++)
			{
				printf(" %c", *my_string_at(guesses, i));
			}
			printf("\n");

			my_string_destroy(&new_key);

			tree_destroy(&hTree);
			
			hTree = tree_init_default();

			// Check if the word has been guessed
			if (my_string_compare(generic_vector_at(dictionary[word_length], 0), current_word_family) == 0)
			{
				printf("Congrats!!\nYou guessed the word!\n");
				printf("The word was %s\n", my_string_c_str(generic_vector_at(dictionary[word_length], 0)));
				break;
			}
		}

		if (guesses_left == 0 && !(my_string_compare(generic_vector_at(dictionary[word_length], 0), current_word_family) == 0))
		{
			printf("You lose the word was %s\n", my_string_c_str(generic_vector_at(dictionary[word_length], 0)));
		}

		my_string_destroy(&guesses);
		my_string_destroy(&current_word_family);
		tree_destroy(&hTree);

		for (int i = 0; i < 30; i++)
		{
			generic_vector_destroy(&dictionary[i]);
		}
		free(dictionary);

	} while (prompt_play_again() == TRUE);
}

char make_guess(void)
{
	char c;
	printf("\nMake a guess: \n");
	scanf("%c", &c);
	clear_keyboard_buffer();
	if (isalpha(c))
	{
		c = tolower(c);
	}
	else
	{
		printf("Invalid guess please try again!\n");
		make_guess();
	}

	return c;
}

int prompt_get_word_length(GENERIC_VECTOR *dictionary)
{
	int letter;
	printf("What length word do you want to play with?\n");
	scanf("%d", &letter);
	clear_keyboard_buffer();

	while (letter < 3 || letter > 29 || generic_vector_get_size(dictionary[letter]) == 0)
	{
		printf("The number you picked is invalid please pick another number\n");
		scanf("%d", &letter);
		clear_keyboard_buffer();
	}
	return letter;
}

int prompt_number_guesses(void)
{
	int guesses;
	printf("How many guesses would you like to have? (1-25)\n");
	scanf("%d", &guesses);
	clear_keyboard_buffer();

	while (guesses < 1 || guesses > 26)
	{
		printf("Invalid number of guesses try again!\n");
		scanf("%d", &guesses);
		clear_keyboard_buffer();
	}

	return guesses;
}

Boolean prompt_running_total(void)
{
	printf("Would you like to have a running total of words remaining in the word list? (y-n)\n");
	char c;
	scanf("%c", &c);
	clear_keyboard_buffer();

	while (c != 'y' && c != 'n')
	{
		printf("Invalid input please try again!\n");
		scanf("%c", &c);
		clear_keyboard_buffer();
	}

	if (c == 'y')
	{
		return TRUE;
	}

	return FALSE;
}

Boolean prompt_play_again(void)
{
	printf("\nWould you like to play again? (y-n)\n");
	char c;
	scanf("%c", &c);
	clear_keyboard_buffer();

	while (c != 'y' && c != 'n')
	{
		printf("Invalid input please try again!\n");
		scanf("%c", &c);
		clear_keyboard_buffer();
	}

	if (c == 'y')
	{
		return TRUE;
	}
	return FALSE;
}

GENERIC_VECTOR *create_dictionary(void)
{
	GENERIC_VECTOR *pVector = (GENERIC_VECTOR *)malloc(sizeof(GENERIC_VECTOR) * 30); 
	int i;
	MY_STRING hString = my_string_init_default(); 

	if (pVector == NULL)
	{
		return NULL;
	}

	for (i = 0; i < 30; i++)
	{
		pVector[i] = generic_vector_init_default(my_string_init_copy, my_string_destroy);

		if (pVector[i] == NULL)
		{
			return NULL;
		}
	}

	FILE *fp;
	fp = fopen("dictionary.txt", "r");
	if (fp == NULL)
	{
		return NULL;
	}

	while (my_string_extraction(hString, fp))
	{
		generic_vector_push_back(pVector[my_string_get_size(hString)], hString);
	}
	my_string_destroy(&hString);
	fclose(fp);
	return pVector;
}

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);

	while (c != '\n')
	{
		scanf("%c", &c);
	}
}