#include <cmath>
#include "Stack.h"
#include "Node.h"

using namespace std;

void deleteTree(const Node<string> *root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

float operate(const string &op, const float &a, const float &b) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    if (op == "%") return fmod(a, b);
    if (op == "^") return pow(a, b);
    return 0;
}

bool isOperator(const string &s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

float evaluateExpressionTree(const Node<string> &root) {
    if (!isOperator(root.data)) {
        return stof(root.data);
    }
    return operate(root.data, evaluateExpressionTree(*root.left), evaluateExpressionTree(*root.right));
}

Node<string> *createExpressionTreeFromPostfixExpression(Stack<string> &postfixStack) {
    const string s = postfixStack.pop();
    if (!isOperator(s)) {
        return new Node(s);
    }
    auto *node = new Node(s);
    node->right = createExpressionTreeFromPostfixExpression(postfixStack);
    node->left = createExpressionTreeFromPostfixExpression(postfixStack);
    return node;
}

Stack<string> fillStack(const string &expr) {
    Stack<string> stack = *new Stack<string>();
    vector<string> separatedElements;
    string aux;
    for (auto &c: expr) {
        if (c == ' ') {
            separatedElements.push_back(aux);
            aux = "";
            continue;
        }
        aux += c;
    }
    separatedElements.push_back(aux);
    for (auto &s: separatedElements) {
        stack.push(s);
    }
    return stack;
}


int main() {
    const string expr = "8 2 / 4 2 * 1 + -";
    Stack<string> stack = fillStack(expr);
    Node<string> *root = createExpressionTreeFromPostfixExpression(stack);
    cout << evaluateExpressionTree(*root) << endl;
    deleteTree(root);
    return 0;
}
