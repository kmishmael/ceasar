#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;
 
// function prototype
string caesar(int k, string plaintext);
 
int main(int argc, char* argv[])
{
    cout << argc << endl;
    for(int j = 0; j < argc; j++){
        cout << argv[j] << endl;
    }
   // TODO 1: declare an int to hold k as well as a string to hold the plaintext
   int k;
   string plaintext;
 
   // TODO 2: ensure that the right number of command line arguments are entered
   // If the wrong number of arguments are entered exit by returning 3.
   // If the right number are entered assign k the appropriate value

   if(argc != 2){
    cout << "One argument expected!" << endl;
    return 3;
   }

   k = atoi(argv[0]);
 
   // TODO 3: read in the plaintext using getline
   getline(cin, plaintext);
   // TODO 4: run the function caesar with appropriate arguments and assign the value returned to a string called ciphertext
   string ciphertext = caesar(k, plaintext);
   // Print out the ciphertext
   cout << plaintext << " ";
   cout << ciphertext;
}
 
// TODO 5: implement the caesar function
// Remember to take care of a case in which k is greater than 26
string caesar(int k, string plaintext){
    
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string ciphertext = "";

    for(int i = 0, n = plaintext.length(); i < n; i++)
    {
        char currentCharacter = plaintext[i];

        if(isspace(plaintext[i])){
            ciphertext.push_back(' ');
            continue;
        }
        
        int currentIndex = letters.find(tolower(currentCharacter));

        int newIndex = (currentIndex + k) % 26;

        char newCharacter = plaintext[newIndex];

        ciphertext.push_back(((isupper(currentCharacter)) ? toupper(newCharacter) : newCharacter));
    }

    return ciphertext;
}
