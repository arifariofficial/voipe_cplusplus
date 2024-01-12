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