#pragma once
#include <stdio.h>
#include "TkWord.h"
#include <string>

using namespace std;
class Lex
{
public:
    Lex();
    ~Lex();
    void init_lex();
	void getword();
	void start_lex(const char* filepath);
	void deal_token();
	int deal_unnormal_token();
	void deal_note();
	void deal_space();
    void deal_parse();
    void deal_number();
    void show_token();
    string string_from_tkcolor(int tk_color, int &color);

    void show_tktable();
    char wd;
    int tkcolor;
    string tmp_wd;
    FILE *fd;
private:
	TkWord *tp;
    string lastword;
};

