#pragma once
#include"c_Spravochnik.h"
#include<iostream>
#include<fstream>
#include<string>
struct Node
{
	Node* next;
	c_Spravochnik* val;
	Node(){}
	Node(c_Spravochnik* sp)
	{
		this->next = nullptr;
		this->val = sp;
	}
};
class Col_Spravochnik
{
	Node* head;
	int size;
public:
	Col_Spravochnik()
	{
		this->head = nullptr;
		this->size = 0;
	}
	void Add(c_Spravochnik* sp)
	{
		Node* tmp = this->head;
		if (tmp == nullptr)
		{
			tmp = new Node(sp);
			this->head = tmp;
			size++;
		}
		else
		{
			while (tmp->next!=nullptr)
			{
				tmp = tmp->next;
			}
			tmp->next = new Node(sp);
			size++;
		}
	}
	void  Shoow()
	{
		Node* iter = this->head;
		while (iter!=nullptr)
		{
			iter->val->print();
			iter = iter->next;
		}
	}
	void SerchByName(std::string name)
	{
		Node* iter = this->head;
		int f = 0;
		while (iter!=nullptr)
		{
			if (iter->val->getName() == name)
			{
				iter->val->print();
				f = 1;
			}
			iter = iter->next;
		}
		if (f == 0)
			std::cout << "Nothing found\n";
	}
	void SerchByNameFirm(std::string name_firm)
	{
		Node* iter = this->head;
		int f = 0;
		while (iter!=nullptr)
		{
			if (iter->val->getNameFirm() == name_firm)
			{
			  iter->val->print();
			  f = 1;
			}
			iter = iter->next;
		}
		if (f == 0)
			std::cout << "Nothing found\n";
	}
	void SerchByNumber(std::string number)
	{
		Node* iter = this->head;
		int f = 0;
		while (iter != nullptr)
		{
			if (iter->val->getNumber() == number)
			{
				iter->val->print();
				f = 1;
			}
			iter = iter->next;
		}
		if (f == 0)
			std::cout << "Nothing found\n";
	}
	void SerchByOccupation(std::string occupation)
	{
		Node* iter = this->head;
		int f = 0;
		while (iter != nullptr)
		{
			if (iter->val->getOccupation() == occupation)
			{
				iter->val->print();
				f = 1;
			}
			iter = iter->next;
		}
		if (f == 0)
			std::cout << "Nothing found\n";
	}
	void Writh()
	{
		Node* iter = this->head;
		std::fstream f;
		f.clear();
		f.open("File.txt", std::ios::out);
		f << this->size;
		while (iter!=nullptr)
		{
			f << iter->val->getNameFirm()<<":" << iter->val->getName() << ":" << iter->val->getNumber() << ":"
			<< iter->val->getAddress() << ":" << iter->val->getOccupation() << "\n";
			iter = iter->next;
		}
		f.close();
	}
	void Dell(std::string name_f)
	{
		Node* iter = this->head;
		if (iter->val->getNameFirm() == name_f)
		{
			this->head = this->head->next;
			size--;
		}
		else
		{
			while (iter->next != nullptr)
			{
				if (iter->next->next == nullptr && iter->next->val->getNameFirm() == name_f)
				{
					iter->next = nullptr;
					size--;
					break;
				}
				else if (iter->next->val->getNameFirm() == name_f)
				{
					iter->next = iter->next->next;
					size--;
					break;
				}
				iter = iter->next;
			}
		}
		this->Writh();
	}
	void Reading()
	{
		int s;
		Node* tmp = this->head;
		c_Spravochnik* sp;
		std::fstream f;
		f.open("File.txt", std::ios::in);
		f >> s;
		for (int i = 0; i < s; i++)
		{
			std::string n_k = "";
			std::string name = "";
			std::string number = "";
			std::string address = "";
			std::string all = "";
			f >> name;
			f >> n_k;
			f >> number;
			f >> all;
			f >> address;
			sp = new c_Spravochnik(n_k,name,number,address,all);
			this->Add(sp);
		}
		f.close();
	}
	void read()
	{
		std::string str;
		std::fstream f;
		std::size_t pos = 0;
		std::string sep = ":";
		std::string name;
		std::string name_firm;
		std::string number;
		std::string rod_d;
		std::string address;
		c_Spravochnik* sp;
		f.open("File.txt", std::ios::in);
		int n;
		f >> n;
		std::cout << n << "\n";
		for (int i = 0; i < n; i++)
		{
			std::getline(f, str);
			while ((pos = str.find(sep)) != std::string::npos)
			{
				name = str.substr(0, pos);
				str.erase(0, pos + sep.length());
				pos = str.find(sep);
				name_firm = str.substr(0, pos);
				str.erase(0, pos + sep.length());
				pos = str.find(sep);
				number = str.substr(0, pos);
				str.erase(0, pos + sep.length());
				pos = str.find(sep);
				rod_d = str.substr(0, pos);
				str.erase(0, pos + sep.length());
				pos = str.find(sep);
				address = str.substr(0, pos);
				str.erase(0, pos + sep.length());
				sp = new c_Spravochnik(name_firm, name, number, address, rod_d);
				this->Add(sp);
			}
		}
		f.close();
	}
};

