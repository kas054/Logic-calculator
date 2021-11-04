#ifndef LOGICELEMENT_H
#define LOGICELEMENT_H
#include <exception>
#include <iostream>
#include <limits>

template <class T>
int getNum(T& a)
{
    while (true)
    {
        std::cin >> a;
        if (!std::cin.good())
        {
            if (std::cin.eof())
                return -1;
            std::cout << "You are wrong; repeat please! --> ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return 1;
    }
}
enum Types {
    Input, 
    Output,
};


class Terminal
{
private:

    Types Type;    // Enum
    int Connects; //  Range: 0-1 for input || 0-3 for output
    int position; // 0,1, (2 - Not stated)

public:

    Terminal() : Type(Input), Connects(0), position(2) {}
    Terminal(Types type, int pos, int con) : Type(type), position(pos), Connects(con) {}
    Types getType() const;
    int getConnects() const;
    int getposition() const;
    void setposition(int pos);
    void setconnects(int con);
    void settype(Types typ);

};

class LogicElement {
private:
    int RealSZ; // Shows how many terminals in logic element 
    Terminal *ar;

public:
    LogicElement() : RealSZ(0), ar(nullptr) {}
    LogicElement(int in, int out);
    ~LogicElement(); // destructor
    LogicElement(const LogicElement& le); // copy constructor
    LogicElement(LogicElement&& le); // Move constructor
    LogicElement& operator =(LogicElement&& le); // moving assignment operator
    LogicElement& operator =(const LogicElement&); // overload operator = (copy)

    //Metods

    void newpositionforall(int *mass);
    void PrintAllInfo() const;
    int positioncheck(int num) const;
    void newposition(int num, int pos);
    void increaseNconnections(int num);
    void decreaseNconnections(int num);
    void addTerminal(Types Type, int con, int pos);


    int getRealSZ() const;
    Terminal getar(int i) const;
    friend std::ostream& operator <<(std::ostream&, const LogicElement&); // overload for "print all info"
    LogicElement& operator +=(const Terminal&); // overload add terminal to logic element
    LogicElement& operator +(int); // overload increase  number of connections for define ternimal
    LogicElement& operator -(int); // overload decrease  number of connections for define ternimal
    Terminal & operator [](int);
};
#endif
