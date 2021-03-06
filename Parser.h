
/**
*	Source : Parser.h
*	Description: Parser holds all the tokens generated by the scanner and parses the program using the grammer passed to it.
*				 It provides the interface to the grammer to access the next token, update the count of variables, function,
*				 and statments.
*/
#ifndef _PRASER_H
#define _PRASER_H

#include <vector>
#include "Token.h"
#include "Grammar.h"
#include "SymbolTable.h"
#include "ASTNode.h"

class Grammar;

class Parser
{
public:
	/*Consumes current token and moves to next token*/
	Token* nextToken();

	/*Retrives current token*/
	Token* curToken();
	
	/*Inserts a new token to the parser token list*/
	void addToken(Token *newToken);

	/*Starts parsing the program*/
	bool parseProgram();

	/*Returns number of variables decalred*/
	int getNumVar();

	/*Returns number of funtions in the program*/
	int getNumFunc();

	/*Retruns the number of statments in the program*/
	int getNumStmt();

	/*Increments Variable count*/
	void incrementVariableCount();

	/*Increments Function count*/
	void incrementFunctionCount();

	/*Decrements Variable count*/
	void decrementVariableCount();

	/*Increments Statement Count*/
	void incrementStmtCount();

	/*Returns SymbolTable reference*/
	SymbolTable* getSymbolTable();

	/*Ealutes the AST tree*/
	void evaluateASTTree(ASTNode *root, bool isTop = true, bool constAllowed = true);
	
	/*Initializes parsers and assigns grammer*/
	Parser(Grammar* newGrammar, SymbolTable* mySymTab);

	~Parser();

private:
	std::vector<Token *> *tokenVector;
	std::vector<Token *>::iterator tokenIT;

	int numVar;
	int numFunc;
	int numStmt;

	bool isDeclaration;
	Grammar* myGrammar;
	SymbolTable* mySymTab;
};
#endif
