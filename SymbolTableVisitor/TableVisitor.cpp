#include "TableVisitor.h"

#include "DeclarationException.h"

namespace SymbolTable {

void TableVisitor::ParseProgram(AST::Program* program)
{
    program->accept(this);
    for(auto className = table.GetClassesNames().begin();
        className != table.GetClassesNames().end(); ++className)
    {
        try {
            std::string name = (*className)->GetString();
            std::cout << "class " << name << ":" << std::endl;
            auto classInfo = table.GetClass(name, Position(0,0));
            table.AddClassToScope(name, Position(0,0));
            printClassInfo(classInfo);
            table.FreeLastScope();
            std::cout << std::endl;
        } catch(DeclarationException e) {
            std::cout << "Declaration error:" << e.what() << std::endl;
        }
    }
}

void TableVisitor::visit(const AST::Program* node)
{
    for (auto el : node->classes_)
    {
        el->accept(this);
    }
}

void TableVisitor::visit(const AST::MainClass* node)
{
    for (auto statement : node->statements_)
    {
        statement->accept(this);
    }
}

void TableVisitor::visit(const AST::ClassDeclaration* node)
{
    auto newClass = new ClassInfo(node->id_->name_, fromCoords(node->coordinates_));
    if(node->parentId_.get() != nullptr) {
        newClass->AddSuperClassName(node->parentId_->name_);
    }
    for (auto var : node->vars_)
    {
        newClass->AddVariableInfo(new VariableInfo(var->id_->name_,
                                                   fromCoords(var->coordinates_),
                                                   fromType(var->type_.get())));
    }
    for (auto method : node->methods_)
    {
        auto methodInfo = new MethodInfo(method->id_->name_,
                                         method->type_->type_name_,
                                         fromCoords(method->coordinates_),
                                         fromType(method->type_.get()),
                                         method->modifier_->modifier_ == AST::T_PUBLIC ? Q_Public : Q_Private);
        for(auto arg : method->arguments_)
        {
            methodInfo->AddArgInfo(new VariableInfo(arg->id_->name_,
                                                    fromCoords(arg->coordinates_),
                                                    fromType(arg->type_.get())));
        }
        for(auto var : method->arguments_)
        {
            methodInfo->AddVariableInfo(new VariableInfo(var->id_->name_,
                                                         fromCoords(var->coordinates_),
                                                         fromType(var->type_.get())));
        }
        newClass->AddMethodInfo(methodInfo);
    }
    table.AddClass(newClass, fromCoords(node->coordinates_));
}

TypeInfo TableVisitor::fromType(const AST::IType* type)
{
    switch (type->type_value_) {
    case AST::T_INT:
        return TypeInfo(VT_Int);
    case AST::T_INT_ARRAY:
        return TypeInfo(VT_IntArray);
    case AST::T_BOOLEAN:
        return TypeInfo(VT_Boolean);
    case AST::T_CLASS:
        return TypeInfo(VT_UserClass, type->type_name_);
    default:
        break;
    }
}

void TableVisitor::printClassInfo(const ClassInfo* classInfo)
{
    if(classInfo->GetSuperClassName() != nullptr) {
        std::cout << "  Super: " << classInfo->GetSuperClassName()->GetString() << std::endl;
        auto superClass = table.GetClass(classInfo->GetSuperClassName()->GetString(), Position(0, 0));
        printClassInfo(superClass);
    }

    for(auto varName = classInfo->GetVarsNames().begin();
        varName != classInfo->GetVarsNames().end(); ++varName)
    {
        std::cout << "    ";
        auto variable = table.GetVariable((*varName)->GetString(), Position(0, 0));
        printVariable(variable);
    }

    for(auto methodName = classInfo->GetMethodNames().begin();
        methodName != classInfo->GetMethodNames().end(); ++methodName) {
        auto method = table.GetMethod((*methodName)->GetString(), Position(0, 0));
        table.AddMethodToScope(method->GetName()->GetString(), Position(0, 0));
        std::cout << "    " << (method->GetQualifier() == Q_Public ? "public " : "private ");
        printType(method->GetReturnType());
        std::cout << method->GetName()->GetString() << std::endl;
        std::cout << "      Args:" << std::endl;
        auto& args= method->GetArgsNames();
        for(auto arg = args.begin(); arg != args.end(); ++arg) {
            auto var = table.GetVariable((*arg)->GetName()->GetString(), Position(0, 0));
            std::cout << "        ";
            printVariable(var);
        }
        std::cout << "      Local vars:" << std::endl;
        auto& vars = method->GetVarsNames();
        for(auto var = vars.begin(); var != vars.end(); ++var) {
            auto varInfo = table.GetVariable((*var)->GetName()->GetString(), Position(0, 0));
            std::cout << "        ";
            printVariable(varInfo);
        }
        table.FreeLastScope();
    }
}

void TableVisitor::printVariable(const VariableInfo* varInfo)
{
    printType(varInfo->GetType());
    std::cout << " " << varInfo->GetName()->GetString() << std::endl;
}

void TableVisitor::printType(const TypeInfo &type)
{
    switch (type.GetType()) {
    case VT_Int:
        std::cout << "int ";
        break;
    case VT_IntArray:
        std::cout << "int[] ";
        break;
    case VT_Boolean:
        std::cout << "boolean ";
        break;
    case VT_UserClass:
        std::cout << "class " << type.GetUserClass()->GetString();
        break;
    default:
        break;
    }
}

}
