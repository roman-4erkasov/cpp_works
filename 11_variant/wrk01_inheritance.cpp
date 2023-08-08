#include <iostream>
#include <string>
#include <variant>


class Node: private std::variant<bool, int, long, double, std::string>
{
public:
    using variant::variant;
    using Value = variant;

    struct MakeNodeHelper {
        Node operator()(bool value){return {value};}
        Node operator()(int value){return {value};}
        Node operator()(long value){return {value};}
        Node operator()(double value){return {value};}
        Node operator()(std::string value){return {value};}
    };

    static Node MakeNode(Value value){
        return std::visit(MakeNodeHelper{}, value);
    }

    //TODO: double code functions IsNNN(), 
    bool IsBool() const {
        return std::holds_alternative<bool>(*this);
    }
    bool AsBool() const {
        using namespace std::literals;
        if (!IsBool()) {
            throw std::logic_error("Not a bool"s);
        }

        return std::get<bool>(*this);
    }

    bool IsInt() const {
        return std::holds_alternative<int>(*this);
    }
    int AsInt() const {
        using namespace std::literals;
        if (!IsInt()) {
            throw std::logic_error("Not an int"s);
        }
        return std::get<int>(*this);
    }

    bool IsPureDouble() const {
        return std::holds_alternative<double>(*this);
    }
    bool IsDouble() const {
        return IsInt() || IsPureDouble();
    }
    double AsDouble() const {
        using namespace std::literals;
        if (!IsDouble()) {
            throw std::logic_error("Not a double"s);
        }
        return IsPureDouble() ? std::get<double>(*this) : AsInt();
    }

    bool IsString() const {
        return std::holds_alternative<std::string>(*this);
    }
    const std::string& AsString() const {
        using namespace std::literals;
        if (!IsString()) {
            throw std::logic_error("Not a string"s);
        }

        return std::get<std::string>(*this);
    }

    Value& GetValue() {
        return *this;
    }
};
// bool, unsigned short, short, unsigned, int, long, long long, double, std::string
Node get_node_1(Node::Value value){
    if (std::holds_alternative<bool>(value))  
        return Node(std::get<bool>(value)); 
    else if (std::holds_alternative<unsigned short>(value))  
        return Node(std::get<unsigned short>(value)); 
    else if (std::holds_alternative<unsigned>(value))  
        return Node(std::get<unsigned>(value)); 
    else if (std::holds_alternative<int>(value))  
        return Node(std::get<int>(value)); 
    else if (std::holds_alternative<long>(value))  
        return Node(std::get<long>(value)); 
    else if (std::holds_alternative<long long>(value))  
        return Node(std::get<long long>(value)); 
    else if (std::holds_alternative<double>(value))  
        return Node(std::get<double>(value)); 
    else if (std::holds_alternative<std::string>(value))  
        return Node(std::get<std::string>(value)); 
    else throw std::logic_error( 
        "get_node_1: Unsupported value for arugent \"value\"" 
    );
}

Node get_node_2(Node::Value value){
    return Node::MakeNode(value);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
