#pragma once
#include "Client.h"


Client::Client(vector<string> clients)
{
  this->name = clients.at(0);
  stringstream nif(clients.at(1));
  nif >> this->nif;
  stringstream famSize(clients.at(2));
  famSize >> this->familySize;
  Address address(clients.at(3));
  this->address = address;
  this->packets = clients.at(4);
  stringstream totPurch(clients.at(5));
  totPurch >> this->totalPurchased;
}

//MODIFICADO - NAO USADO
Client::Client(string name, unsigned nif, unsigned short familySize, Address address, string packets, unsigned totalPurchased) : name(name), nif(nif), familySize(familySize), address(address), packets(packets), totalPurchased(totalPurchased)
{
	
	this->name = name;
	this->VATnumber = VATnumber;
	this->familySize = familySize;
	this->address = address;
	//packets - inicialization = empty
	this->totalPurchased = 0;
}

Client::Client()
{
	Address aux();
	this->name = "";
	this->VATnumber = "";
	this->familySize = 0;
	this->address = aux ;
	this->packets = "";
	this->totalPurchased = 0;
}

// GET methods

string Client::getName() const
{
  return name;
}

unsigned Client::getNifNumber() const
{

  return nif;
}

unsigned short Client::getFamilySize() const
{

  return familySize;
}

Address Client::getAddress() const
{

  return address;
}

string Client::getPacketList() const
{

  return packets;
}

unsigned Client::getTotalPurchased() const
{

  return totalPurchased;
}

// metodos SET

void Client::setName(string name)
{

  this->name = name;
  ;
}

void Client::setNifNumber(unsigned nif)
{

  this->nif = nif;
}

void Client::setFamilySize(unsigned short familySize)
{

  this->familySize = familySize;
}
void Client::setAddress(Address address)
{
  this->address = address;
}
void Client::setPacketList(string packets)
{
  this->packets = packets;
}
unsigned Client::setTotalPurchased(unsigned totalPurchased)
{
  this->totalPurchased = totalPurchased;
}

// outros metodos

vector<Client> clientData(string clientFile)
{
  vector<Client> client_info;
  ifstream file;
  string lines;
  vector<string> client_temp;
  file.open(clientFile);
  while (getline(file, lines, '\n'))
  {
    if (lines == "::::::::::")
    {
      Client newClient(client_temp);
      client_info.push_back(newClient);
      client_temp.clear();
    }
    else
    {
      client_temp.push_back(lines);
    }
  }
  Client newClient(client_temp);
  client_info.push_back(newClient);
  file.close();
  return client_info;
}

//MODIFICADO
ostream &operator<<(ostream &out, const Client &client)
{
	out << "::::::::::" << endl;
	out << "Name: " << client.getName << endl;
	out << "NIF: " << client.getVATnumber << endl;
	out << "Family members: " << client.getFamilySize << endl;
	out << "----Address--- \n" << client.getAddress << endl;
	out << "Packages: " << client.getPacketList << endl;
	return out;
}

//creates a vector of packets id
void clients_packs(string line, vector<int> &aux)
{
  line = regex_replace(line, regex(";"), " ");
  istringstream test(line);
  int i;
  while (test >> i)
  {
    aux.push_back(i);
  }
}

//-------------------------------------------
//Add new client
vector<Client> add_client(vector<Client> &vec) {
	vector<string> new_client = clients_questions();
	Client aux(new_client);
	vec.push_back(aux);
	return vec;
}

//it will automate de clients_question job
vector<string> clientQuestionHandler(vector<string> vec) {
	string line;
	vector<string> new_client;
	cout << "::::::::::" << endl;
	cin.ignore();
	for (size_t i = 0; i < vec.size(); i++) {
		cout << vec.at(i);
		getline(cin, line);
		new_client.push_back(line);
	}
	cout << "::::::::::" << endl;
	return new_client;
}

//creates a new vector<string> with the data needed to create my new client
vector<string> clients_questions() {
	string line;
	vector<string> nClient_questions = { "Client name: ","NIF number: ","Nº family members: ","Address: ","Package list: " };
	cout << endl;
	vector<string> new_client = clientQuestionHandler(nClient_questions);
	return new_client;
}

