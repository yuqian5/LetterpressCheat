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

// function to print out matched result formatted
void print(const vector<string> &result){
    int count = 0;
    for (const auto &i : result) {
        cout << i;
        for (int x = 0; x < 16 - i.length(); x++) {
            cout << " ";
        }
        count += 1;

        if (count % 6 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

// custom rule to sort vector by length
struct compare {
    bool operator()(const std::string& first, const std::string& second) {
        return first.size() > second.size();
    }
} rule;

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
    cout << match_count << " Word Matched" << endl;
}

void SE::display_result() {
    // sort everything by length
    sort(S1_5.begin(), S1_5.end(), rule);
    sort(S6_9.begin(), S6_9.end(), rule);
    sort(S10_15.begin(), S10_15.end(), rule);
    sort(S16_a.begin(), S16_a.end(), rule);

    bool stop = false;

    while(!stop){
        int option;

        // display option, prompt for input
        cout << "[1] Word Length 1-5    [2] Word Length 6-9    [3] Word Length 10-15    [4] Word Length 16-A    [5] exit" << endl;
        cin >> option; // get input


        if(option == 1){
            system("clear");
            print(S1_5);
        }else if(option == 2){
            system("clear");
            print(S6_9);
        }else if(option == 3){
            system("clear");
            print(S10_15);
        }else if(option == 4){
            system("clear");
            print(S16_a);
        }else if(option == 5){
            system("clear");
            stop = true;
        }else{
            system("clear");
            cout << "<< OPTION UNKNOWN >>" << endl;
        }
    }
}
