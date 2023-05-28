﻿import <string>;
import <iostream>;
import <stddef.h>;

export module TreeModule;

export template <class Type> class CNode;
export template <class Type> class CTreeF;
export template <class Type> class CTreeExpr;

export template <class Type>
class CNode {
public:
	Type data;
	CNode* left;
	CNode* right;

public:
	CNode() {
		left = nullptr;
		right = nullptr;
	}
	CNode(Type _data) {
		data = _data;
		left = nullptr;
		right = nullptr;
	}

	friend class CTreeF<Type>;
};

export template <class Type>
class CTreeF {
private:
	CNode<Type>* root = nullptr;
protected:
	bool find(CNode<Type>* _node, Type _data) {
		if (_node == nullptr) {
			return false;
		}

		if (_node->data == _data) {
			return true;
		}
		else if (_data < _node->data) {
			return find(_node->left, _data);
		}
		else {
			return find(_node->right, _data);
		}
	}
	CNode<Type>* findMin(CNode<Type>* _node) {
		CNode<Type>* current = _node;
		while (current && current->left != nullptr) {
			current = current->left;
		}
		return current;
	}
	CNode<Type>* insert(CNode<Type>* _node, Type _data) {
		if (_node == nullptr) {
			return new CNode<Type>(_data);
		}

		if (_data < _node->data) {
			_node->left = insert(_node->left, _data);
		}
		else {
			_node->right = insert(_node->right, _data);
		}

		return _node;
	}
	CNode<Type>* remove(CNode<Type>* _node, Type _data) {
		if (_node == nullptr) {
			return nullptr;
		}

		if (_data < _node->data) {
			_node->left = remove(_node->left, _data);
		}
		else if (_data > _node->data) {
			_node->right = remove(_node->right, _data);
		}
		else {
			if (_node->left == nullptr) {
				CNode<Type>* temp = _node->right;
				delete _node;
				return temp;
			}
			else if (_node->right == nullptr) {
				CNode<Type>* temp = _node->left;
				delete _node;
				return temp;
			}

			CNode<Type>* minNode = findMin(_node->right);
			_node->data = minNode->data;
			_node->right = remove(_node->right, minNode->data);
		}

		return _node;
	}
public:
	void insert(Type _data) {
		root = insert(root, _data);
	}
	bool find(Type _data) {
		return find(root, _data);
	}
	void remove(Type _data) {
		root = remove(root, _data);
	}
};

export template <class Type>
class CTreeExpr {
private:
	CNode<Type>* root;
protected:
	CNode<Type>* buildExpressionTree(std::string expression, int index) {
		if (index >= expression.length()) {
			return nullptr;
		}

		CNode<Type>* node = new CNode<Type>(expression[index]);

		index++;
		if (index < expression.length() && expression[index] != ')') {
			node->left = buildExpressionTree(expression, index);
		}
		index++;
		if (index < expression.length() && expression[index] != ')') {
			node->right = buildExpressionTree(expression, index);
		}

		return node;
	}
	int evaluateExpressionTree(CNode<Type>* _node) {
		if (_node == nullptr) {
			return 0;
		}

		if (isdigit(_node->data)) {
			return _node->data - '0';
		}

		int leftValue = evaluateExpressionTree(_node->left);
		int rightValue = evaluateExpressionTree(_node->right);

		switch (_node->data) {
		case '+':
			return leftValue + rightValue;
		case '-':
			return leftValue - rightValue;
		case '*':
			return leftValue * rightValue;
		case '/':
			return leftValue / rightValue;
		default:
			std::cout << "Некорректное выражение.\n";
			return 0;
		}
	}
public:
	void buildExpressionTree(std::string expression) {
		root = buildExpressionTree(expression, 0);
	}
	int evaluateExpressionTree() {
		return evaluateExpressionTree(root);
	}
};
