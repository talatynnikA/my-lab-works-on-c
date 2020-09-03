// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "Tree.h"
#include <fstream>
using namespace std;
struct NodeTree
{
	int  key;
};
//-------------------------------
btree::CMP cmpfnc(void* x, void* y)    // Сравнение
{
	btree::CMP rc = btree::EQUAL;
	if (((NodeTree*)x)->key  <  ((NodeTree*)y)->key)
		rc = btree::LESS;
	else
	if (((NodeTree*)x)->key  >((NodeTree*)y)->key)
		rc = btree::GREAT;
	return rc;
}
//-------------------------------
void printNode(void* x)               // Вывод при обходе
{
	cout << ((NodeTree*)x)->key << ends;
}
//-------------------------------
bool buildTree(char *FileName, btree::Object& tree) //Построение дерева из файла
{
	bool rc = true;
	FILE *inFile;
	fopen_s(&inFile, FileName, "r");
	if (inFile == NULL)
	{
		cout << "Ошибка открытия входного файла" << endl;
		rc = false; return rc;
	}
	while (!feof(inFile)) // заполнение дерева 
	{
		int num;
		fscanf_s(inFile, "%d", &num, 1);
		NodeTree *a = new NodeTree();
		a->key = num;
		tree.insert(a);
	}
	fclose(inFile);
	return rc;
}
FILE * outFile;
//-------------------------------
void saveToFile(void *x)              // Запись одного элемента в файл
{
	NodeTree *a = (NodeTree*)x;
	int q = a->key;
	fprintf(outFile, "%d\n", q);
}
//-------------------------------
void saveTree(btree::Object &tree, char *FileName)    //Сохранение дерева в файл 
{
	fopen_s(&outFile, FileName, "w");
	if (outFile == NULL)
	{
		cout << "Ошибка открытия выходного файла" << endl;
		return;
	}
	tree.Root->scanDown(saveToFile);
	fclose(outFile);
}
////-------------------------------
//void iterPostorder(Node *parent) {
//	Stack *ps = createStack();
//	Node *lnp = NULL;
//	Node *peekn = NULL;
//
//	while (!ps->size == 0 || root != NULL) {
//		if (root) {
//			push(ps, root);
//			root = root->left;
//		}
//		else {
//			peekn = peek(ps);
//			if (peekn->right && lnp != peekn->right) {
//				root = peekn->right;
//			}
//			else {
//				pop(ps);
//				printf("visited %d\n", peekn->data);
//				lnp = peekn;
//			}
//		}
//	}
//
//	freeStack(&ps);
//}
//------------------------------- Из прошлой лабы
//void delnew(Node *&a) {
//	/*cur->left + cur->right = temp;*/
//	//int(cur->right);
//	//int(cur->left);
//	//int(cur);
//	if (cur->left == NULL || cur->right == NULL) { // если есть один потомок, или их вообще нет
//		BstNode* sav = cur;
//		if (cur->left != NULL) // перетаскиваем потомка на место вершины, а саму вершину удаляем
//			cur = cur->left;
//		else
//			cur = cur->right;
//		delete sav;
//	}
//	else { // дальше идет процедура удаления, если у вершины есть оба потомка
//		if ((cur->left->data + cur->right->data) == cur->data){
//
//			BstNode** p2 = &cur->right;
//			while ((*p2)->left) p2 = &((*p2)->left);
//			cur->data = (*p2)->data;
//			del(*p2);
//		}
//	}
//}
//-------------------------------



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian");
	btree::Object demoTree = btree::create(cmpfnc);
	int k, choice;
	NodeTree a1 = { 1 }, a2 = { 2 }, a3 = { 3 }, a4 = { 4 }, a5 = { 5 }, a6 = { 6 };
	bool rc = demoTree.insert(&a4);   //           4  
	rc = demoTree.insert(&a1);        //   1             
	rc = demoTree.insert(&a6);        //                   6
	rc = demoTree.insert(&a2);        //      2     
	rc = demoTree.insert(&a3);        //         3
	rc = demoTree.insert(&a5);        //                 5	
	for (;;)
	{
		NodeTree *a = new NodeTree;
		cout << "1 - вывод дерева на экран" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - сохранить в файл" << endl;
		cout << "5 - загрузить из файла" << endl;
		cout << "6 - очистить дерево" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choice;
		switch (choice)
		{
		case 0:   	exit(0);
		case 1:  	if (demoTree.Root)
			demoTree.Root->scanByLevel(printNode);
					else
						cout << "Дерево пустое" << endl;
			break;
		case 2: 	cout << "введите ключ" << endl;  cin >> k;
			a->key = k;
			demoTree.insert(a);
			break;
		case 3:  	cout << "введите ключ" << endl;  cin >> k;
			a->key = k;
			demoTree.deleteByData(a);
			break;
		case 4:   	saveTree(demoTree, "G.txt");
			break;
		case 5:  	buildTree("G.txt", demoTree);
			break;
		case 6:	while (demoTree.Root)
			demoTree.deleteByNode(demoTree.Root);
			break;
		//case 7: iterPostorder(demoTree.Root);
			break;
		}
	}
	return 0;
}
