#pragma once
#include <stdio.h>

class Lex
{
public:
    Lex();
    ~Lex();
    void init_lex();
	void getword();
	void start_lex(char *filepath);

private:
	char wd;
	FILE *fd;
    
};

