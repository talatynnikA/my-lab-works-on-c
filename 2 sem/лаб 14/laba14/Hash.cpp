#include "Hash.h"
#include <cstring>
#include <iostream>

using namespace std;
int HashFunction(int key, int size, int p)
{
	double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
	return (int)((double)p + key2) % size;
}

int Next_hash(int hash, int size, int p)
{
	return (hash % size + p * (1 + hash % size)) % size;
}

inline int mod_hash(int hash, int size, int p)
{
	return (hash + p) % size;
}

inline int univ_hash(int key, int size, int p)
{
	return (key % 2 ? HashFunction(key, size, p) : Next_hash(key, size, p));
}

// Additive hashing
int addit_hash(char *key, int size, int p)
{
	int s = 0;
	ushort length = strlen(key);
	for (size_t i = 0; i < length; i++)
		s += key[i];
	return (s + p) % size;
}

Object create(int size, int (*getkey)(void *), char *(*getStr)(void *), Hashing h)
{
	return *(new Object(size, getkey, getStr, h));
}

Object::Object(int size, int (*getkey)(void *), char *(*getstr)(void *), Hashing h)
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->getStr = getstr;
	this->hash = h;
	this->data = new void *[size];
	for (int i = 0; i < size; i++)
		data[i] = NULL;
}

Object Object::chSize(int newSize)
{
	Object g = create(newSize, getKey, getStr, hash);
	for (size_t i = 0; i < size; i++)
		if (data[i])
		{
			g.data[i] = data[i];
			g.N++;
		}
	return g;
}

bool Object::insert(void *d)
{
	bool b = false;
	if (N != size)
		switch (hash)
		{
		case DEF:
			for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0); i != size && !b; j = Next_hash(j, size, ++i))
				if (!data[j])
				{
					data[j] = d;
					N++;
					b = true;
				}
			break;
		case UNIV:
			for (int i = 0, t = getKey(d), j = univ_hash(t, size, 0); i != size && !b; j = univ_hash(t, size, ++i))
				if (!data[j])
				{
					data[j] = d;
					N++;
					b = true;
				}
			break;
		case MOD:
			for (int i = 0, t = getKey(d), j = mod_hash(t, size, 0); i != size && !b; j = mod_hash(t, size, ++i))
				if (!data[j])
				{
					data[j] = d;
					N++;
					b = true;
				}
			break;
		case ADDIT:
			char *t = getStr(d);
			for (int i = 0, j = addit_hash(t, size, 0); i != size && !b; j = addit_hash(t, size, ++i))
				if (!data[j])
				{
					data[j] = d;
					N++;
					b = true;
				}
			break;
		}
	return b;
}

int Object::searchHash(HashKey key1)
{
	int t = -1;
	bool b = false;
	int key = key1.num;
	char *str = key1.str;
	if (N != 0)
		switch (hash)
		{
		case DEF:
			for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = Next_hash(j, size, ++i))
				if (data[j] != NULL)
					if (getKey(data[j]) == key)
					{
						t = j;
						b = true;
					}
			break;
		case UNIV:
			for (int i = 0, j = univ_hash(key, size, 0); data[j] != NULL && i != size && !b; j = univ_hash(key, size, ++i))
				if (data[j] != NULL)
					if (getKey(data[j]) == key)
					{
						t = j;
						b = true;
					}
			break;
		case MOD:
			for (int i = 0, j = mod_hash(key, size, 0); data[j] != NULL && i != size && !b; j = mod_hash(key, size, ++i))
				if (data[j] != NULL)
					if (getKey(data[j]) == key)
					{
						t = j;
						b = true;
					}
			break;
		case ADDIT:
			for (int i = 0, j = addit_hash(str, size, 0); data[j] != NULL && i != size && !b; j = addit_hash(str, size, ++i))
				if (data[j] != NULL)
					if (!strcmp(getStr(data[j]), str))
					{
						t = j;
						b = true;
					}
			break;
		}
	return t;
}

void *Object::search(HashKey key)
{
	int t = -1;
	t = searchHash(key);
	return (t >= 0) ? (data[t]) : (NULL);
}

void *Object::deleteByKey(HashKey key)
{
	int i = searchHash(key);
	void *t = data[i];
	if (t)
	{
		data[i] = NULL;
		N--;
	}
	return t;
}

// bool Object::deleteByValue(void *d)
// {
// 	if (hash == ADDIT)
// 	return delByChar(getStr(d));
// 	else
// 		return deleteByKey(getKey(d));
// }

void Object::scan(void (*f)(void *))
{
	std::cout << "Элементы таблицы (в формате значение [ключ]):\n";
	for (int i = 0; i < this->size; i++)
	{
		std::cout << i << ") ";
		if (!data[i])
			std::cout << "пуст.\n";
		else
			f(data[i]);
	}
}

Object Object::chMethod(Hashing newHash)
{
	Object g = create(size, getKey, getStr, newHash);
	g.N = N;
	for (size_t i = 0; i < size; i++)
		if (data[i])
			g.insert(data[i]);
	return g;
}
