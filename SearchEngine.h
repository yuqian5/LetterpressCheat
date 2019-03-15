#pragma once
#define Uint unsigned int

#include <iostream>
#include <vector>
#include <ctype.h>
#include <fstream>
#include <algorithm>
using namespace std;

// function to delete point to heap
template <typename PT>
void safe_delete(PT *p){
    delete p;
    p = nullptr;
}

class SE{
    public:
        SE();

        ~SE();

        void get_input();

        void load_dict();

        void search_dict();

        void display_result();

    private:
        vector <string> S1_5;
        vector <string> S6_9;
        vector <string> S10_15;
        vector <string> S16_a;

        string letters;

        vector <string> *dict;
};