#include <iostream>>
#include <array>

using namespace std;

class Dish {
private:
	string description;

public:
	Dish() {

	}

	Dish(string description) {
		this->description = description;
	}

	string get_description() {
		return this->description;
	}
};


class Stack
{
private:
	array<Dish, 9> my_stack;
	int current_size = 0;
public:
	Stack() {
		Dish fakedish = Dish("This Dish doesn't exist...");
		my_stack[0] = fakedish;
	}
	void push(Dish new_dish) {
		if (current_size > 8) {
			cout << "The current stack is full, remove a dish or start a new stack." << endl;
		}
		else {
			my_stack[current_size] = new_dish;
			current_size++;
		}
	}
	Dish pop() {
		remove();
		return peek(1);
	}
	Dish peek(int i=0) {
		if (i < 1) { i = 0;}else { i = 1; }
		return my_stack[current_size-1 + i];
	}
	void remove() {
		if (current_size > 0) {
			current_size = current_size - 1;
		}
		else {
			cout << "The stack is empty..." << endl;
		}
	}
	void clear() {
		if (current_size > 0) {
			current_size = 0;
		}
		else {
			cout << "The stack is empty..." << endl;
		}
	}
	int size() {
		return current_size;
	}
};


int main() {
	Stack first_stack;
	Dish dish1 = Dish("A dish with one fish pattern on it");
	Dish dish2 = Dish("A dish with two fish pattern on it");
	Dish dish3 = Dish("A dish with red fish pattern on it");
	Dish dish4 = Dish("A dish with blue fish pattern on it");



	first_stack.push(dish1);
	first_stack.push(dish2);
	cout << first_stack.peek().get_description() << endl;
	cout << first_stack.pop().get_description() << endl;
	first_stack.push(dish3);
	first_stack.push(dish4);

	Stack second_stack;
	second_stack.push(dish2);
	//list the first stack
	cout << "This first stack has: " << endl;
	int stack_size = first_stack.size();
	for (int i = 0; i < stack_size; i++)
	{
		cout << first_stack.pop().get_description() << endl;
	}
	//lists the second stack
	cout << "This second stack has: " << endl;
	stack_size = second_stack.size();
	for (int i = 0; i < stack_size; i++)
	{
		cout << second_stack.pop().get_description() << endl;
	}

	first_stack.push(dish1);
	first_stack.push(dish2);
	first_stack.push(dish3);
	first_stack.push(dish4);
	first_stack.clear();

	//retry's to list the first stack
	cout << "This first stack again: " << endl;
	stack_size = first_stack.size();
	for (int i = 0; i < stack_size; i++)
	{
		cout << first_stack.pop().get_description() << endl;
	}

	return 0;
}