#ifndef AUTHOR_HPP  // If AUTHOR_HPP has not been defined yet...
#define AUTHOR_HPP  // ...define it now.

#include <string> // We need to include this because our method uses the std::string type.
using std::string;

class Author {
    private:    // Not required. All is private by default.
    // Member variables to store the book's data
        string name;
        int birth_year ;

    public: 
        // Constructor declaration: how to create a Author object
        Author(const string& name, u_int birth_year);
        // Method declaration: what a Book object can do
        string get_name() const;

        // This declaration for the destructor
        ~Author();
};

#endif // End of the include guard block.