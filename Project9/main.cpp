//HM_ex_1_3.04.2023
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string text = "Rebrov didn't like that I called him a messiah for the national team, I think I'll survive it.";
    string word;
    int count = 0;
    cout << "Enter word: ";
    cin >> word;
    size_t pos = text.find(word);
    while (pos != string::npos)
    {
        count++;
        pos = text.find(word, pos + 1);
    }
    cout << "The number of occurrences of the word '" << word << "' in the text: " << count << endl;
    int sentence_count = 0;
    for (size_t i = 0; i < text.length(); i++)
    {
        if (text[i] == '.' || text[i] == '?')
        {
            sentence_count++;
        }
    }
    cout << "Number of sentences in the text: " << sentence_count << endl;
    int dot_count = 0;
    int comma_count = 0;
    for (size_t i = 0; i < text.length(); i++)
    {
        if (text[i] == '.')
        {
            dot_count++;
        }
        else if (text[i] == ',')
        {
            comma_count++;
        }
    }
    cout << "The number of points in the text: " << dot_count << endl;
    cout << "The number of commas in the text: " << comma_count << endl;
    string reversed_text;
    for (int i = text.length() - 1; i >= 0; i--)
    {
        reversed_text += text[i];
    }
    cout << "Inverted text: " << reversed_text << endl;
    string reversed_sentences;
    string sentence;
    for (size_t i = 0; i < text.length(); i++)
    {
        sentence += text[i];
        if (text[i] == '.' || text[i] == '?')
        {
            for (int j = sentence.length() - 2; j >= 0; j--)
            {
                reversed_sentences += sentence[j];
            }
            reversed_sentences += sentence[sentence.length() - 1];
            sentence = "";
        }
    }
    cout << "Inverted sentences in the text: " << reversed_sentences << endl;
    return 0;
}