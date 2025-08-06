#include <iostream>
#include <stack>
#include <vector>
#include "draw.hpp"

int Tree::get_levels(Tree *tree)
{
    if (!tree)
        return (0);
    int i = get_levels(tree->left);
    int j = get_levels(tree->right);
    if (i > j)
        return (i + 1);
    return (j + 1);
}

Tree    *Tree::make_tree(std::string str)
{
    std::stack<Tree*> tree;
    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == '1' || str[i] == '0')
            tree.push(new Tree(str[i]));
        else if (str[i] == '!')
        {
            if (tree.size() < 1)
                throw("Error: parse error");
            Tree *val = tree.top();
            tree.pop();
            Tree *node = new Tree(str[i]);
            node->left = val;
            tree.push(node);
        }
        else if (str[i] == '&' || str[i] == '|' || str[i] == '^' || str[i] == '>' || str[i] == '=')
        {
            if (tree.size() < 2)
                throw ("Error: parse error");
            Tree *right = tree.top();
            tree.pop();
            Tree *left = tree.top();
            tree.pop();
            Tree    *node = new Tree(str[i]);
            node->left = left;
            node->right = right;
            tree.push(node);
        }
        else
            throw("Error: parse error");
    }
    if (tree.size() != 1)
        throw("Error: parse error");
    return (tree.top());
}

std::vector<std::string>    Tree::vector_tree(Tree *tree)
{
    std::vector<std::string>    paint;
    int levels = get_levels(tree);
    int height = ((levels - 1) * 2) + 1;
    int width = ((((levels - 1) * 2) + 1) * 2) + 1;
    for (size_t i = 0; i < height; i++)
    {
        std::string lines = "";
        for (size_t j = 0; j < width; j++)
        {
            lines += " ";
        }
        paint.push_back(lines);
    }
    return (paint);
}

void    Tree::print_vector(std::vector<std::string> vector)
{
    for (std::vector<std::string>::iterator it = vector.begin(); it != vector.end(); it++)
    {
        std::cout << *it << std::endl;
    }   
}

void    Tree::painting(std::vector<std::string>& vec, Tree* tree, int x, int y)
{
    if (!tree)
        return ;
    vec[y][x] = tree->value;
    if (tree->left)
    {
        vec[y + 1][x - 1] = '/';
        painting(vec, tree->left, x - 2, y + 2);
    }
    if (tree->right)
    {
        vec[y + 1][x + 1] = '\\';
        painting(vec, tree->right, x + 2, y + 2);
    }
}

std::vector<std::string> Tree::fill_vector(Tree *tree, std::vector<std::string> vector)
{
    int x = ((get_levels(tree) - 1) * 2) + 1;
    int y = 0;
    painting(vector, tree, x, y);
    return (vector);
}

Tree::Tree( std::string str )
{
    Tree    *tree = make_tree(str);
    std::vector<std::string> vector = vector_tree(tree);
    vector = fill_vector(tree, vector);
    print_vector(vector);
}

int main(void)
{
    std::string str = "10&";
    try
    {
        Tree tree(str);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    str = "10|1|1=";
    try
    {
        Tree tree(str);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
Tree::Tree( char value )
{
    this->value = value;
    this->left = NULL;
    this->right = NULL;
}

Tree::~Tree()
{
}
