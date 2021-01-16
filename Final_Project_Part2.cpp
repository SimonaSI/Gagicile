#include<iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;


class identificare
{
private:
	string comanda;
public:
	identificare()
	{
		comanda = "no";

	}
	identificare(string comanda)
	{

		this->comanda = comanda;

	}

	string getcomanda()
	{
		return comanda;
	}

	void setcomanda(string comanda)
	{

		this->comanda = comanda;

	}

	explicit operator string()
	{
		return comanda;
	}

	bool operator!()
	{
		return comanda > "";
	}

	bool operator<(const identificare& i)
	{
		if (comanda < i.comanda)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const identificare& i)
	{
		return *this != i;
	}



	friend istream& operator>>(istream&, identificare&);
	friend ostream& operator<<(ostream&, identificare);


};

istream& operator>>(istream& in, identificare& i)
{
	cout << "Comanda dorita este create/drop/display?" << endl;
	in >> i.comanda;
	if (i.comanda == "create" or i.comanda == "drop" or i.comanda == "display")
	{
		return in;
	}
	else
	{
		cout << "Comanda invalida" << endl;
	}

}

ostream& operator<<(ostream& out, identificare i)
{
	out << "Comanda: " << i.comanda;
	return out;
}

class create_table
{
private:
	string denumire;
	int nr_atribute;
	string* tip;
	string* atribut;
	int* dimensiune;
	string* valori_imp;
public:


