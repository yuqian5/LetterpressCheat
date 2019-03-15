#include "SearchEngine.h"

void search(){
    system("clear"); // clear bash
    cout << "<< Search Engine Initiated >>" << endl;

    auto *engine = new SE; // create SearchEngine on heap

    engine->get_input(); // get 25 letter from stdin

    engine->search_dict(); // search the dictionary

    engine->display_result(); // display result

    safe_delete(engine); // delete pointer
}

int main(){
    bool terminate = false;

    while(!terminate){
        int option;
        cout << "[1] initialize   [2] terminate" << endl; // display option
        cin >> option; // get option

        if(option == 1){ // if 1 is chosen, initiate search
            search();
        }else if(option == 2){ // terminate
            terminate = true;
        }else{
            cout << "UNKNOWN CHOICE" << endl;
        }
    }

    system("clear"); // clear bash
    cout << "<< TERMINATED >>" << endl; // display to user
    return 0;
}