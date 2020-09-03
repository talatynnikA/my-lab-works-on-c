struct Stack
{
	int data;             //информационный элемент
	Stack *head;		 //вершина стека 
	Stack *next;		 //указатель на следующий элемент
};
FILE *f;
void show(Stack *myStk);         //прототип
int pop(Stack *myStk);           //прототип
void push(int x, Stack *myStk);  //прототип
void toFile(Stack *myStk);
void fromFile(Stack *myStk);
void clear(Stack *myStk);
Stack *newStackless(Stack * myStk);
Stack *newStackMore(Stack *myStk);