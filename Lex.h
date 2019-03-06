#pragma once
#include <stdio.h>
#include "TkWord.h"
class Lex
{
public:
    Lex();
    ~Lex();
    void init_lex();
	void getword();
	void start_lex(char *filepath);
	void deal_token();
	void deal_unnormal_token();
	void deal_note();
	void deal_space();

private:
	char wd;
	FILE *fd;
	TkWord *tp;
    
};

