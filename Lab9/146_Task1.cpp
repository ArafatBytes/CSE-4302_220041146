#include <bits/stdc++.h>
using namespace std;

class LibraryResource
{
protected:
    string title, author;
    double price;

public:
    LibraryResource(string t, string a, double p) : title(t), author(a), price(p) {};
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
    Book(string t, string a, double p, CoverType ct) : LibraryResource(t, a, p), covertype(ct) {};
};

class EBook : public LibraryResource
{
private:
    double fileSize;

public:
    EBook(string t, string a, double p, double fS) : LibraryResource(t, a, p), fileSize(fS) {};
};

class Audiobook : public LibraryResource
{
private:
    int duration;

public:
    Audiobook(string title, string author, double price, int duration) : LibraryResource(title, author, price), duration(duration) {};
};