#include <iostream>
#include <stack>
#include <vector>
#include "draw.hpp"

// uint32_t : standard 32-bit unsigned integer in <cstdint> c++ and <stdint.h> in c
// MAX 4294967295

//Time complexity: O(n) →  Not Applicable or Not Assessed
//Space complexity: N/A → Not Applicable or Not Assessed

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
                throw(std::runtime_error("Error: RPN expression not correctly written"));
            Tree *val = tree.top();
            tree.pop();
            Tree *node = new Tree(str[i]);
            node->left = val;
            tree.push(node);
        }
        else if (str[i] == '&' || str[i] == '|' || str[i] == '^' || str[i] == '>' || str[i] == '=')
        {
            if (tree.size() < 2)
                throw(std::runtime_error("Error: RPN expression not correctly written"));
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
            throw(std::runtime_error("Error: character not valid"));
    }
    if (tree.size() != 1)
        throw(std::runtime_error("Error: RPN expression not correctly written"));
    return (tree.top());
}

std::vector<std::string>    Tree::vector_tree(Tree *tree)
{
    std::vector<std::string>    paint;
    int levels = get_levels(tree);
    int height = ((levels - 1) * 2) + 1;

    int large = 1;
    if (levels >= 2)
        large = 7;
    for (size_t i = 2; i < levels; i++)
    {
        large = large * 2 - 1;
    }
    for (size_t i = 0; i < height; i++)
    {
        std::string lines = "";
        for (size_t j = 0; j < large; j++)
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

void    Tree::painting(std::vector<std::string>& vec, Tree* tree, int x, int y, int levels)
{
    if (!tree)
        return ;
    vec[y][x] = tree->value;
    int spaces = 0;
    int level_cpy = levels;
    if (level_cpy - y >= 5)
        spaces = 1;
    while (level_cpy > y && level_cpy - y > 5)
    {
        spaces = (spaces * 2) + 3 - 1;
        level_cpy -= 2;
    }
    if (tree->left)
    {
        vec[y + 1][x - (1 + spaces)] = '/';
        painting(vec, tree->left, x - (spaces + 2), y + 2, levels);
    }
    if (tree->right)
    {
        vec[y + 1][x + (1 + spaces)] = '\\';
        painting(vec, tree->right, x + (spaces + 2), y + 2, levels);
    }
}

std::vector<std::string> Tree::fill_vector(Tree *tree, std::vector<std::string> vector)
{
    int levels = get_levels(tree);
    int large = 1;
    if (levels >= 2)
        large = 7;
    for (size_t i = 2; i < levels; i++)
    {
        large = large * 2 - 1;
    }
    int x = (large - 1) / 2;
    int y = 0;
    painting(vector, tree, x, y, ((levels - 1) * 2) + 1);
    return (vector);
}

int Tree::solve(Tree *tree)
{
    if (tree->value >= '0' && tree->value <= '9')
        return (tree->value - '0');

    int leftVal = solve(tree->left);
    int rightVal = 0;
    if (tree->right)
        rightVal = solve(tree->right);

    switch (tree->value) {
        case '&':
            return (leftVal & rightVal);
        case '|':
            return (leftVal | rightVal);
        case '^':
            return (leftVal ^ rightVal);
        case '>':
            return ((!leftVal) | rightVal);
        case '=':
            return (leftVal == rightVal);
        case '!':
            return (!leftVal);
    }
    return (0);
}

Tree::Tree( std::string str )
{
    Tree    *tree = make_tree(str);
    std::cout << "result = " << solve(tree) << std::endl;

    std::vector<std::string> vector = vector_tree(tree);
    vector = fill_vector(tree, vector);
    print_vector(vector);
}

int main(void)
{
    try
    {
        std::string str = "10&";
        std::cout << str << std::endl;
        Tree tree(str);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    try
    {
        std::string str = "00|00||";
        std::cout << str << std::endl;
        Tree tree(str);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    try
    {
        std::string str = "11|11||11|11|||";
        std::cout << str << std::endl;
        Tree tree(str);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    try
    {
        std::string str = "11|11||11|11|||11|11||11|11||||";
        std::cout << str << std::endl;
        Tree tree(str);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n";
    try
    {
        std::string str = "10!&1|10^>1=";
        std::cout << str << std::endl;
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
