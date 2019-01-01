#include "SearchEngine.h"

// function to see if a char is in a string
bool is_in(string str, char c){
    for(auto x : str){
        if(x == c){
            return true;
        }
    }
    return false;
}

SE::SE() {
    dict = new vector <string>; // create dict on heap

    load_dict(); // load library to dict
}

SE::~SE() {
    safe_delete(dict); // delete dict on heap
}

void SE::load_dict() {
    ifstream lib; // open file
    lib.open("lib");

    string word;
    long int word_loaded = 0;
    while(!lib.eof()){ // file eof not reached, load word to dict
        lib >> word;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        dict->push_back(word);
        word_loaded += 1;
    }

    cout << "DICTIONARY LOADED" << endl;
    lib.close(); // close file
}

void SE::get_input() { // only 25 alphabet will be taken, anything else will be discarded
    cout << "Please Input 25 Alphabets: " << endl;
    char c;
    while(letters.length() != 25){
        c = (char) getchar(); // get char
        if(isalpha(c)) { // check if the character is an alphabet
            letters += c; // load character to letters
        }else{
            // ignore and do nothing
        }
    }

    cout << letters << endl;
}

void SE::search_dict() {
    /*
     * for every word in dict
     *      if the word can be spelled with letters in letters
     *          this word is a match
     *              according to length, add to the right vector
     *      if not
     *          this word is not a match, discard and move on
     */
    cout << "Searching Dictionary" << endl;
    int match_count = 0;

    for(const auto &word : *dict){
        bool match = true;

        string temp = letters;

        for(auto character : word){
            bool in_letters = false;

            for(auto i : temp){
               if(i==character){
                   in_letters = true;
                   break;
               }
            }

            if(!in_letters){
                match = false;
                break;
            }else{
                for (char &i : temp) {
                    if(i == character){
                        i = '|';
                        break;
                    }
                }
            }
        }

        if(match){ // if match, add to the right vector according to length
            match_count += 1; // increment word count
            int str_len = word.length();
            if(str_len < 6 ){
                S1_5.push_back(word);
            }else if(str_len < 10){
                S6_9.push_back(word);
            }else if(str_len < 16){
                S10_15.push_back(word);
            }else{
                S16_a.push_back(word);
            }
        }else{
            // not a match, do nothing
        }
    }
}

void SE::display_result() {
    bool stop = false;

    while(!stop){
        int option;
        cout << "[1] 1-5    [2] 6-9    [3] 10-15    [4] 16-A    [5] exit" << endl; // display option, prompt for input
        cin >> option; // get input

        switch (option){ // display according to selection
            case 1:
                system("clear");for (const auto &x : S1_5){cout << x << endl;}break;
            case 2:
                system("clear");for (const auto &x : S6_9){cout << x << endl;}break;
            case 3:
                system("clear");for (const auto &x : S10_15){cout << x << endl;}break;
            case 4:
                system("clear");for (const auto &x : S16_a){cout << x << endl;}break;
            case 5:
                system("clear");stop = true;break;
            default:
                system("clear");cout << "UNKNOWN OPTION" << endl;break;
        }
    }
}
