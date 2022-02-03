#pragma once
#include<iostream>
class c_Spravochnik
{
	std::string name_firm;
	std::string name;
	std::string t_number;
	std::string address;
	std::string rod_d;
public:
	c_Spravochnik()
	{
		this->address = nullptr;
		this->name = nullptr;
		this->name_firm = nullptr;
		this->rod_d = nullptr;
		this->t_number = nullptr;
	}
	c_Spravochnik(std::string name_firm, std::string name, std::string t_number, std::string address, std::string rod_d)
	{
		this->address = address;
		this->name = name;
		this->name_firm = name_firm;
		this->rod_d = rod_d;
		this->t_number = t_number;
	}
	void print()
	{
		std::cout << "Name Firm: "<<this->name_firm<<"\tDirector: "<<this->name<<"\tNumber: "<<this->t_number<<"\tAddress: "<<this->address<<"\tOccupation: "<<this->rod_d<<"\n";
	}
	std::string getName()
	{
		return (std::string)this->name;
	}
	std::string getNameFirm()
	{
		return (std::string)this->name_firm;
	}
	std::string getNumber()
	{
		return (std::string)this->t_number;
	}
	std::string getOccupation()
	{
		return (std::string)this->rod_d;
	}
	std::string getAddress()
	{
		return (std::string)this->address;
	}
};

