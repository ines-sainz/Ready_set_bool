#pragma once

#include <iostream>

class Tree
{
    private:
        char    value;
        Tree    *left;
        Tree    *right;

        void    painting(std::vector<std::string>& vec, Tree* tree, int x, int y);
        std::vector<std::string> fill_vector(Tree *tree, std::vector<std::string> vector);
        void    print_vector(std::vector<std::string> vector);
        void    print_small_tree(Tree *tree, int levels, int current);
        std::vector<std::string>    vector_tree(Tree *tree);
        void    print_tree(Tree *tree);
        Tree    *make_tree(std::string str);
        int     get_levels(Tree *tree);
public:
    Tree( char value );
    Tree( std::string str );
    ~Tree();
};
