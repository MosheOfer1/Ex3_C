#include <stdio.h>
#include <string.h>

#define LINE 256 // maximum length of the input line
#define WORD 30

// getline: read a line into s, return length
int getline1(char s[])
{
    int c, i;

    for (i = 0; i < LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (i==0)
    {
        return 1;
    }
    
    // if (c == '\n')
    //     s[i++] = c;
    s[i] = '\0';
    return i;
}
// getword: read a word into w, return length
int getword(char w[])
{
    int c, i;

    for (i = 0; i < WORD - 1 && (c = getchar()) != EOF && c != ' ' && c != '\t' && c != '\n'; ++i)
        w[i] = c;
    // Handle empty line
    if (c == '\n' && i==0)
        w[i++] = c;
    w[i] = '\0';
    return i;
}

// substring: return 1 if str1 is a substring of str2, 0 otherwise
int substring(char *str1, char *str2)
{
    int len1 = strlen(str1); // length of str1
    int len2 = strlen(str2); // length of str2

    for (int i = 0; i < len2 - len1 + 1; i++)
    {
        // compare the characters in str1 to the corresponding characters in str2
        if (strncmp(str1, str2 + i, len1) == 0)
            return 1; // str1 is a substring of str2
    }
    return 0; // str1 is not a substring of str2
}
// similar: return 1 if it is possible to get t from s by removing at most n characters, 0 otherwise
int similar(char *s, char *t, int n)
{
    int len_s = strlen(s); // length of s
    int len_t = strlen(t); // length of t

    if (len_s < len_t || len_t + n < len_s)
        return 0; // s cannot be transformed into t by removing at most n characters

    int i = 0, j = 0;
    while (i < len_s && j < len_t)
    {
        if (s[i] == t[j])
            j++; // advance j if the characters match
        i++; // always advance i
    }
    return j == len_t; // return 1 if all characters in t were found in s, 0 otherwise
}
// print_lines: print all the lines that contain the string str
void print_lines(char *str)
{
    char line[LINE]; // character array to hold the input line

    while (getline1(line) > 0)
    {
        if (substring(str, line)){
            printf("%s\n", line); // print the line if it contains str
        }
    }
}

void print_similar_words(char *str) {
    char word[WORD]; // to store the words read from the input
    while (getword(word) > 0) { // read a word from the input
        if (similar(word, str, 1)) { // check if temp is similar to str
            printf("%s\n", word); // print word if it is similar to temp
        }   
    }
}

int main() {
    char word[WORD];
    //c for the users choise and l for the blank line '\n'
    char c,l;
    //Gets the user choise
    scanf("%s %c%c",word,&c,&l);
    

    if (c == 'a')
    {
        print_lines(word);
    }

    else if (c == 'b')
    {
        print_similar_words(word);
    }   
    
    return 0;
}



