#include <iostream>
#include <cstdint>
#include <stack>

// uint32_t : standard 32-bit unsigned integer in <cstdint> c++ and <stdint.h> in c
// MAX 4294967295

//Time complexity: O(n) →  Not Applicable or Not Assessed
//Space complexity: N/A → Not Applicable or Not Assessed

auto eval_formula = [](const std::string& str) -> bool
{
    std::stack<char> tree;
    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == '1' || str[i] == '0')
            tree.push(str[i]);
        else if (str[i] == '!')
        {
            if (tree.size() < 1)
                throw("Error: RPN expression not correctly written");
            int result = !(tree.top() - '0');
            tree.pop();
            tree.push(result + '0');
        }
        else if (str[i] == '&' || str[i] == '|' || str[i] == '^' || str[i] == '>' || str[i] == '=')
        {
            if (tree.size() < 2)
                throw("Error: RPN expression not correctly written");
            int right = tree.top() - '0';
                tree.pop();
            int left = tree.top() - '0';
                tree.pop();
            if (str[i] == '&')
                tree.push((left & right) + '0');
            else if (str[i] == '|')
                tree.push((left | right) + '0');
            else if (str[i] == '^')
                tree.push((left ^ right) + '0');
            else if (str[i] == '>')
                tree.push(((!left) | right) + '0');
            else if (str[i] == '=')
                tree.push((left == right) + '0');
        }
        else
            throw("Error: character not valid");
    }
    if (tree.size() != 1)
        throw("Error: RPN expression not correctly written");
    return (tree.top() - '0');
};

int main(void)
{
	std::string	str = "1!0^";
    try
    {
        std::cout << str << " RPN -> " << eval_formula(str) << std::endl;
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    
}

//	Symbol	|	Mathematical equivalent	|		Description
// ------------------------------------------------------------
// 	0		|			⊥				|	false
// 	1		|			⊤				|	true
// 	!		|			¬				|	Negation
// 	&		|			∧				|	Conjunction
// 	|		|			∨				|	Disjunction
// 	ˆ		|			⊕				|	Exclusive disjunction
// 	>		|			⇒				|	Material condition
// 	=		|			⇔				|	Logical equivalence


// Binary Abstract Syntax Tree structure (Binary AST)
// Each node can have at most 2 children
// Binary operators (+, -, *, /) and and expressions where operations combine 2 operands
// Often with aritmethic expressions and boolean expressions
//       (*)
//      /   \
//    (a)    (+)
//          /   \
//        (b)   (c)

// Abstract Syntax Tree structure (AST)
// The nodes can have any number of children
// Can represent statements, blocks of code, functions with many arguments, lists, etc
// Flexible, for entire programs, binary operations, etc
//        (function add)
//         /    |     \
//    (param a)(param b)(body)
//                        |
//                     (return)
//                        |
//                       (+)
//                      /   \
//                    (a)   (b)

// 1 0 1 1 OR4

// AST
//     (OR4)
//    / |  | \
//  (1)(0)(1)(1)

// BINARY AST
//         (|)
//        /   \
//      (|)   (1)
//     /   \
//   (|)   (1)
//  /   \
// (1)  (0)
