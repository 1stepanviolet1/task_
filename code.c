#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <stdbool.h>

#define BLOCK_SIZE 10


void
error(const char *_msg)
{
    fprintf(stderr, _msg);
    exit(0);

}

void
error_if(bool _cond, const char *_msg)
{
    if (_cond)
        error(_msg);

}

void *
allocator(void *_old, size_t _n, size_t _size)
{
    void *_ptr = realloc(_old, _n * _size);
    error_if(_ptr == NULL, "ERROR: badalloc");

}


char * 
input()
{
    int capacity = BLOCK_SIZE;
    char *text = (char*)allocator(NULL, capacity, sizeof(char));

    int k = 0;

    char ch = getchar();
    char ch_one = 'a';
    char ch_two = 'a';
    char ch_three = 'a';
    char ch_four = 'a';

    while(   ch_one != 'F' 
          || ch_two != 'i' 
          || ch_three != 'n' 
          || ch_four != '.')
    {
        text[k++] = ch;

        if (k == capacity-1)
        {
            capacity += BLOCK_SIZE;
            text = (char*)allocator(text, capacity, sizeof(char));

        }
        
        ch_one = ch_two;
        ch_two = ch_three;
        ch_three = ch_four;
        ch_four = ch;
        ch = getchar();

    }

    text[k] = '\0';
    return text;

}

char ** 
split_text(char *text, int *k)
{
    int capacity = BLOCK_SIZE;
    char **text_done = (char**)allocator(NULL, capacity, sizeof(char*));

    char *sentence = strtok(text, "\n");

    while(sentence != NULL)
    {
        int sent_len = strlen(sentence);
        text_done[*k] = (char**)allocator(NULL, sent_len+1, sizeof(char));

        strcpy(text_done[(*k)++], sentence);
        
        if(*k == capacity-1)
        {
            capacity += BLOCK_SIZE;
            text_done = (char**)allocator(text_done, capacity, sizeof(char*));

        }
        
        sentence = strtok(NULL, "\n");
    }
    
    return text_done;

}

int main(int argc, char **argv)
{
    char *text = input();
    int k = 0;

    char **text_done = split_text(text, &k);
    char *regexString = "(([A-z]*):\\/\\/)?(www.)?([A-z0-9]+([_\\-\\.]+[A-z]+)+)\\/((([A-z]*)\\/)*)([A-z0-9_\\-]+\\.[A-z0-9_\\-]+)";

    regex_t regexCompiled;
    regmatch_t groupArray[BLOCK_SIZE];

    error_if(regcomp(&regexCompiled, regexString, REG_EXTENDED),
             "ERROR: Could not compile regular expression\n");

    for(int index = 0; index < k; index++)
    {
        if(regexec(&regexCompiled, text_done[index], BLOCK_SIZE, groupArray, 0) == 0)
        {
            int i = 4;
            for(int j = groupArray[i].rm_so; j < groupArray[i].rm_eo; j++)
                printf("%c",text_done[index][j]);
            
            printf(" - ");

            i = 9;
            for(int j = groupArray[i].rm_so; j < groupArray[i].rm_eo; j++)
                printf("%c",text_done[index][j]);
            
            printf("\n");
        }
    }

    free(text);
    
    for(int i = 0; i < k; i++)
        free(text_done[i]);
    
    free(text_done);

    regfree(&regexCompiled);

    return 0;

}