//update/change the information of a client; (NOTA: Adicionei como função da class)
void Client::update_client(vector<Client> &vec) {
	print_all_clients(vec);
	int op;
	string line;
	string nif;
	cout << "What's the nif of the client you want to update? " << endl;
	cin >> nif;
	cin.ignore();
	vector<string> menu = { "Name","NIF","Family Number","Address","Package" };
	for (size_t i = 0; i < vec.size(); i++) {
		if (vec.at(i).getVATnumber == nif) {
			op = readOptions(menu);
			if (op == 1) {
				cout << "New Name: ";
				cin.ignore();
				getline(cin, line);
				vec.at(i).setName(line);
			}
			if (op == 2) {
				cout << "New NIF: ";
				cin.ignore();
				getline(cin, line);
				vec.at(i).setVATnumber(line);
			}
			if (op == 3) {
				cout << "New family number: ";
				cin.ignore();
				getline(cin, line);
				istringstream transform(line);
				vec.at(i).setFamilySize(transform);
			}
			if (op == 4) {
				cout << "New address: ";
				cin.ignore();
				getline(cin, line);
				vec.at(i)(line);
			}
			if (op == 5) {
				cout << "New package: ";
				cin.ignore();
				getline(cin, line);
				vec.at(i).setPacketList(line);
			}
		}
	}
}
//print a specifi client
void printClient(vector<Client> &vec) {
	cout << ":::::Please provide us with the client Name or NIF:::::";
	cout << "Wich information suits you?  ";
	vector<string> menu = { "Name","NIF" };
	int op = readOptions(menu);
	string line;
	if (op == 1) {
		cout << "Whats the name of the client?" << endl;
		cin.ignore();
		getline(cin, line);
		for (size_t i = 0; i < vec.size(); i++) {
			if (line == vec.at(i).getName()) {
				cout << "::::::::::" << endl;
				cout << "Name: " << vec.at(i).getName() << endl;
				cout << "NIF: " << vec.at(i).getVATnumber() << endl;
				cout << "Family members: " << vec.at(i).getFamilySize() << endl;
				cout << "----Address--- \n" << vec.at(i).getAddress();
				cout << "Packages: " << vec.at(i).getPacketList() << endl;
			}
		}
	}
	if (op == 2) {
		cin.ignore();
		cout << "Whats the NIF of the client?" << endl;
		getline(cin, line);
		for (size_t i = 0; i < vec.size(); i++) {
			if (line == vec.at(i).getVATnumber()) {
				cout << "::::::::::" << endl;
				cout << "Name: " << vec.at(i).getName() << endl;
				cout << "NIF: " << vec.at(i).getVATnumber() << endl;
				cout << "Family members: " << vec.at(i).getFamilySize() << endl;
				cout << "----Address--- \n" << vec.at(i).getAddress();
				cout << "Packages: " << vec.at(i).getPacketList() << endl;
			}
		}
	}
}

//Print all my clients.
void print_all_clients(vector<Client> &vec) {
	cout << ":::::The current clients in our database are:::::";
	for (size_t i = 0; i < vec.size(); i++) {
		cout << "::::::::::" << endl;
		cout << "Name: " << vec.at(i).getName() << endl;
		cout << "NIF: " << vec.at(i).getVATnumber() << endl;
		cout << "Family members: " << vec.at(i).getFamilySize() << endl;
		cout << "----Address--- \n" << vec.at(i).getAddress();
		cout << "Packages: " << vec.at(i).getPacketList() << endl;
	}
}

void makeCopy(string filename) {
	ifstream ifile;
	string line;
	vector<string> file;
	tokenize(filename, '.', file);

	ifile.open(filename);
	string outname = file.at(0) + "_copy.txt";
	ofstream ofile;
	ofile.open(outname);
	while (getline(ifile, line)) {
		ofile << line << endl;
	}
	//cout << "Ponto na posição : " << pos;
	ifile.close();
	ofile.close();
}

void writeClients(string file_name, vector<Client> &vec) {
	makeCopy(file_name);
	cout << "A copy of the previous file have been made in case of data lost!";
	ofstream file;
	file.open(file_name);
	if (file.is_open()) {
		for (size_t i = 0; i < vec.size(); i++) {
			file << vec.at(i).getName() << endl;
			file << vec.at(i).getVATnumber() << endl;
			file << vec.at(i).getFamilySize() << endl;
			file << vec.at(i).getAddress() << endl;
			file << vec.at(i).getPacketList() << endl;
			file << vec.at(i).getTotalPurchased() << endl;
			if (i < vec.size() - 1) {
				file << "::::::::::" << endl;
			}
		}
	}
	file.close();
}


