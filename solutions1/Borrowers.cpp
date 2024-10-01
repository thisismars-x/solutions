#include<bits/stdc++.h>
using namespace std;

struct book
{
    string title, author;
    
    bool operator<(const book& other){
        
        if (author != other.author) return author < other.author;
        return title < other.title;
    }
};

void read_books(vector<book> & allBooks)
{
    string temp;
    
    book currentbook;
    
    while (cin >> temp, temp != "END")
    {
        currentbook.title = "";
        
        bool first = true;
        
        while (*(temp.end() - 1) != '"')
        {
            if (!first)
                currentbook.title += ' ';

            first = false;
            currentbook.title += temp;
            
            cin >> temp;
        }
        
        if (!first)
            currentbook.title += ' ';
            
        currentbook.title += temp;
        
        // Ignore 'by'
        cin >> temp;
        // ignore the space after the by
        cin.ignore();
        
        getline(cin, currentbook.author);
        allBooks.push_back(currentbook);
    }
}

enum bookStatusEnum { available, borrowed, returned };

int main()
{
    vector<book> allBooks;
    read_books(allBooks);
    
    
    int numBooks = allBooks.size();
    sort(allBooks.begin(), allBooks.end());
    
    vector<bookStatusEnum> booksStatus(numBooks, available);
    
    map<string, int> positionInAllBooks;
    for (int i = 0; i < numBooks; ++i)
        positionInAllBooks[allBooks[i].title] = i;
    
    vector<bool> borrowed(numBooks, false);
    vector<bool> returned(numBooks, false);
    
    string command;
    string bookName;
    while (cin >> command, command != "END")
    {
        if (command == "BORROW")
        {
            cin.ignore();
            getline(cin, bookName);
            int pos = positionInAllBooks[bookName];
            borrowed[pos] = true;
            returned[pos] = false;
        }
        
        else if (command == "RETURN")
        {
            cin.ignore();
            getline(cin, bookName);
            returned[positionInAllBooks[bookName]] = true;
        }
        
        else // SHELVE
        {
            int previous = -1;
            for (int i = 0; i < numBooks; ++i)
            {
                if (!borrowed[i])
                    previous = i;
                else if (returned[i])
                {
                    if (previous == -1)
                        cout << "Put " << allBooks[i].title << " first\n";
                    else
                        cout << "Put " << allBooks[i].title << " after " << allBooks[previous].title << '\n';
                    
                    returned[i] = false;
                    borrowed[i] = false;
                    previous = i;
                }
            }
            
            cout << "END\n";
        }
    }
}