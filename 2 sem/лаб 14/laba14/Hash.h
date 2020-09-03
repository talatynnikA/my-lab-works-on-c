#pragma once
enum Hashing
{
	DEF = 1, // Default
	UNIV,	 // Universal
	MOD,	 // Modular
	ADDIT	 // Addictive
};

union HashKey
{
	char *str;
	int num;
};

struct Object
{
	void **data;
	Hashing hash;
	Object(int, int (*)(void *), char *(*)(void *), Hashing);
	int size;
	int N;	// Number of elements in the table
	int (*getKey)(void *);
	char *(*getStr)(void *);
	bool insert(void *);
	int searchHash(HashKey key);
	void *search(HashKey key);
	void *deleteByKey(HashKey key);
	void scan(void (*f)(void *));
	Object chSize(int newSize);
	Object chMethod(Hashing newHash);
};
Object create(int size, int (*getkey)(void *), char *(*getStr)(void *), Hashing h);
