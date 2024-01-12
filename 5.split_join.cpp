/*
In this exercise we create two functions
mysplit : which splits sentence (string) given as first argument using second
argument as a separator character (char) to separate items. Function returns a
vector of items (vector<string>).
myjoin : which joins vector given as first argument (vector<string>) to a string
separated with character given as second argument. Function returns a string (string).
*/
#include <iostream>
#include <vector>
using namespace std;

vector<string> mysplit(string sentence, char sep);

string myjoin(vector<string> lst, char sep);

int split_and_join() {
    string sentence;
    cout << "Please enter sentence: ";
    getline(cin, sentence);
    cout << myjoin(mysplit(sentence, ' '), ',') << endl;
    cout << myjoin(mysplit(sentence, ' '), '\n') << endl;
    return 0;
}

vector<string> mysplit(string sentence, char sep) {
    vector<string> words_array;
    string temp;
    int i = 0;
    while (sentence[i] != '\0') {
        if (sentence[i] != sep) {
            temp += sentence[i];
        } else {
            words_array.push_back(temp);
            temp.clear();
        }
        i++;
    }
    words_array.push_back(temp);
    return words_array;
}

string myjoin(vector<string> lst, char sep) {
    string str;
    int i = 0;
    while ( i < lst.size()){
        str.append(lst[i]);
        if(i != lst.size() -1)
            str.push_back(sep);
        i++;
    }
    return str;
}

/*
Example output:
Please enter sentence: This is a sentence
This,is,a,sentence
This
is
a
sentence
*/