/*
 * Name: Joe Francesconi
 * Date Submitted: 3/20/2022
 * Assignment Name: Anagram
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>


using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//takes word and returns a vector of anagrams of said string
vector<string> anagram(string word, vector<string> wordlist)
{
   string s;
   vector<string> anagrams;
   
   //checking every word
   for (int i = 0; i < wordlist.size(); i++)
   {
       s = wordlist[i];
       
       int length = word.length();
       int length2 = s.length();
       
       unordered_map<char, int> charMap;
       
       if (length == length2)
       {
           for (int j = 0; j < length; j++)
           {
               charMap[word[j]]++;
           }
           
           for (int j = 0; j < length2; j++)
           {
               //if any char is different
               if (charMap.find(s[j]) == charMap.end())
               {
                   break;
               }
               else
               {
                   charMap[s[j]]--;
                   if (charMap[s[j]] == 0)
                   {
                       charMap.erase(s[j]);
                   }
               }
           }
           //a word is an anagram if the map ends up empty
           if (charMap.size() == 0)
           {
               anagrams.push_back(s);
           }
       }
   }

   return anagrams;
}






