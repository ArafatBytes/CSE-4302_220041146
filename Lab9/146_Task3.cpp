#include <bits/stdc++.h>
using namespace std;

class LibraryResource
{
protected:
    string title, author;
    double price;
    int copies;

public:
    LibraryResource(string t, string a, double p, int c) : title(t), author(a), price(p), copies(c) {};

    virtual void resourceDetails() const = 0;

    void setCopies(int n)
    {
        copies = n;
    };

    int getCopies() const
    {
        return copies;
    }
};

enum class CoverType
{
    Hardcover,
    Paperback
};

class Book : public LibraryResource
{
private:
    CoverType covertype;

public:
    Book(string t, string a, double p, CoverType ct, int c = 1) : LibraryResource(t, a, p, c), covertype(ct) {};

    void resourceDetails() const override
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        if (covertype == CoverType::Hardcover)
        {
            cout << "Cover Type: " << "Hardcover" << endl;
        }
        else
        {
            cout << "Cover Type: " << "Paperback" << endl;
        }
        cout << "No of copies: " << copies << endl;
    };
};

class EBook : public LibraryResource
{
private:
    double fileSize;

public:
    EBook(string t, string a, double p, double fS, int c = 1) : LibraryResource(t, a, p, c), fileSize(fS) {};

    void resourceDetails() const override
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "File Size: " << fileSize << " MB" << endl;
        cout << "No of copies: " << copies << endl;
    };
};

class Audiobook : public LibraryResource
{
private:
    int duration;

public:
    Audiobook(string title, string author, double price, int duration, int c = 1) : LibraryResource(title, author, price, c), duration(duration) {};

    void resourceDetails() const override
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "Duration " << duration << " minutes" << endl;
        cout << "No of copies: " << copies << endl;
    };
};