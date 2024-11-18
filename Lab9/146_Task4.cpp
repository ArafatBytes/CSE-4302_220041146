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

    double getPrice() const
    {
        return price;
    }

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

void sort_resources_price(LibraryResource **resources, int n)
{
    sort(resources, resources + n, [](LibraryResource *a, LibraryResource *b)
         { return a->getPrice() < b->getPrice(); });
}

int main()
{
    LibraryResource *resource_list[100];

    resource_list[0] = new Book("The Alchemist", "Paulo Coelho", 500, CoverType::Hardcover);
    resource_list[1] = new EBook("1984", "George Orwell", 300, 2.5);
    resource_list[2] = new Audiobook("Becoming", "Michelle Obama", 700, 120);

    for (int i = 0; i < 3; i++)
    {
        resource_list[i]->resourceDetails();
    }

    resource_list[0]->setCopies(50);
    resource_list[1]->setCopies(5);
    resource_list[2]->setCopies(1);

    for (int i = 0; i < 3; i++)
    {
        resource_list[i]->resourceDetails();
    }

    resource_list[3] = new Book("Sapiens", "Yuval Noah Harari", 1000, CoverType::Paperback);
    resource_list[4] = new EBook("Digital Minimalism", "Cal Newport", 400, 3.2);
    resource_list[5] = new Audiobook("Atomic Habits", "James Clear", 1200, 180);
    resource_list[6] = new Book("Dune", "Frank Herbert", 800, CoverType::Hardcover);
    resource_list[7] = new EBook("The Subtle Art of Not Giving a F*ck", "Mark Manson", 350, 1.8);
    resource_list[8] = new Audiobook("Educated", "Tara Westover", 600, 150);
    resource_list[9] = new Book("Harry Potter and the Philosopher's Stone", "J.K. Rowling", 450, CoverType::Paperback);

    sort_resources_price(resource_list, 10);

    for (int i = 0; i < 10; i++)
    {
        resource_list[i]->resourceDetails();
    }
}