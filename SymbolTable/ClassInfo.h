#ifndef CLASS_INFO_H
#define CLASS_INFO_H

#include <vector>
#include <unordered_map>
#include <string>
#include "MethodInfo.h"
#include "VariableInfo.h"
#include "Symbol.h"


namespace SymbolTable {

class ClassInfo : public Symbol {
public:
    ClassInfo( std::string _name, Position _position );
    void AddMethodInfo(const MethodInfo *method );
    void AddVariableInfo(const VariableInfo *variable );
    void AddSuperClassName(const std::string& symbol) { superClass = StringSymbol::GetIntern(symbol); }
    void AddSuperClassName(const StringSymbol* symbol) { superClass = symbol; }

    const std::vector<const StringSymbol*>& GetMethodNames() const { return methodsName; }
    const std::vector<const StringSymbol*>& GetVarsNames() const { return varsName; }
    int GetMethodCount() const { return methodsName.size(); }
    int GetVarsCount() const { return varsName.size(); }
    const StringSymbol* GetSuperClassName() const { return superClass; }
    const TypeInfo& GetTypeInfo() const { return info; }

    const VariableBlock& GetVariableBlock() const;
    const MethodBlock& GetMethodsBlock() const;

private:
    std::vector< const StringSymbol* > methodsName;
    std::vector< const StringSymbol* > varsName;
    VariableBlock variableBlock;
    MethodBlock methodsBlock;
    const StringSymbol* superClass;
    TypeInfo info;
};

typedef std::unordered_map<const StringSymbol*, std::unique_ptr<const ClassInfo>> ClassBlock;
}

#endif
