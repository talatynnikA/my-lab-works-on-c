struct Stack
{
	int data;             //�������������� �������
	Stack *head;		 //������� ����� 
	Stack *next;		 //��������� �� ��������� �������
};
FILE *f;
void show(Stack *myStk);         //��������
int pop(Stack *myStk);           //��������
void push(int x, Stack *myStk);  //��������
void toFile(Stack *myStk);
void fromFile(Stack *myStk);
void clear(Stack *myStk);
Stack *newStackless(Stack * myStk);
Stack *newStackMore(Stack *myStk);