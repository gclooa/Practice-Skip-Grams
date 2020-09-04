// Guan Ce Looa
// CS 301 Summer 2020
// Assignment 3: N-skip-M-grams

#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// A word as a linked list node
class Word
{
public:
	string data;
	Word* next;
	Word(string word);
};

// Node constructor for words
Word::Word(string word)
{
	data = word;
	next = nullptr;
}

// A sentence as a linked list made of words
class Sentence
{
private:
	Word* head;
	int size;
public:
	Sentence(string line);
	~Sentence();
	string getWord(int index);
	int getLength();
};

Sentence::Sentence(string line)
{
	if (line.length() == 0)
	{
		head = nullptr;
		size = 0;
	}
	else
	{
		// Object stringstream splits sentence into words
		string word;
		stringstream get(line);
		get >> word;
		// Initialize first word of sentence
		head = new Word(word);
		size = 1;
		// Append subsequent words, creating a sentence where each word is a linked list node
		Word* ptr = head;
		while (get >> word) {
			ptr->next = new Word(word);
			ptr = ptr->next;
			size++;
		}
	}
}

Sentence::~Sentence()
{
	Word* ptr = head;
	while (head != nullptr)
	{
		head = head->next;
		delete ptr;
		ptr = head;
	}
	delete ptr;
}

string Sentence::getWord(int index)
{
	if (index >= size)
	{
		return "";
	}
	else
	{
		Word* ptr = head;
		for (int i = 0; i < index; i++)
		{
			ptr = ptr->next;
		}
		return ptr->data;
	}
}

int Sentence::getLength()
{
	return size;
}
