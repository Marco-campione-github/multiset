#include "multiset.h"
#include <iostream>
#include <cassert>

struct Punto{
	int x;
	int y;
	Punto(int i, int j) : x(i), y(j) {}
	Punto() : x(0), y(0) {}
};

std::ostream& operator<<(std::ostream &os, const Punto &p) {
	os <<"(" << p.x << " , " << p.y << ")";
	return os;
}

bool operator==(const Punto &p1, const Punto &p2){
	return (p1.x == p2.x && p1.y == p2.y);
}

void test_multiset_int(){
	std::cout << "TEST MULTISET<INT>: " << std::endl;
	multiset<int> mint; //test multiset()
	std::cout << mint << std::endl; //test operatore di stampa su multiset vuoto
	mint.add(1); //test add()
	mint.add(2, 2); //test add multipla()
	mint.add(100, 30);
	multiset<int> mint1(mint); //test costruttore di copia
	multiset<int> mint2;
	mint2 = mint; //test operatore di assegnamento (e swap() privato)
	std::cout << mint << std::endl; //test operatore di stampa
	std::cout << mint1 << std::endl; //test operatore di stampa
	std::cout << mint2 << std::endl; //test operatore di stampa
	assert(mint == mint1); //test operatore di uguaglianza
	assert(mint == mint2); //test operatore di uguaglianza
	assert(mint.size() == 33); //test size() (numero di occorrenze)
	assert(mint.unique_size() == 3); //test unique_size() (numero di valori differenti)
	assert(mint.contains(100)); //test contains()
	assert(mint.occurrences_of(2) == 2); //test occurrences_of() (e index_of() privato)
	mint.remove(1); //test_remove()
	assert(mint.size() == 32); //mi assicuro che la dimensione si cambiata
	assert(mint.unique_size() == 2); //mi assicuro che la dimensione si cambiata
	assert(!mint.contains(1)); //mi assicuro che il multset non contenga piu' il valore
	mint.remove_all(); //test remove_all()
	assert(mint.is_empty()); //test is_empty()
	//test ~multiset()
}

void test_multiset_punto(){
	std::cout << "TEST MULTISET<PUNTO>: " << std::endl;
	multiset<Punto> mpoint; //test multiset()
	std::cout << mpoint << std::endl; //test operatore di stampa su multiset vuoto
	mpoint.add(Punto(1, 1)); //test add()
	mpoint.add(Punto(2, 5), 3); //test add multipla()
	mpoint.add(Punto(10, 10), 10);
	multiset<Punto> mpoint1(mpoint); //test costruttore di copia
	multiset<Punto> mpoint2;
	mpoint2 = mpoint; //test operatore di assegnamento (e swap() privato)
	std::cout << mpoint << std::endl; //test operatore di stampa (e iteratori in parte)
	std::cout << mpoint1 << std::endl;
	std::cout << mpoint2 << std::endl;
	assert(mpoint == mpoint1); //test operatore di uguaglianza
	assert(mpoint == mpoint2); //test operatore di uguaglianza
	assert(mpoint.size() == 14); //test size() (numero di occorrenze)
	assert(mpoint.unique_size() == 3); //test unique_size() (numero di valori differenti)
	assert(mpoint.contains(Punto(10, 10))); //test contains()
	assert(mpoint.occurrences_of(Punto(2, 5)) == 3); //test occurrences_of() (e index_of() privato)
	mpoint.remove(Punto(2, 5)); //test_remove()
	assert(mpoint.size() == 13); //mi assicuro che la dimensione si cambiata
	mpoint.remove(Punto(1, 1)); //test_remove()
	assert(mpoint.size() == 12); //mi assicuro che la dimensione si cambiata
	assert(mpoint.unique_size() == 2); //mi assicuro che la dimensione si cambiata
	assert(!mpoint.contains(Punto(1, 1))); //mi assicuro che il multset non contenga piu' il valore
	mpoint.remove_all(); //test remove_all()
	assert(mpoint.is_empty()); //test is_empty()
	//test ~multiset()
}

void test_multiset_multiset_int(){
	std::cout << "TEST MULTISET<MULTISET<INT>>: " << std::endl;
	multiset<multiset<int>> mmint; //test multiset()
	std::cout << mmint << std::endl; //test operatore di stampa su multiset vuoto
	multiset<int> tmp1;
	tmp1.add(10), tmp1.add(20, 3), tmp1.add(30, 10);
	multiset<int> tmp2;
	tmp2.add(1), tmp2.add(2, 3), tmp2.add(3, 10);
	multiset<int> tmp3;
	tmp3.add(3, 3), tmp3.add(6, 6), tmp3.add(9, 9);
	mmint.add(tmp1); //test add()
	mmint.add(tmp2, 3); //test add multipla()
	mmint.add(tmp3, 10);
	multiset<multiset<int>> mmint1(mmint); //test costruttore di copia
	multiset<multiset<int>> mmint2;
	mmint2 = mmint; //test operatore di assegnamento (e swap() privato)
	std::cout << mmint << std::endl; //test operatore di stampa
	std::cout << mmint1 << std::endl; //test operatore di stampa
	std::cout << mmint2 << std::endl; //test operatore di stampa
	assert(mmint == mmint1); //test operatore di uguaglianza
	assert(mmint == mmint2); //test operatore di uguaglianza
	assert(mmint.size() == 14); //test size() (numero di occorrenze)
	assert(mmint.unique_size() == 3); //test unique_size() (numero di valori differenti)
	assert(mmint.contains(tmp2)); //test contains()
	assert(mmint.occurrences_of(tmp2) == 3); //test occurrences_of() (e index_of() privato)
	mmint.remove(tmp2); //test_remove()
	assert(mmint.size() == 13); //mi assicuro che la dimensione si cambiata
	mmint.remove(tmp1); //test_remove()
	assert(mmint.size() == 12); //mi assicuro che la dimensione si cambiata
	assert(mmint.unique_size() == 2); //mi assicuro che la dimensione si cambiata
	assert(!mmint.contains(tmp1)); //mi assicuro che il multset non contenga piu' il valore
	mmint.remove_all(); //test remove_all()
	assert(mmint.is_empty()); //test is_empty()
	//test ~multiset()
}

void test_iteratori_multiset_int(){
	std::cout << "TEST MULTISET<INT>::CONST_ITERATOR" << std::endl;
	multiset<int> mint;
	mint.add(10, 10), mint.add(30, 5), mint.add(70, 50);

	//test begin(), end(), const_iterator()
	multiset<int>::const_iterator i = mint.begin(), ie = mint.end();
	multiset<int>::const_iterator i1(i); //test costruttore di copia
	multiset<int>::const_iterator i2; //test costruttore di default
	i2 = i; //test operatore di assegnamento
	assert(i == i1); //test operatore ==
	assert(i == i2);

	multiset<int> mint3(i, ie); //test multiset(Q begin, Q end)
	std::cout << mint3 << std::endl;

	while(i != ie){ //test operatore !=
		assert(mint.contains(*i)); //test dereferenziamento
		//std::cout << *i << std::endl;
		i++; //test post-incremento
	}

	//operatore di pre-incremento utilizzato nel metodo
	//di stampa operator<< e quindi già testato

	//~const_iterator();
}

int main(){
	test_multiset_int();
	test_multiset_punto();
	test_multiset_multiset_int();
	test_iteratori_multiset_int();
	return 0;
}
