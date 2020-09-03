#include<iostream>
using namespace std;

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data) {
	if (root == NULL)
	{
		root = GetNewNode(data);
	}

	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}

	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(BstNode* root, int data) {
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == data)
	{
		return true;
	}
	else if (data <= root->data)
	{
		return Search(root->left, data);
	}
	else
	{
		return Search(root->right, data);
	}
}

BstNode *FindMin(BstNode* root)
{
	while (root->left != NULL)
		root = root->left;
	return root;
}

BstNode* Delete(BstNode *root, int data) {
	if (root == NULL) return root;
	else if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	// Wohoo... I found you, Get ready to be deleted    
	else {
		// Case 1:  No child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if (root->left == NULL) {
			struct BstNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			struct BstNode *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			struct BstNode *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

//void Inorder(BstNode *root) {
//  if (root == NULL) return;
//
//  Inorder(root->left);       //Visit left subtree
//  printf("%d ", root->data);  //Print data
//  Inorder(root->right);      // Visit right subtree
//}

void PrintTree(BstNode *pNode, int n)
{
	if (pNode->left)
		PrintTree(pNode->left, n + 1);

	for (int i = 0; i < n; i++)
		printf(" ");
	printf("%d\n", pNode->data);

	if (pNode->right)
		PrintTree(pNode->right, n + 1);
}

/*Добавили очистку памяти*/
void del(BstNode *&Tree){
	if (Tree != NULL)                //Пока не встретится пустое звено
	{
		del(Tree->left);                //Рекурсивная функция прохода по левому поддереву
		del(Tree->right);                //Рекурсивная функци для прохода по правому поддереву
		delete Tree;                 //Убиваем конечный элемент дерева
		Tree = NULL;                 //Может и не обязательно, но плохого не будет
	}

}

void delnew(BstNode *&cur) {
	/*cur->left + cur->right = temp;*/
	//int(cur->right);
	//int(cur->left);
	//int(cur);
	if (cur->left == NULL || cur->right == NULL) { // если есть один потомок, или их вообще нет
		BstNode* sav = cur;
		if (cur->left != NULL) // перетаскиваем потомка на место вершины, а саму вершину удаляем
			cur = cur->left;
		else
			cur = cur->right;
		delete sav;
	}
	else { // дальше идет процедура удаления, если у вершины есть оба потомка
		if ((cur->left->data + cur->right->data) == cur->data){

			BstNode** p2 = &cur->right;
			while ((*p2)->left) p2 = &((*p2)->left);
			cur->data = (*p2)->data;
			del(*p2);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	BstNode* root = NULL;
	int choice = 0;
	int number = 0;
	do
	{
		cout << "1. добавление элемента" << endl;
		cout << "2. вывод дерева" << endl;
		cout << "3. удаление элемента" << endl;
		cout << "4. поиск элемента" << endl;
		cout << "5. очистка дерева\n";
		cout << "6. удалениe вершины с максимальной суммой 2 целых значений узла\n";


		cout << "ваш выбор?  ";
		cin >> choice;
		switch (choice)
		{
		case 1:   
			cout << "0 - The end of entering numbers" << endl;
			for (;;)
			{
				cout << "Введите число: ";
				cin >> number;
				if (number != 0)
					root = Insert(root, number);
				else
					break;
			}
			cout << endl;
			break;
		case 2:   
			//Inorder(root);
			PrintTree(root, 20);
			cout << endl;
			break;
		case 3:   
			number = 0;
			cout << "Please, enter number to delete: ";
			cin >> number;
			root = Delete(root, number);
			break;
		case 4:   
			number = 0;
			cout << "Введите число: ";
			cin >> number;
			if (Search(root, number) == true)
				cout << "Result: элемент найден\n\n";
			else
				cout << "Result: элемент не найден\n\n";
			break;
		case 5:
			del(root);
			cout << "\nУспешно! \n";
			cout << "\nдерево удалено \n";

			break;
		case 6:
			delnew(root);
			cout << "\nУспешно! \n";
			cout << "\nдерево удалено \n";

			break;
		}
	} while (choice != 0);
	return 0;
}