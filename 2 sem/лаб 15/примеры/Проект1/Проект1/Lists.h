#pragma once              //������������ ���� Lists.h
#define LISTNIL (Element*)-1
namespace listx
{
	struct Element
	{
		Element* prev;
		Element* next;
		void* data;
		Element(Element* prev, void* data, Element* next)
		{
			prev = prev;
			data = data;
			next = next;
		}
		Element* getNext()
		{
			return next;
		};
		Element* getPrev()
		{
			return prev;
		};
	};
	static Element* NIL = NULL;
	struct Object
	{
		Element* head;
		Object()
		{
			head = NIL;
		};
		Element* getFirst()
		{
			return head;
		};
		Element* getLast();
		Element* search(void* data);
		bool insert(void* data);
		bool deleteByElement(Element* e);
		bool deleteByData(void* data);
		void scan();
	};
	Object create();
}
#undef LISTNIL 
