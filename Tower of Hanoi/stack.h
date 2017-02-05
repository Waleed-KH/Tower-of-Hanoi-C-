template <class Type>
class stack
{
private:
	int maxSize;
	int stackTop;
	Type* list;

public:
	stack();
	stack(int);
	bool empty();
	bool full();
	int size();
	void push(Type);
	Type top();
	void pop();
};

template <class Type>
stack<Type>::stack() {
}

template <class Type>
stack<Type>::stack(int size)
{
	if (size <= 0)
		maxSize = 100;
	else
		maxSize = size;

	stackTop = 0;
	list = new Type[maxSize];
}

template <class Type>
bool stack<Type>::empty()
{
	return (stackTop <= 0);
}

template <class Type>
bool stack<Type>::full()
{
	return (stackTop == maxSize);
}

template <class Type>
int stack<Type>::size()
{
	return stackTop;
}

template <class Type>
void stack<Type>::push(Type newItem)
{
	if (!full())
		list[stackTop++] = newItem;
}

template <class Type>
Type stack<Type>::top()
{
	if (!empty())
		return list[stackTop - 1];
}

template <class Type>
void stack<Type>::pop()
{
	if (!empty())
		stackTop--;
}