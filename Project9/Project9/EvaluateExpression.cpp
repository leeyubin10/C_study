#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>
#include "ImprovedStack.h"

using namespace std;

// 숫자, 연산자, 괄호로 수식 분리
vector<string> split(const string& expression);

// 수식 계산 및 결과 변환
int evaluateExpression(const string& expression);

// 연산 수행
void processAnOperator(
	Stack<int>& operandStack, Stack<char>& operatorStack);

int main()
{
	string expression;
	cout << "Enter an expression: ";
	getline(cin, expression);

	cout << expression << " = " << evaluateExpression(expression) << endl;

	return 0;
}

vector<string> split(const string& expression)
{
	vector<string> v;
	string numberString;

	for (unsigned i = 0; i < expression.length(); i++)
	{
		if (isdigit(expression[i]))
			numberString.append(1, expression[i]);
		else
		{
			if (numberString.size() > 0)
			{
				v.push_back(numberString);
				numberString.erase();
			}

			if (!isspace(expression[i]))
			{
				string s;
				s.append(1, expression[i]);
				v.push_back(s);
			}
		}
	}

	// 마지막 숫자 문자열 저장
	if (numberString.size() > 0)
		v.push_back(numberString);

	return v;
}

// 수식 계산
int evaluateExpression(const string& expression)
{
	// 피연산자를 저장하기 위한 operandStack 생성
	Stack<int> operandStack;

	// 연산자를 저장하기 위한 operatorStack 생성
	Stack<char> operatorStack;

	// 피연산자와 연산자 추출
	vector<string> tokens = split(expression);

	// 1단계: 토큰(token) 검색
	for (unsigned i = 0; i < tokens.size(); i++)
	{
		if (tokens[i][0] == '+' || tokens[i][0] == '-')
		{
			// 연산자 스택의 상단에 있는 모든 +,-,*,/ 처리
			while (!operatorStack.empty() && (operatorStack.peek() == '+' || operatorStack.peek() == '-' || operatorStack.peek() == '*' || operatorStack.peek() == '/' || operatorStack.peek() == '%' || operatorStack.peek() == '^'))
			{
				processAnOperator(operandStack, operatorStack);
			}

			// 연산자 스택으로 + 또는 - 연산자 푸시(push)
			operatorStack.push(tokens[i][0]);
		}
		else if (tokens[i][0] == '*' || tokens[i][0] == '/' || tokens[i][0] == '%')
		{
			// 연산자 스택의 상단에 있는 모든 *, / 처리
			while (!operatorStack.empty() && (operatorStack.peek() == '*' || operatorStack.peek() == '/' || operatorStack.peek() == '%' || operatorStack.peek() == '^'))
			{
				processAnOperator(operandStack, operatorStack);
			}

			// 연산자 스택으로 * 또는 / 연산자 푸시
			operatorStack.push(tokens[i][0]);
		}
		else if (tokens[i][0] == '^')
		{
			while (!operatorStack.empty() && (operatorStack.peek() == '^'))
			{
				processAnOperator(operandStack, operatorStack);
			}

			// 연산자 스택으로 * 또는 / 연산자 푸시
			operatorStack.push(tokens[i][0]);
		}
		else if (tokens[i][0] == '(')
		{
			operatorStack.push('(');
		}
		else if (tokens[i][0] == ')')
		{
			// '('가 나타날 때까지 스택의 모든 연산자 처리
			while (operatorStack.peek() != '(')
			{
				processAnOperator(operandStack, operatorStack);
			}

			operatorStack.pop(); // 스택으로부터 '(' 기호 팝(pop)
		}
		else
		{ // 피연산자 검색. 스택에 정수인 피연산자 푸시
			operandStack.push(atoi(tokens[i].c_str()));
		}
	}

	// 2단계: 스택에서 남은 모든 연산자 처리
	while (!operatorStack.empty())
	{
		processAnOperator(operandStack, operatorStack);
	}

	// 결과 변환
	return operandStack.pop();
}

// 연산자 하나 처리: operatorStack으로부터 연산자를 가져와서
// operandStack에 있는 피연산자에 적용
void processAnOperator(Stack<int>& operandStack, Stack<char>& operatorStack)
{
	char op = operatorStack.pop();
	int op1 = operandStack.pop();
	int op2 = operandStack.pop();
	if (op == '+')
		operandStack.push(op2 + op1);
	else if (op == '-')
		operandStack.push(op2 - op1);
	else if (op == '*')
		operandStack.push(op2 * op1);
	else if (op == '/')
		operandStack.push(op2 / op1);
	else if (op == '%')
		operandStack.push(op2 % op1);
	else if (op == '^')
		operandStack.push(static_cast<int>(pow(op2, op1)));
}