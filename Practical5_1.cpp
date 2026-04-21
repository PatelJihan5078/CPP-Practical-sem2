#include <iostream>
#include <string>
using namespace std;

int main() {
    string paragraph;
    cout << "Enter paragraph:\n";
    getline(cin, paragraph);

    string words[100];
    int freq[100] = {0};
    int size = 0;

    string temp = "";

    for (int i = 0; i <= paragraph.length(); i++) {
        char ch = paragraph[i];

        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
        }

        if (ch != ' ' && ch != '\0') {
            temp += ch;
        } 
        else {
            if (temp != "") {
                bool found = false;

                for (int j = 0; j < size; j++) {
                    if (words[j] == temp) {
                        freq[j]++;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    words[size] = temp;
                    freq[size] = 1;
                    size++;
                }

                temp = "";
            }
        }
    }

    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < size; i++) {
        cout << words[i] << " : " << freq[i] << endl;
    }

    return 0;
}