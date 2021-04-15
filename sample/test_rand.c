/*
    This program tries to match a given regular expression with text given as input to stdin.
    If the text is a match for the pattern, the program returns 0.
    If the text doesn't match the pattern, the program returns -2.

    This program is used in random testing to test a lot of random text and regex together.
    See ./scripts/regex_test.py and the Makefile for this project for the gritty details.
*/

#include <rtthread.h>
#include <re.h>

int regex_rand(int argc, char** argv)
{
    int length;
    if (argc == 3)
    {
        int m = re_match(argv[1], argv[2], &length);
        if (m != -1)
        {
            rt_kprintf("regex test success.\n");
            return 0;
        }
        else
        {
            re_print(re_compile(argv[1]));
            rt_kprintf("pattern '%s' matched '%s' unexpectedly, matched %i chars. \n", argv[1], argv[2], length);
        }
    }
    else
    {
        rt_kprintf("\nUsage: %s <PATTERN> <TEXT> \n", argv[0]);
    }
    return -2;
}

MSH_CMD_EXPORT(regex_rand, tries to match a given regular expression with text given as input to stdin);
