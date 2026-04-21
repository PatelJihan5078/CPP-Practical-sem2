#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file;
    char filename[100];

    cout << "Enter file name: ";
    cin >> filename;

    file.open(filename);


    if (!file) {
        cout << "Error: File does not exist or cannot be opened." << endl;
        return 1;
    }

    char line[1000];
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

   
    while (file.getline(line, 1000)) {
        lineCount++;

        bool inWord = false;

        for (int i = 0; line[i] != '\0'; i++) {
            charCount++;

            if (line[i] != ' ' && line[i] != '\t') {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }
        }
    }

    file.close();

   
    cout << "Total Lines: " << lineCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Characters: " << charCount << endl;

    return 0;
}