#include <codeanalysis/BoundExpressionNode.hpp>

namespace trylang
{
    BoundUnaryExpression::BoundUnaryExpression(BoundUnaryOperator* op, std::unique_ptr<BoundExpressionNode> operand)
        : _op(op), _operand(std::move(operand))
    {}
    
    const char* BoundUnaryExpression::Type()
    {
        return _op->_resultType;
    }

    BoundNodeKind BoundUnaryExpression::Kind()
    {
        return BoundNodeKind::UnaryExpression;
    }


    BoundLiteralExpression::BoundLiteralExpression(const object_t& value)
        : _value(value)
    {}

    const char* BoundLiteralExpression::Type()
    {   
        return trylang::assign_type_info(*_value);
    }

    BoundNodeKind BoundLiteralExpression::Kind()
    {
        return BoundNodeKind::LiteralExpression;
    }

    BoundBinaryExpression::BoundBinaryExpression(std::unique_ptr<BoundExpressionNode> left, BoundBinaryOperator* op, std::unique_ptr<BoundExpressionNode> right)
        : _left(std::move(left)), _op(op), _right(std::move(right))
    {}

    const char* BoundBinaryExpression::Type()
    {
        return _op->_resultType;
    }
    
    BoundNodeKind BoundBinaryExpression::Kind()
    {
        return BoundNodeKind::BinaryExpression;
    }

    BoundVariableExpression::BoundVariableExpression(VariableSymbol variable)
        : _variable(std::move(variable))
    {}

    BoundNodeKind BoundVariableExpression::Kind()
    {
        return BoundNodeKind::VariableExpression;
    }

    const char* BoundVariableExpression::Type()
    {
        return _variable._type;
    }

    BoundAssignmentExpression::BoundAssignmentExpression(VariableSymbol variable, std::unique_ptr<BoundExpressionNode> expression)
        : _variable(std::move(variable)), _expression(std::move(expression))
    {}

    const char* BoundAssignmentExpression::Type()
    {
        return _expression->Type();
    }

    BoundNodeKind BoundAssignmentExpression::Kind()
    {
        return BoundNodeKind::AssignmentExpression;
    }


}