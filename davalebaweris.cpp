#include <iostream>
#include <fstream>
using namespace std;


/* kodis es nawili gansazghvravs or klass: Saxeli da Damsaqmebeli. damsakmebeli, saxelis warmoshobili klasia.
 Saxelis, klass aqvs ramdenime daculi cvladi da konstruqtori tavisi nagulisxmevi mnishvnelobebit.
*/
class Saxeli {
	
protected:
	
	unsigned int nomeri;
	string saxeli;
	string gvari;
	unsigned int dabweli;
	unsigned int sqesi;
	void set(unsigned int nomeri, string saxeli, string gvari, unsigned int dabweli, unsigned int sqesi) {
		
		this->nomeri = nomeri; this->saxeli = saxeli; this->gvari = gvari; 
		this->dabweli = dabweli; this->sqesi = sqesi;
	}
public:
	
	Saxeli() {
		set(0, "saxeli", "gvari", 0, 0);
	}
	Saxeli(unsigned int nomeri, string saxeli, string gvari, unsigned int dabweli, unsigned int sqesi) {
		set(nomeri, saxeli, gvari, dabweli, sqesi);
	}
	string getSaxeli() {
		return saxeli;
	}
	string getGvari() {
		return gvari;
	}
	unsigned int getNomeri() {
		return nomeri;
	}
	unsigned int getSqesi() {
		return sqesi;
	}
	unsigned int getDabweli() {
		return dabweli;
	}
};

class Damsaqmebeli : public Saxeli {
	
private:
	
	void set(string  pozicia, unsigned int xelfasi) {
		this->pozicia = pozicia;
		this->xelfasi = xelfasi;
	}
protected:
	
	string pozicia;
	unsigned int xelfasi;
	
public:
	
	Damsaqmebeli() : Saxeli() {
		set("tanamdeboba", 0);
	}
	Damsaqmebeli(unsigned int nomeri, string saxeli, string gvari, unsigned int dabweli, unsigned int sqesi, string  pozicia, unsigned int xelfasi):
	Saxeli(nomeri, saxeli, gvari, dabweli, sqesi)
	{
		set(pozicia, xelfasi);
	}
	
	string getPozicia() {
		return pozicia;
	}
	unsigned int getXelfasi() {
		return xelfasi;
	}
};
/*
shemdgomshi kodis es nawili gansazgravs, damsaqmebeli tipis obieqtebTan muSaobis ramdenime funqcias, 
rogoricaa print, input, sortArr, deleteSaxeli, addSaxeli, sqesiFilter da xelfasiFilter. es funqciebi
iReben damsaqmebeli obieqtebis masivis input-s da matze sxvadasxva gzit manipulireben.
*/


// bechdvis funqcia bechdavs damsaqmebelidan tipis obieqtis detalebs
void print(Damsaqmebeli& A) {
	cout << A.getNomeri() << " " << A.getSaxeli() << " " << A.getGvari() << " " << A.getDabweli() << " " << A.getSqesi() << " " << A.getPozicia() << " " << A.getXelfasi() << endl;
}
// sheyvanis funqcia kiTxulobs Sheyvanil monacemebs failidan da am monacemebze dayrdnobiT qmnis obieqtebs.
void input(Damsaqmebeli* Arr) {
	int counter = 0;
	ifstream fin("D:\\faili1.txt");
	if (!fin.is_open()) {
		cerr << "Faili Ver Moidzebna!";
		exit(1);
	}
	unsigned int nomeri, dabweli, sqesi, xelfasi;
	string saxeli, gvari, pozicia;
	while (fin >> nomeri >> saxeli >> gvari >> dabweli >> sqesi >> pozicia >> xelfasi) {
		Damsaqmebeli tmp(nomeri, saxeli, gvari, dabweli, sqesi, pozicia, xelfasi);
		Arr[counter] = tmp;
		counter++;
	}
}
// sortArr funqcia axarisxebs damsaqmebeli obieqtebis masivs mati saxelis mixedvit
	void sortArr(Damsaqmebeli* Arr, unsigned int n) {
		for (int i = 0; i < n - 1; i++) {
			int t = i;
			for (int j = i + 1; j < n; j++){
					if (Arr[j].getSaxeli()[0] < Arr[t].getSaxeli()[0]) {
							t = j;
					}
				}
				swap(Arr[i], Arr[t]);
			}
		}
// deleteSaxeli funqcia Shlis obieqts damsaqmebeli obieqtebis masividan nomeris safudzvelze.
	void deleteSaxeli(Damsaqmebeli* Arr, unsigned int n, unsigned int nomeri) {
			int k = 0;
			for (int i = 0; i < n; i++) {
					if (Arr[i].getNomeri() != nomeri) {
							Arr[k++] = Arr[i];
					}
			}
			while (k < n) {
					Arr[k++] = Damsaqmebeli();
			}
	}
// addSaxelis funqcia amatebs damsaqmebeli tipis axal obieqts misive arsebul masivs.
		void addSaxeli(Damsaqmebeli* &Arr, Damsaqmebeli& user, unsigned int n) {
				Damsaqmebeli* tmpArr = new Damsaqmebeli[n + 1];
				for (int i = 0; i < n; i++) {
					tmpArr[i] = Arr[i];
			}
					tmpArr[n] = user;
					Arr = tmpArr;
	}
// sqesiFilter Funqcia bechdavs damsaqmebeli tipis obieqtebis detalebs, romelTa sqesis cvladi emtxveva mocemul mnishvnelobas.
	void sqesiFilter(Damsaqmebeli* Arr, unsigned int n, unsigned int sqesi) {
			for (int i = 0; i < n; i++) {
					if (Arr[i].getSqesi() == sqesi) {
							print(Arr[i]);
							cout << endl;
		}
	}
}
/* xolo sabolood xelfasiFilter funqcia bechdavs damsaqmebeli tipis obieqtebis detalebs, romelTa xelfasi cvladi aris
	mocemul minimalur da maqsimalur mnishvnelobebs shoris.
*/
	void xelfasiFilter(Damsaqmebeli* Arr, unsigned int n, int min, int max) {
			for (int i = 0; i < n; i++) {
					if (Arr[i].getXelfasi() > min && Arr[i].getXelfasi() < max) {
							print(Arr[i]);
							cout << endl;
		}
	}
}

	
int main() {
	
	Damsaqmebeli* arr = new Damsaqmebeli[4];
	for (int i = 0; i < 4; i++) {
			arr[i] = Damsaqmebeli();
	}
	input(arr);
	print(arr[2]);
		
	return 0;
		
		
}

