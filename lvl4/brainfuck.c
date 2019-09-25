// Assignment name  : brainfuck
// Expected files   : *.c, *.h
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------
//
// Write a Brainfuck interpreter program.
// The source code will be given as first parameter.
// The code will always be valid, with no more than 4096 operations.
// Brainfuck is a minimalist language. It consists of an array of bytes
// (in our case, let's say 2048 bytes) initialized to zero,
// and a pointer to its first byte.
//
// Every operator consists of a single character :
// - '>' increment the pointer ;
// - '<' decrement the pointer ;
// - '+' increment the pointed byte ;
// - '-' decrement the pointed byte ;
// - '.' print the pointed byte on standard output ;
// - '[' go to the matching ']' if the pointed byte is 0 (while start) ;
// - ']' go to the matching '[' if the pointed byte is not 0 (while end).
//
// Any other character is a comment.
//
// Examples:
//
// $>./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]
// >++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." | cat -e
// Hello World!$
// $>./brainfuck "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>." | cat -e
// Hi$
// $>./brainfuck | cat -e
// $

#include <unistd.h>

unsigned char MEM[2048] = {0};

void brainfuck(char *program)
{
    int mem_index = 0;
    int brace_counter = 0;

    for (int i = 0; program[i] != '\0'; ++i)
    {
        brace_counter = 0;
        if (program[i] == '>')
            mem_index++;
        else if (program[i] == '<')
            mem_index--;
        else if (program[i] == '+')
            MEM[mem_index]++;
        else if (program[i] == '-')
            MEM[mem_index]--;
        else if (program[i] == '.')
            write(1,&MEM[mem_index], 1);
        else if (program[i] == '[' && MEM[mem_index] == 0)
        {
            brace_counter++;
            ++i;
            while(brace_counter > 0)
            {
                if (program[i] == '[')
                {
                    brace_counter++;
                    ++i;
                }
                else if (program[i] == ']')
                {
                    brace_counter--;
                    ++i;
                }
                else
                {
                    ++i;
                    continue;
                }
            }
        }
        else if (program[i] == ']' && MEM[mem_index] != 0)
        {
            brace_counter++;
            --i;
            while(brace_counter > 0)
            {
                if (program[i] == ']')
                {
                    brace_counter++;
                    --i;
                }
                else if (program[i] == '[')
                {
                    brace_counter--;
                    --i;
                }
                else
                {
                    --i;
                    continue;
                }
            }
        }
        else
            continue;
    }
}

int main(int argc, char **argv)
{
    brainfuck(argv[1]);
}
