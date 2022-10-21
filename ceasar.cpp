#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/// @brief
/// @param k positive integer for the number of letters for displacement.
/// @param plaintext  string text to be converted to cipher text.
/// @return encrypted ciphertext string as per the input rules.
string caesar(int k, string plaintext);

int main(int argc, char *argv[])
{

    // 1: declare an int to hold k as well as a string to hold the plaintext
    int k;
    string plaintext;

    // 2: ensure that the right number of command line arguments are entered
    // If the wrong number of arguments are entered exit by returning 3.
    // If the right number are entered assign k the appropriate value

    if (argc != 2)
    {
        cout << "One argument expected!";
    }
    else
    {

        k = atoi(argv[1]);

        // 3: read in the plaintext using getline
        getline(cin, plaintext);
        // 4: run the function caesar with appropriate arguments and assign the value returned to a string called ciphertext
        string ciphertext = caesar(k, plaintext);
        // Print out the ciphertext
        cout << ciphertext << "\n";
    }
    return 0;
}

string caesar(int k, string plaintext)
{

    // initialise empty ciphertext variable.
    string ciphertext = "";

    for (int i = 0, n = plaintext.length(); i < n; i++)
    {
        // set current character to currentCharacter variable
        char currentCharacter = plaintext[i];

        int alphaIndex;
        int newIndex;
        int newAsciiChar;

        if (isalpha(currentCharacter))
        {

            if (isupper(currentCharacter))
            {
                // uppercase letter
                // get the ASCII code of the uppercase letter, then get its index in alphabet
                alphaIndex = int(currentCharacter) % 65;
                newIndex = (alphaIndex + k) % 26;
                newAsciiChar = 65 + newIndex;
            }
            else
            {
                // lower case letter
                // get the ASCII code of the lowercase letter, then get its index in alphabet
                alphaIndex = int(currentCharacter) % 97;
                newIndex = (alphaIndex + k) % 26;
                newAsciiChar = 97 + newIndex;
            }

            char newCharacter = char(newAsciiChar);

            ciphertext += newCharacter;
        }
        else
        {

            ciphertext += currentCharacter;
        }
    }

    return ciphertext;
}
