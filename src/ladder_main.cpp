#include "ladder.h"
#include <iostream>

using namespace std;

int main() {
    set<string> word_list;
    load_words(word_list, "words.txt");

    string start_word = "cat";
    string end_word = "dog";

    vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);

    cout << "Testing word ladder from \"" << start_word << "\" to \"" << end_word << "\":" << endl;
    print_word_ladder(ladder);

    return 0;
}
