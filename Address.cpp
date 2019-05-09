#pragma once
#include "Address.h"
//MODIFICADO
Address::Address()
{
	street = "";
	doorNumber = 0;
	floor = ""; // NOTA: o prof indicou: "floor number ("-" is not applicable)"
	zipCode = "";
	location = "";
}

Address::Address(string line)
{
    vector<string> addres_vec;
    tokenize(line, '/', addres_vec);
    for (int i = 0; i < addres_vec.size(); i++)
    {
        if (i == 0)
        {
            this->street = addres_vec.at(0);
        }
        else if (i == 1)
        {
            istringstream teste(addres_vec.at(1));
            teste >> this->doorNumber;
        }
        else if (i == 2)
        {
            this->floor = addres_vec.at(2);
        }
        else if (i == 3)
        {
            this->zipCode = addres_vec.at(3);
        }
        else if (i == 4)
        {
            this->location = addres_vec.at(4);
        }
    }
}
//MODIFICO
Address::Address(string street, int doorNumber, string floor, string zipCode, string location) : street(street), doorNumber(doorNumber), floor(floor), zipCode(zipCode), location(location)
{
	this->street = street;
	this->doorNumber = doorNumber;
	this->floor = floor; // NOTA: o prof indicou: "floor number ("-" is not applicable)"
	this->zipCode = zipCode;
	this->location = location;
}

// metodos GET

string Address::getStreet() const
{
    return street;
}

int Address::getDoorNumber() const
{

    return doorNumber;
}

string Address::getFloor() const
{

    return floor;
}

string Address::getZipCode() const
{

    return zipCode;
}

string Address::getLocation() const
{

    return location;
}

// metodos SET

void Address::setStreet(string street)
{

    this->street = street;
}

void Address::setDoorNumber(int doorNumber)
{

    this->doorNumber = doorNumber;
}

void Address::setFloor(string floor)
{

    this->floor = floor;
}

void Address::setZipCode(string postalCode)
{
    this->zipCode = zipCode;
}

void Address::setLocation(string location)
{

    this->location = location;
}

//other functions
//function that process my addresses removing the '/', making a plan line with spaces, so i can use it with my stringstream

//fill a string vector with informations separated by a certain delimiter
void Address::tokenize(string const &str, const char delim, vector<string> &out)
{
    stringstream ss(str);
    string s;
    while (getline(ss, s, delim))
    {
        out.push_back(s);
    }
}

/*********************************
 * Mostrar Address
 ********************************/




//-----------------------------------------------------------------------------------------
//devolve a address em string para ser apresentada nos clientes
string Address::getAddressString() const
{
	string street = getStreet();   
	int doorNumber = getDoorNumber(); 
	string floor = getFloor();    
	string zipCode = getZipCode(); 
	string location = getLocation(); 

	string oneLine = street + " / " + to_string(doorNumber) + " / " + floor + " / " + zipCode + " / " + location;

	return oneLine;
}
// As duas funções seguintes escrevem a Morada no return de maneira compacta (PARA APRESENTAR NO ECRA)
// displayes an address in a nice format
ostream &operator<<(ostream &out, const Address &address)
{
	out << "Rua: " << address.getStreet << endl;
	out << "Nº porta/prédio: " << address.getDoorNumber << endl;
	out << "Andar: " << address.getFloor << endl;
	out << "Código postal: " << address.getZipCode << endl;
	out << "Localidade: " << address.getLocation << endl;
	return out;
}

string :return_addres(Address endereco) {
	stringstream ss;
	string address_output;
	ss << "Rua: " << endereco.getStreet << endl;
	ss << "Nº porta/prédio: " << endereco.getDoorNumber << endl;
	ss << "Andar: " << endereco.getFloor << endl;
	ss << "Código postal: " << endereco.getZipCode << endl;
	ss << "Localidade: " << endereco.getLocation << endl;
	address_output = ss.str();

	return address_output;
}