	create_table()
	{
		denumire = "Noname";
		nr_atribute = 1;
		atribut = nullptr;
		tip = nullptr;
		dimensiune = nullptr;
		valori_imp = nullptr;

	}
	create_table(int nr_atribute, string* atribut)
	{

		if (atribut != nullptr && nr_atribute > 0)
		{
			this->nr_atribute = nr_atribute;
			this->atribut = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				this->atribut[i] = atribut[i];
			}
		}
		else
		{
			nr_atribute = 0;
			atribut = nullptr;


		}

	}
	create_table(string denumire, int nr_atribute, string* atribut, string* tip, int* dimensiune, string* valori_imp)
	{
		this->denumire = denumire;
		if (atribut != nullptr && nr_atribute > 0 && dimensiune != nullptr && valori_imp != nullptr)
		{
			this->nr_atribute = nr_atribute;
			this->atribut = new string[nr_atribute];
			this->tip = new string[nr_atribute];
			this->dimensiune = new int[nr_atribute];
			this->valori_imp = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				this->atribut[i] = atribut[i];
				this->tip[i] = tip[i];
				this->dimensiune[i] = dimensiune[i];
				this->valori_imp[i] = valori_imp[i];
			}
		}
		else
		{
			this->nr_atribute = 0;
			this->atribut = nullptr;
			this->tip = nullptr;
			this->dimensiune = nullptr;
			this->valori_imp = nullptr;
		}


	}
	create_table(const create_table& t)
	{
		this->denumire = t.denumire;
		if (t.atribut != nullptr && t.nr_atribute > 0 && t.tip != nullptr && t.dimensiune != nullptr && t.valori_imp != nullptr)
		{
			this->nr_atribute = t.nr_atribute;
			this->atribut = new string[t.nr_atribute];
			this->tip = new string[t.nr_atribute];
			this->dimensiune = new int[t.nr_atribute];
			this->valori_imp = new string[t.nr_atribute];
			for (int i = 0; i < t.nr_atribute; i++)
			{
				this->atribut[i] = t.atribut[i];
				this->tip[i] = t.tip[i];
				this->dimensiune[i] = t.dimensiune[i];
				this->valori_imp[i] = t.valori_imp[i];
			}
		}
		else
		{
			this->atribut = nullptr;
			this->nr_atribute = 0;
			this->tip = nullptr;
			this->dimensiune = nullptr;
			this->valori_imp = nullptr;
		}
	}

	create_table& operator=(const create_table& t)
	{
		if (atribut != nullptr)
		{
			delete[] atribut;
		}
		if (tip != nullptr)
		{
			delete[] tip;
		}
		if (dimensiune != nullptr)
		{
			delete[] dimensiune;
		}
		if (valori_imp != nullptr)
		{
			delete[] valori_imp;
		}
		this->denumire = t.denumire;
		if (t.atribut != nullptr && t.nr_atribute > 0 && t.tip != nullptr && t.dimensiune != nullptr && t.valori_imp != nullptr)
		{
			this->nr_atribute = t.nr_atribute;
			this->atribut = new string[t.nr_atribute];
			this->tip = new string[t.nr_atribute];
			this->dimensiune = new int[t.nr_atribute];
			this->valori_imp = new string[t.nr_atribute];
			for (int i = 0; i < t.nr_atribute; i++)
			{
				this->atribut[i] = t.atribut[i];
				this->tip[i] = t.tip[i];
				this->dimensiune[i] = t.dimensiune[i];
				this->valori_imp[i] = t.valori_imp[i];
			}
		}
		else
		{
			this->atribut = nullptr;
			this->nr_atribute = 0;
			this->tip = nullptr;
			this->dimensiune = nullptr;
			this->valori_imp = nullptr;
		}
		return *this;
	}

	int getnr_atribute()
	{

		return nr_atribute;

	}

	string getdenumire()
	{
		return denumire;

	}

	string* gettip()
	{
		if (tip != nullptr)
		{
			string* copie = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				copie[i] = tip[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	int* getdimensiune()
	{
		if (dimensiune != nullptr)
		{
			int* copie = new int[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				copie[i] = dimensiune[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	string* getatribut()
	{
		if (atribut != nullptr)
		{
			string* copie = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				copie[i] = atribut[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	string* getvalori_imp()
	{
		if (valori_imp != nullptr)
		{
			string* copie = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				copie[i] = valori_imp[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	void setnr_atribute(int nr_atribute)
	{
		if (nr_atribute > 0)
		{
			this->nr_atribute = nr_atribute;
		}
	}

	void setdenumire(string denumire)
	{
		if (denumire != " ")
		{
			this->denumire = denumire;
		}
	}

	void settip(string* tip, int nr_atribute)
	{
		if (tip != nullptr && nr_atribute > 0)
		{
			this->nr_atribute = nr_atribute;
			if (this->tip != nullptr)
			{
				delete[] this->tip;
			}
			this->tip = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				this->tip[i] = tip[i];
			}
		}
	}
	void setdimensiune(int* dimensiune, int nr_atribute)
	{
		if (dimensiune != nullptr && nr_atribute > 0)
		{
			this->nr_atribute = nr_atribute;
			if (this->dimensiune != nullptr)
			{
				delete[] this->dimensiune;
			}
			this->dimensiune = new int[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				this->dimensiune[i] = dimensiune[i];
			}
		}
	}
	void setatribut(string* atribut, int nr_atribute)
	{
		if (atribut != nullptr && nr_atribute > 0)
		{
			this->nr_atribute = nr_atribute;
			if (this->atribut != nullptr)
			{
				delete[] this->atribut;
			}
			this->atribut = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				this->atribut[i] = atribut[i];
			}
		}
	}
	void setvalori_imp(string* valori_imp, int nr_atribute)
	{
		if (valori_imp != nullptr && nr_atribute > 0)
		{
			this->nr_atribute = nr_atribute;
			if (this->valori_imp != nullptr)
			{
				delete[] this->valori_imp;
			}
			this->valori_imp = new string[nr_atribute];
			for (int i = 0; i < nr_atribute; i++)
			{
				this->valori_imp[i] = valori_imp[i];
			}
		}
	}

	int& operator[](int index)
	{

		if (index > 0 && index < nr_atribute)
		{
			return dimensiune[index];
		}

	}


	void adauga(string den, string* valori)
	{
		ofstream f(den, ios::binary | ios::app);
		for (int i = 0; i < nr_atribute; i++)
		{

			int length = valori[i].length();
			f.write((char*)&length, sizeof(length));
			f.write(valori[i].c_str(), length + 1);


		}
		f.close();



	}
	~create_table()
	{
		if (atribut != nullptr)
		{
			delete[] atribut;
		}
		if (tip != nullptr)
		{
			delete[] tip;
		}
		if (dimensiune != nullptr)
		{
			delete[] dimensiune;
		}
		if (valori_imp != nullptr)
		{
			delete[] valori_imp;
		}

	}
	friend istream& operator>>(istream&, create_table&);
	friend ostream& operator<<(ostream&, create_table);


	create_table operator++(int i)
	{
		create_table copie = *this;
		this->nr_atribute++;
		return copie;
	}

	create_table operator++()
	{
		this->nr_atribute++;
		return *this;
	}

	operator int()
	{
		return nr_atribute;
	}

	explicit operator string()
	{
		return denumire;
	}

	bool operator!()
	{
		return nr_atribute > 0;
	}

	bool operator <(const create_table& t) {
		if (denumire < t.denumire)
		{
			return true;
		}

		return false;
	}

	bool operator==(const create_table& t1)
	{
		return *this == t1;
	}



	create_table operator+(int valoare)
	{

		create_table copie = *this;
		copie.nr_atribute += valoare;
		return copie;


	}

	friend ofstream& operator<<(ofstream&, create_table);
	friend ifstream& operator>>(ifstream&, create_table&);

};

class randuri
{
private:
	string* valori;
	int nr_col;
public:
	randuri()
	{
		valori = nullptr;
		nr_col = 0;
	}
	randuri(string* valori, int nr_col)
	{

		if (valori != nullptr && nr_col > 0)
		{
			this->nr_col = nr_col;
			this->valori = new string[nr_col];
			for (int i = 0; i < nr_col; i++)
			{
				this->valori[i] = valori[i];
			}
		}
		else
		{
			this->nr_col = 0;
			this->valori = nullptr;

		}
	}

	randuri(const randuri& r)
	{
		if (r.valori != nullptr && r.nr_col > 0)
		{
			this->nr_col = r.nr_col;
			this->valori = new string[r.nr_col];
			for (int i = 0; i < r.nr_col; i++)
			{
				this->valori[i] = r.valori[i];
			}
		}
		else
		{
			this->nr_col = 0;
			this->valori = nullptr;

		}
	}

	randuri operator=(const randuri& r)
	{

		if (valori != nullptr)
		{
			delete[] valori;
		}

		if (r.valori != nullptr && r.nr_col > 0)
		{
			this->nr_col = r.nr_col;
			this->valori = new string[r.nr_col];
			for (int i = 0; i < r.nr_col; i++)
			{
				this->valori[i] = r.valori[i];
			}
		}
		else
		{
			this->nr_col = 0;
			this->valori = nullptr;

		}
	}

	string* getvalori()
	{
		if (valori != nullptr)
		{
			string* copie = new string[nr_col];
			for (int i = 0; i < nr_col; i++)
			{
				copie[i] = valori[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	int getnr_col()
	{
		return nr_col;
	}
	~randuri()
	{
		if (valori != nullptr)
		{
			delete[] valori;
		}
	}
	void serializare( string fisier)
	{
		ofstream f(fisier, ios::binary| ios::app);
		for (int i = 0; i < nr_col; i++)
		{
			int length = valori[i].length() + 1;
			f.write((char*)&length, sizeof(int));
			f.write(valori[i].c_str(), length);
		}
		f.close();
	}


	friend istream& operator>>(istream&, randuri&);
	friend ostream& operator<<(ostream&, randuri);
};

istream& operator>>(istream& in, randuri& r)
{

	cout << "Numarul de valori: ";
	in >> r.nr_col;
	if (r.valori != nullptr)
	{
		delete[] r.valori;
	}

	if (r.nr_col > 0)
	{
		r.valori = new string[r.nr_col + 1];

		for (int i = 0; i < r.nr_col; i++)
		{
			cout << "valoarea " << i + 1 << " ";
			in >> r.valori[i];


		}

	}
	else
	{
		r.nr_col = 0;
		r.valori = nullptr;

	}
	return in;
}

ostream& operator<<(ostream& out, randuri r)
{

	out << "Numar de valori: " << r.nr_col << endl;
	for (int i = 0; i < r.nr_col; i++)
	{
		out << "Valoarea" << i + 1 << " " << r.valori[i] << endl;

	}
	return out;
}

ofstream& operator<<(ofstream& g, create_table t)
{
	if (g.is_open())
	{
		g << t.denumire << endl;
		g << t.nr_atribute << endl;
		if (t.atribut != nullptr && t.tip != nullptr && t.dimensiune != nullptr && t.valori_imp != nullptr)
		{
			for (int i = 0; i < t.nr_atribute; i++)
			{
				g << t.atribut[i] << " ";
				g << t.tip[i] << " ";
				g << t.dimensiune[i] << " ";
				g << t.valori_imp[i] << " ";
				g << endl;
			}
		}
	}
	return g;
}

ifstream& operator>>(ifstream& in, create_table& t)
{
	if (in.is_open())
	{
		cout << "Denumire tabelei: " << endl;
		getline(in, t.denumire);
		cout << "Numar de atribute: " << endl;
		in >> t.nr_atribute;
		if (t.atribut != nullptr)
		{
			delete[] t.atribut;
		}
		if (t.tip != nullptr)
		{
			delete[] t.tip;
		}
		if (t.dimensiune != nullptr)
		{
			delete[] t.dimensiune;
		}
		if (t.valori_imp != nullptr)
		{
			delete[] t.valori_imp;
		}
		if (t.nr_atribute > 0)
		{
			t.atribut = new string[t.nr_atribute + 1];
			t.tip = new string[t.nr_atribute + 1];
			t.dimensiune = new int[t.nr_atribute + 1];
			t.valori_imp = new string[t.nr_atribute + 1];
			for (int i = 0; i < t.nr_atribute; i++)
			{
				in >> ws;
				cout << "atributul " << i + 1 << " ";
				getline(in, t.atribut[i]);
				in >> ws;
				cout << endl << "tipul atributului este ";
				getline(in, t.tip[i]);

				cout << endl << "dimesiunea atributului  este ";
				in >> t.dimensiune[i];
				in >> ws;
				cout << endl << "valoarea implicita  este ";
				getline(in, t.valori_imp[i]);
				cout << endl;
			}

		}
		else
		{
			t.nr_atribute = 0;
			t.atribut = nullptr;
			t.tip = nullptr;
			t.dimensiune = nullptr;
			t.valori_imp = nullptr;
		}
	}
	return in;

}


create_table operator+(int valoare, create_table tr)
{
	int x = tr.getnr_atribute();
	x += valoare;
	return tr;
}
istream& operator>>(istream& in, create_table& t)
{


	cout << "Denumire tabelei: ";
	in >> t.denumire;
	cout << "Numar de atribute: ";
	in >> t.nr_atribute;
	if (t.atribut != nullptr)
	{
		delete[] t.atribut;
	}
	if (t.tip != nullptr)
	{
		delete[] t.tip;
	}
	if (t.dimensiune != nullptr)
	{
		delete[] t.dimensiune;
	}
	if (t.valori_imp != nullptr)
	{
		delete[] t.valori_imp;
	}
	if (t.nr_atribute > 0)
	{
		t.atribut = new string[t.nr_atribute + 1];
		t.tip = new string[t.nr_atribute + 1];
		t.dimensiune = new int[t.nr_atribute + 1];
		t.valori_imp = new string[t.nr_atribute + 1];
		for (int i = 0; i < t.nr_atribute; i++)
		{
			cout << "atributul " << i + 1 << " ";
			in >> t.atribut[i];
			cout << "tipul atributului " << t.atribut[i] << " este ";
			in >> t.tip[i];
			cout << "dimesiunea atributului " << t.atribut[i] << " este ";
			in >> t.dimensiune[i];
			cout << "valoarea implicita " << t.atribut[i] << " este ";
			in >> t.valori_imp[i];

		}

	}
	else
	{
		t.nr_atribute = 0;
		t.atribut = nullptr;
		t.tip = nullptr;
		t.dimensiune = nullptr;
		t.valori_imp = nullptr;
	}
	return in;
}

ostream& operator<<(ostream& out, create_table t)
{
	out << "Denumirea tabelei: " << t.denumire << endl;
	out << "Numar de atribute: " << t.nr_atribute << endl;
	for (int i = 0; i < t.nr_atribute; i++)
	{
		out << "Nume atribut " << i + 1 << " " << t.atribut[i] << endl;
		out << "Tipul atributului " << t.atribut[i] << " este " << t.tip[i] << endl;
		out << "Dimensiunea atributului " << t.atribut[i] << " este " << t.dimensiune[i] << endl;
		out << "Valoarea implicita a atributului " << t.atribut[i] << " este " << t.valori_imp[i] << endl;
	}
	return out;
}

int pozitie( int nr,string n, string* s)
{
	int i=0, ok=0;
	while (i < nr && ok == 0)
	{
		if (s[i] == n)
		{
			ok = 1;
		}
		i++;
	}
	i--;
	return i;

}

int main()
{
	create_table ta[100];
	int k = 0;
	char optiune;
	do
	{
		cout << endl << endl << "                                   MENIU       " << endl;
		cout << "                    1 - CREATE TABLE" << endl;
		cout << "                    2 - DROP TABLE" << endl;
		cout << "                    3 - DISPLAY TABLE" << endl;
		cout << "                    4 - INSERT" << endl;
		cout << "                    5 - UPDATE" << endl;
		cout << "                    6 - DELETE" << endl;
		cout << "                    7 - SELECT" << endl;
		cout << "                    x - iesire" << endl;
		cout << "Introduceti comanda: ";
		cin >> optiune;

		switch (optiune)
		{
			case '1': 
			{
				create_table t;
				cin >> t;
				ta[k] = t;
				k++;
				ofstream g;
				string num;
				num = t.getdenumire();
				g.open(num);
				g << t;
				g.close();
				cout << "Tabela a fost creata cu succes!";
			}
			break;
			case '2':
			{
				string nume;
				cout << "DROP TABLE ";
				cin >> nume;
				remove(nume.c_str());
				cout << "Tabela " << nume << " a fost stearsa cu succes.";
			}
			break;
			case '3': 
			{
				cout << "DISPLAY ";
				string nume;
				cin >> nume;
				for (int i = 0; i < k; i++)
				{
					if (ta[i].getdenumire() == nume)
					{
						cout << ta[i];
					}
					else
					{
						cout << "Tabela nu exista!";
					}
				}
			}
			break;
			case '4':
			{
				string num;
				int nr;
				cout << "INSERT INTO   ";
				cin >> num;
				for (int i = 0; i < k; i++)
				{
					if (ta[i].getdenumire() == num)
					{
						string* p;
						p = new string[ta[i].getnr_atribute()];
						cout << "VALUES ";
						for (int g = 0; g < ta[i].getnr_atribute(); g++)
						{
							cin >> p[g];
						}
						nr = ta[i].getnr_atribute();
						randuri ra(p, nr);
						ra.serializare(num + '1');
						cout << "O inregistrare inserata cu succes!" << endl;			
						delete[] p;
					}		
				}				
			}
			break;
			case '5': 
			{
				string c, n, v, val;
				cout << "UPDATE ";
				cin >> c;
				cout << "SET ";
				cin >> n;
				cout << " = ";
				cin >> v;
				cout << "WHERE "<<n<<" = ";
				cin >> val;
				int ok;
				string c1 = c + '1';
				ifstream f(c1, ios::binary);
				ofstream g("temp.bin", ios::binary | ios::trunc);
				for (int i = 0; i < k; i++)
				{
					if (ta[i].getdenumire() == c)
					{
						string* s = ta[i].getatribut();
						int p = pozitie(ta[i].getnr_atribute(), n, s); //set
						while (!f.eof())
						{
							for (int k2 = 0; k2 < ta[i].getnr_atribute(); k2++)
							{
								int length = 0;
								f.read((char*)&length, sizeof(int));
								char* temp = new char[length];
								f.read(temp, length);
								if (temp == val && k2 == p)
								{
									g.write((char*)&v, sizeof(v));
								}
								else
								{
									g.write((char*)&temp, sizeof(temp));
								}
								delete[] temp;
							}
						}
						delete[] s;				
					}
				}
				f.close();
				g.close();
				remove(c1.c_str());
				rename("temp.bin", c1.c_str());
				cout << "Inregistrarea s-a modificat cu succes! ";
			}			
			break;
			case '6':
			{
				string c;
				cout << "DELETE FROM ";
				cin >> c;
				cout << "WHERE ";
				string n, v;
				cin >> n;
				cout << " = ";
				cin >> v;
				int ok = 0;
				string c1 = c + '1';
				ifstream f(c1, ios::binary);
				ofstream g("temp.bin", ios::binary | ios::trunc);
				for (int i = 0; i < k; i++)
				{
					if (ta[i].getdenumire() == c)
					{
						string* s = ta[i].getatribut();
						int p = pozitie(ta[i].getnr_atribute(), n, s);
						string* vl;
						vl = new string[ta[i].getnr_atribute() + 1];
						while (!f.eof())
						{
							int ok1 = 1;
							int k1 = 0;
							for (int k2 = 0; k2 < ta[i].getnr_atribute(); k2++)
							{
								int length = 0;
								f.read((char*)&length, sizeof(int));
								char* temp = new char[length];
								f.read(temp, length);
								vl[k1] = temp;
								k1++;
								if (temp == v && k2 == p)
								{
									ok1 = 0;
								}
							}
							if (ok1 == 1)
							{
								for (int t = 0; t < ta[i].getnr_atribute(); t++)
								{
									g.write((char*)&vl[t], sizeof(vl[t]));
								}
							}
						}
						delete[] s;
						delete[] vl;
					}
				}
				f.close();
				g.close();
				remove(c1.c_str());
				rename("temp.bin", c1.c_str());
				cout << "Inregistrarea a fost stearsa cu succes!";
			}
			break;
			case '7': 
			{
				cout << "Se introduc coloane pana la intalnirea tastei 0! "<<endl;
				string c,n;
				cout << "SELECT ";
				int k1 = 0;
				string* v;
				v = new string[100000];
				while (cin >> n && n!="0")
				{
					v[k1] = n;
					k1++;
				}
				cout << "FROM ";
				cin >> c;
				string c1 = "SELECT " + c;
				ifstream f(c + '1', ios::binary);
				ofstream g(c1, ios::binary | ios::trunc);
				int* p = new int[1000000];
				for (int i = 0; i < k; i++)
				{
					if (ta[i].getdenumire() == c)
					{
						string* s = ta[i].getatribut();
						for (int j = 0; j < k1; j++)
						{
							p[j] = pozitie(ta[i].getnr_atribute(), v[j], s);
						}
						while (!f.eof())
						{
							for (int m = 0; m < ta[i].getnr_atribute(); m++)
							{
								int length = 0;
								f.read((char*)&length, sizeof(int));
								char* temp = new char[length];
								f.read(temp, length);
								for (int n = 0; n < k1; n++)
								{
									if (m == p[n])
									{
										g.write((char*)&temp, sizeof(temp));
									}									
								}
							}
						}
						delete[] s;
					}			
				}
				f.close();
				g.close();
				delete[] v;
				cout << "Selectia a fost realizata cu succes!";
			}
			break;
			case 'x': exit(1); 
			default: cout << "Optiune incorecta!";
		}
	} while (optiune != 'x');
}