#include <iostream>
#include <sstream>
#include <cmath>
#include <stack>
using namespace std;

const double Pi = acos(-1); //pi function

double Sin(double x) { //Function to round the sine value
    return (round(sin(x) * 10000000) / 10000000);
}

double Cos(double x) { //Function to round the cosine value
    return (round(cos(x) * 10000000) / 10000000);
}

double Ctg(double x) { //cotangient function
    double a = cos(x);
    double b = Sin(x);
    return (a / b);
}

struct Leksema //Structure describing any number or operation
{
    char type; // 0 for numbers, "+" for addition, etc.
    double value; //Value (only for numbers). Operations always have a value of "0"
};

bool Maths(stack <Leksema>& Stack_n, stack <Leksema>& Stack_o, Leksema& item) { //Mathematical function that performs calculations
    //The function is of type bool to return "false" if any error occurs.
    double a, b, c;
    a = Stack_n.top().value; //Take the top number from the stack of numbers
    Stack_n.pop(); //Remove the top number from the stack of numbers
    switch (Stack_o.top().type) {  //The type of the top operation from the stack with operations is checked
    case '+': //If the type of the top operation from the stack with addition operations
        b = Stack_n.top().value;
        Stack_n.pop();
        c = a + b;
        item.type = '0';
        item.value = c;
        Stack_n.push(item); //The result of the operation is pushed back onto the stack with numbers
        Stack_o.pop();
        break;

    case '-':
        b = Stack_n.top().value;
        Stack_n.pop();
        c = b - a;
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '^':
        b = Stack_n.top().value;
        Stack_n.pop();
        c = pow(b, a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '*':
        b = Stack_n.top().value;
        Stack_n.pop();
        c = a * b;
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '/':
        b = Stack_n.top().value;
        if (a == 0) {
            cerr << "\nYou can't divide by 0!\n";
            return false;
        }
        else {
            Stack_n.pop();
            c = (b / a);
            item.type = '0';
            item.value = c;
            Stack_n.push(item);
            Stack_o.pop();
            break;
        }

    case 's':
        c = Sin(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case 'c':
        c = Cos(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case 't':
        if (Cos(a) == 0) {
            cerr << "\nWrong argument for tangent!\n";
            return false;
        }
        else {
            c = tan(a);
            item.type = '0';
            item.value = c;
            Stack_n.push(item);
            Stack_o.pop();
            break;
        }

    case 'g':
        if (Sin(a) == 0) {
            cerr << "\nInvalid argument for cotangent!\n";
            return false;
        }
        else {
            c = Ctg(a);
            item.type = '0';
            item.value = c;
            Stack_n.push(item);
            Stack_o.pop();
            break;
        }

    case 'e':
        c = exp(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    default:
        cerr << "\nerror!\n";
        return false;
        break;
    }
    return true;
}

int getRang(char Ch) { //The function returns the priority of the operation: "1" for addition and subtraction, "2" for multiplication and division, and so on.
    if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'g' || Ch == 'e')return 4;
    if (Ch == '^')return 3;
    if (Ch == '+' || Ch == '-')return 1;
    if (Ch == '*' || Ch == '/')return 2;
    else return 0;
}

int main()
{
    
    while (true) {
        system("cls");
        cout << "   Hey! This program is a calculator!\n";
        cout << "   To use Pi enter 'p', to use E enter 'exp(1)'\n";
        cout << "   Enter an expression: ";
        std::string str;
        getline(cin, str);
        stringstream sstr{ str };

        char Ch; 
        double value;
        bool flag = true; 
        stack<Leksema> Stack_n; 
        stack<Leksema> Stack_o; 
        Leksema item; 
        while (true) {
            Ch = sstr.peek(); 
            if (Ch == '\377')break; 
            if (Ch == ' ') { 
                sstr.ignore();
                continue;
            }
            if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'e') { 
                char foo[3]; 
                for (int i = 0; i < 3; i++) {
                    Ch = sstr.peek();
                    foo[i] = Ch;
                    sstr.ignore();
                }
                if (foo[0] == 's' && foo[1] == 'i' && foo[2] == 'n') { 
                    item.type = 's';
                    item.value = 0;
                    Stack_o.push(item);
                    continue;
                }
                if (foo[0] == 'c' && foo[1] == 'o' && foo[2] == 's') { 
                    item.type = 'c';
                    item.value = 0;
                    Stack_o.push(item); 
                    continue;
                }
                if (foo[0] == 't' && foo[1] == 'a' && foo[2] == 'n') { 
                    item.type = 't';
                    item.value = 0;
                    Stack_o.push(item); 
                    continue;
                }
                if (foo[0] == 'c' && foo[1] == 't' && foo[2] == 'g') { 
                    item.type = 'g';
                    item.value = 0;
                    Stack_o.push(item); 
                    continue;
                }
                if (foo[0] == 'e' && foo[1] == 'x' && foo[2] == 'p') { 
                    item.type = 'e';
                    item.value = 0;
                    Stack_o.push(item); 
                    continue;
                }
            }
            if (Ch == 'p') { 
                item.type = '0';
                item.value = Pi;
                Stack_n.push(item); 
                flag = 0;
                sstr.ignore();
                continue;
            }
            if (Ch >= '0' && Ch <= '9' || Ch == '-' && flag == 1) { 
                sstr >> value;
                item.type = '0';
                item.value = value;
                Stack_n.push(item); 
                flag = 0;
                continue;
            }
            if (Ch == '+' || Ch == '-' && flag == 0 || Ch == '*' || Ch == '/' || Ch == '^') { 
                if (Stack_o.size() == 0) { 
                    item.type = Ch;
                    item.value = 0;
                    Stack_o.push(item); 
                    sstr.ignore();
                    continue;
                }
                if (Stack_o.size() != 0 && getRang(Ch) >
                    getRang(Stack_o.top().type)) {  
                    item.type = Ch;
                    item.value = 0;
                    Stack_o.push(item); 
                    sstr.ignore();
                    continue;
                }
                if (Stack_o.size() != 0 && getRang(Ch) <=
                    getRang(Stack_o.top().type)) { 
                    if (Maths(Stack_n, Stack_o, item) == false) { 
                        system("pause");
                        return 0;
                    }
                    continue;
                }
            }
            if (Ch == '(') { 
                item.type = Ch;
                item.value = 0;
                Stack_o.push(item); 
                sstr.ignore();
                continue;
            }
            if (Ch == ')') { 
                while (Stack_o.top().type != '(') {
                    if (Maths(Stack_n, Stack_o, item) == false) { 
                        system("pause");
                        return 0;
                    }
                }
                Stack_o.pop();
                sstr.ignore();
                continue;
            }
            else { 
                cout << "\nInvalid expression entered!\n";
                system("pause");
                return 0;
            }
        }
        while (Stack_o.size() !=
            0) { 
            if (Maths(Stack_n, Stack_o, item) == false) { 
                system("pause");
                return 0;
            }
            else continue; 
        }
        cout << "   answer: " << Stack_n.top().value << endl; 
        system("pause");
    }
    return 0;
}