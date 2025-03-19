#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    string title, author, ISBN;

public:
    Book(string t, string a, string i) : title(t), author(a), ISBN(i) {}
    string getTitle() const
    {
        return title;
    }
    string getAuthor() const
    {
        return author;
    }
    string getISBN() const
    {
        return ISBN;
    }
    void display() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
    }
};

class Library
{
private:
    vector<Book> inventory;
    deque<Book> borrowedBooks;
    list<Book> archivedBooks;

public:
    void addBook()
    {
        string t, a, i;
        cout << "Enter title,author and ISBN: " << endl;
        cin >> t >> a >> i;
        Book book(t, a, i);
        inventory.push_back(book);
        cout << "Book added" << endl;
    }
    void borrowBook(const string &ISBN)
    {
        for (auto it = inventory.begin(); it != inventory.end(); ++it)
        {
            if (it->getISBN() == ISBN)
            {
                borrowedBooks.push_back(*it);
                inventory.erase(it);
                cout << "Book borrowed successfully." << endl;
                return;
            }
        }
        cout << "Book not found in inventory." << endl;
    }
    void returnBook(const string &ISBN)
    {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it)
        {
            if (it->getISBN() == ISBN)
            {
                inventory.push_back(*it);
                borrowedBooks.erase(it);
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Book not found in borrowed books." << endl;
    }
    void archiveBook(const string &ISBN)
    {
        for (auto it = inventory.begin(); it != inventory.end(); ++it)
        {
            if (it->getISBN() == ISBN)
            {
                archivedBooks.push_back(*it);
                inventory.erase(it);
                cout << "Book archived successfully." << endl;
                return;
            }
        }
        cout << "Book not found in inventory." << endl;
    }
    void displayAllBooks() const
    {
        cout << "INVENTORY" << endl;
        for (const auto &book : inventory)
        {
            book.display();
        }
        cout << "BORROWED BOOKS" << endl;
        for (const auto &book : borrowedBooks)
        {
            book.display();
        }
        cout << "ARCHIVED BOOKS" << endl;
        for (const auto &book : archivedBooks)
        {
            book.display();
        }
    }

    void saveData() const
    {
        ofstream invFile("inventory.txt"), borFile("borrowed.txt"), arcFile("archived.txt");
        for (const auto &book : inventory)
        {
            invFile << book.getTitle() << "," << book.getAuthor() << "," << book.getISBN() << endl;
        }
        for (const auto &book : borrowedBooks)
        {
            borFile << book.getTitle() << "," << book.getAuthor() << "," << book.getISBN() << endl;
        }
        for (const auto &book : archivedBooks)
        {
            arcFile << book.getTitle() << "," << book.getAuthor() << "," << book.getISBN() << endl;
        }
        cout << "Book saved successfully." << endl;
    }

    void loadData()
    {
        ifstream invFile("inventory.txt"), borFile("borrowed.txt"), arcFile("archived.txt");
        string line;

        inventory.clear();
        borrowedBooks.clear();
        archivedBooks.clear();

        if (invFile.is_open())
        {
            while (getline(invFile, line))
            {
                stringstream ss(line);
                string title, author, ISBN;
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, ISBN, ',');
                inventory.push_back(Book(title, author, ISBN));
            }
            invFile.close();
        }
        else
        {
            cout << "Unable to open inventory.txt for reading." << endl;
        }

        if (borFile.is_open())
        {
            while (getline(borFile, line))
            {
                stringstream ss(line);
                string title, author, ISBN;
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, ISBN, ',');
                borrowedBooks.push_back(Book(title, author, ISBN));
            }
            borFile.close();
        }
        else
        {
            cout << "Unable to open borrowed.txt for reading." << endl;
        }

        if (arcFile.is_open())
        {
            while (getline(arcFile, line))
            {
                stringstream ss(line);
                string title, author, ISBN;
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, ISBN, ',');
                archivedBooks.push_back(Book(title, author, ISBN));
            }
            arcFile.close();
        }
        else
        {
            cout << "Unable to open archived.txt for reading." << endl;
        }

        cout << "Data loaded successfully." << endl;
    }
};

int main()
{
    Library library;
    int choice;
    string ISBN;

    do
    {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Borrow Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Archive Book" << endl;
        cout << "5. Display All Books" << endl;
        cout << "6. Save Data" << endl;
        cout << "7. Load Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            library.addBook();
            break;

        case 2:
            cout << "Enter ISBN of the book to borrow: ";
            cin >> ISBN;
            library.borrowBook(ISBN);
            break;

        case 3:
            cout << "Enter ISBN of the book to return: ";
            cin >> ISBN;
            library.returnBook(ISBN);
            break;

        case 4:
            cout << "Enter ISBN of the book to archive: ";
            cin >> ISBN;
            library.archiveBook(ISBN);
            break;

        case 5:
            library.displayAllBooks();
            break;

        case 6:
            library.saveData();
            break;

        case 7:
            library.loadData();
            break;

        case 8:
            cout << "Exiting the program" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}