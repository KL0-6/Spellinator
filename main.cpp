#include <stdio.h>
#include <string>
#include <iostream>
#include <unordered_map>

#define SUPPORT_REMOVED_WORDS true // ch && ll were eliminated, however you can choose to support those characters!
#define VERIFY_CHAR true // If enabled, it will make sure the char exists within our map!

// Letter : Spanish Name
// ñ will be handled within the convert function because it is multi char!
std::unordered_map<char, std::string> words = 
{
    {'a', "a"},
    {'b', "be"},
    {'c', "ce"},
    {'d', "de"},
    {'e', "e"},
    {'f', "efe"},
    {'g', "ge"},
    {'h', "hache"},
    {'i', "i"},
    {'j', "jota"},
    {'k', "ka"},
    {'l', "ele"},
    {'m', "eme"},
    {'n', "ene"},
    {'o', "o"},
    {'p', "pe"},
    {'q', "cu"},
    {'r', "ere"},
    {'s', "ese"},
    {'t', "te"},
    {'u', "u"},
    {'v', "ve"},
    {'w', "doble ve"},
    {'x', "equis"},
    {'y', "i griega"},
    {'z', "zeta"},
};

std::string convert(std::string word)
{
    size_t sz = word.size();

    if(sz == 0)
        return "";

    std::string return_string = "";

    for(size_t i = 0; i < sz; i++)
    {
        char c = word[i];
        
        if(i != 0)
            return_string += "-"; // Add a dash to seperate names

        if(word[i] == (-61) && word[i + 1] == (-79)) // ñ
        {
            return_string += "eñe";
            ++i; // Skip over next char
        }
    #if SUPPORT_REMOVED_WORDS
        else if(c == 'c' && word[i + 1] == 'h') // ch
        {
            return_string += "che";
            ++i; // Skip over next char
        }
        else if(c == 'l' && word[i + 1] == 'l') // ll
        {
            return_string += "elle";
            ++i; // Skip over next char
        }
    #endif
        else
        {
            #if VERIFY_CHAR 
                if(words.find(c) != words.end())
                    return_string += words[c];
                else
                    printf("Unknown char (%c)!\n", c);
            #else
                return_string += words[c];
            #endif      
        }
    }

    return return_string;
}

int main(int argc, char* argv[])
{
    printf("Welcome to spellinator!\n");

    while(true)
    {
        printf("Enter your word:\n");

        std::string word = "";
        if(getline(std::cin, word))
            printf("%s\n", convert(word).c_str());
    }

    return 0;
}
