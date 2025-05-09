#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    string title;
    string author;
    string ISBN;
    int isIssued;

    Book(string t = "", string a = "", string i = "")
    {
        title = t;
        author = a;
        ISBN = i;
        isIssued = 0;
    }
    void displayBookDetails()
    {
        cout << "Title: " << title << ", Author: " << author
             << ", ISBN: " << ISBN
             << ", Status: " << (isIssued ? "Issued" : "Available") << endl;
    }
    void issueBook()
    {
        if (isIssued == 0)
        {
            isIssued = 1;
            cout << "Book issued successfully!" << endl;
        }
        else
        {
            cout << "Book is already issued." << endl;
        }
    }
    void returnBook()
    {
        if (isIssued == 1)
        {
            isIssued = 0;
            cout << "Book returned successfully!" << endl;
        }
        else
        {
            cout << "Book was not issued." << endl;
        }
    }
};
class User
{
public:
    string name;
    int userID;
    string issuedBookISBN;

    User(string n = "", int id = 0)
    {
        name = n;
        userID = id;
        issuedBookISBN = "";
    }

    void issueBook(Book &b)
    {
        if (issuedBookISBN == "")
        {
            if (b.isIssued == 0)
            {
                b.issueBook();
                issuedBookISBN = b.ISBN;
            }
            else
            {
                cout << "Book is not available." << endl;
            }
        }
        else
        {
            cout << "You already have a book issued." << endl;
        }
    }

    void returnBook(Book &b)
    {
        if (issuedBookISBN == b.ISBN)
        {
            b.returnBook();
            issuedBookISBN = "";
        }
        else
        {
            cout << "This book was not issued to you." << endl;
        }
    }
};

int findUser(User users[], int size, int userID)
{
    for (int i = 0; i < size; i++)
    {
        if (users[i].userID == userID)
            return i;
    }
    return 0;
}

int findBook(Book books[], int size, string ISBN)
{
    for (int i = 0; i < size; i++)
    {
        if (books[i].ISBN == ISBN)
            return i;
    }
    return 0;
}

int main()
{
    Book books[100];
    User users[10] = {User("Alice", 101), User("Bob", 102)};
    int bookCount = 0;
    int choice;

    while (true)
    {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n2. Issue Book\n3. Return Book\n4. View Books\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1)
        {
            string t, a, i;
            cout << "Enter title: ";
            getline(cin, t);
            cout << "Enter author: ";
            getline(cin, a);
            cout << "Enter ISBN: ";
            getline(cin, i);

            books[bookCount] = Book(t, a, i);
            bookCount++;
            cout << "Book added.\n";
        }

        else if (choice == 2 || choice == 3)
        {
            int uid;
            string isbn;
            cout << "Enter User ID: ";
            cin >> uid;
            cin.ignore();
            cout << "Enter Book ISBN: ";
            getline(cin, isbn);

            int userIndex = findUser(users, 10, uid);
            int bookIndex = findBook(books, bookCount, isbn);

            if (userIndex == -1 || bookIndex == -1)
            {
                cout << "User or Book not found.\n";
            }
            else
            {
                if (choice == 2)
                    users[userIndex].issueBook(books[bookIndex]);
                else
                    users[userIndex].returnBook(books[bookIndex]);
            }
        }

        else if (choice == 4)
        {
            for (int i = 0; i < bookCount; i++)
            {
                books[i].displayBookDetails();
            }
        }

        else if (choice == 5)
        {
            cout << "Goodbye!" << endl;
            break;
        }

        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}