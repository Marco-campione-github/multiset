#ifndef MULTISET_H
#define MULTISET_H

#include <ostream>   //std::ostream
#include <iostream>  //std::cout std::endl
#include <cassert>   // assert
#include <algorithm> // std:swap
#include <iterator>  // std::forward_iterator_tag
#include <cstddef>   // std::ptrdiff_t

/**
    @file multiset.h
    @brief Dichiarazione e definizione della classe templata multiset.
*/

/**
    @brief MultiSet di elementi generici T.

    Classe che rappresenta un MultiSet di elementi generici T.
*/
template <typename T>
class multiset
{

public:
    /** Ridefinisco il tipo T come value_type. */
    typedef T value_type;
    /** Ridefinisco il tipo della dimensione del MultiSet come size_type. */
    typedef unsigned int size_type;

private:
    /**
        @brief Struct multiset::element di supporto alla classe MultiSet.

        Struct che rappresenta un elemento unico del MultiSet che memorizza
        il valore dell' elemento e il numero di occorrenze nel MultiSet.
    */
    struct element
    {
        value_type value;      ///< Valore dell' elemento del MultiSet.
        size_type occurrences; ///< numero di occorrenze dell' elemento.
        /**
            Costruttore di default della struct multiset::element che inizializza
            value usando il suo costruttore di default (dipendente dal tipo T) e
            il numero di occorrenze dell' elemento a 0.

            @post occurrences == 0
        */
        element() : value(), occurrences(0) {}
        /**
            Costruttore secondario della struct multiset::element che inizializza
            value usando il parametro val passato come reference e
            il numero di occorrenze dell' elemento a 1.

            @param val reference al valore di default dell' elemento
            @post value == value
            @post occurrences == 1
        */
        element(const value_type &val) : value(val), occurrences(1) {}
        /**
            Costruttore secondario della struct multiset::element che inizializza
            value usando il parametro val passato come reference e il numero
            di occorrenze dell' elemento usando il parametro occ.

            @param val reference al valore di default dell' elemento
            @param occ occorrenze di default dell' elemento
            @post value == value
            @post occurrences == occ
        */
        element(const value_type &val, size_type occ) : value(val), occurrences(occ) {}
    };

    const element *_sequence; ///< Puntatore alla sequenza di elementi.
    size_type _size;          ///< Dimensione del MultiSet.

    /**
        Funzione privata della classe MultiSet che ritorna un
        size_type con l'indice numerico del valore val passato come parametro.
        Questa funzione assume che il valore val sia contenuto nel MultiSet
        utilizzando un assert.

        @param val reference al valore del quale si vuole conoscere l'indice
        @pre val è contenuto nel MultiSet
        @return size_type con l'indice di val nel MultiSet
    */
    size_type index_of(const value_type &val) const
    {
        assert(contains(val));
        size_type index;
        if (_sequence != nullptr)
            for (size_type i = 0; i < _size; ++i)
            {
                if (_sequence[i].value == val)
                    index = i;
            }
        return index;
    }

    /**
        Funzione privata di supporto all' operatore di assegnamento (operator=)
        che scambia il valore di _sequence  e di _size del MultiSet this con
        il MultiSet other passato come parametro per reference.
        Utilizza la funzione della libreria standard std::swap.

        @param other reference al MultiSet per lo scambio dei valori
    */
    void swap(multiset &other)
    {
        std::swap(this->_sequence, other._sequence);
        std::swap(_size, other._size);
    }

public:
    /**
        Costruttore di default della classe MultiSet che inizializza
        _sequence a nullptr e _size a 0

        @post _sequence == 0
        @post _size == 0
    */
    multiset() : _sequence(nullptr), _size(0) {}

    /**
        Costruttore di copia della classe MultiSet che prende come parametro
        un MultiSet e inizializza _sequence e _size con i suoi valori rispettivi.
        Aggiunge alla fine della sequenza un element di default che segna la fine
        del MultiSet.

        @post _sequence == other._sequence
        @post _size == other._size
        @param other reference al MultiSet da copiare
    */
    multiset(const multiset &other) : _sequence(nullptr), _size(0)
    {
        element *tmp = new element[other._size + 1];
        try
        {
            for (size_type i = 0; i < other._size; ++i)
                tmp[i] = other._sequence[i];
            tmp[other._size] = element();
            _sequence = tmp;
        }
        catch (...)
        {
            delete[] _sequence;
            _sequence = nullptr;
            _size = 0;
            throw;
        }
        _size = other._size;
    }

    /**
        Distruttore della classe MultiSet che elimina il MultiSet dalla
        memoria e setta i valori _sequence e _size a dei valori coerenti
        tramite la funzione pubblica remove_all().
    */
    ~multiset()
    {
        remove_all();
    }

    /**
        Operatore di assegnamento della classe MultiSet che assegna il MultiSet
        passato come parametro a this utilizzando il costruttore di copia e la
        funzione privata swap.

        @param other reference al MultiSet da copiare
        @return reference a this
    */
    multiset &operator=(const multiset &other)
    {
        if (&other != this)
        {
            multiset tmp(other);
            tmp.swap(*this);
        }
        return *this;
    }

    /**
        Funzione che aggiunge un valore preso come parametro nel MultiSet.
        Se il valore è già contenuto modifica le sue occorrenze altrimenti
        aggiunge un nuovo elemento con una occorrenza.

        @param val reference al valore da inserire nel MultiSet
    */
    void add(const value_type &val)
    {
        if (contains(val))
        {
            size_type new_occ = occurrences_of(val) + 1;
            element *tmp = new element[_size + 1];
            for (size_type i = 0; i < _size; ++i)
            {
                tmp[i] = _sequence[i];
            }
            tmp[index_of(val)] = element(val, new_occ);
            tmp[_size] = element();
            delete[] _sequence;
            _sequence = tmp;
        }
        else
        {
            element *tmp = new element[_size + 2];
            for (size_type i = 0; i < _size; ++i)
            {
                tmp[i] = _sequence[i];
            }
            tmp[_size] = element(val);
            tmp[_size + 1] = element();
            delete[] _sequence;
            _sequence = tmp;
            _size++;
        }
    }

    /**
        Funzione che aggiunge un valore preso come parametro nel MultiSet
        un numero di volte pari al parametro occ specificato.
        Se il valore è già contenuto modifica le sue occorrenze altrimenti
        aggiunge un nuovo elemento con un numero di occorrenze specificato
        nei parametri.
        Utilizza la funzione add già implementata.

        @param val reference al valore da inserire nel MultiSet
        @param occ occorrenze da inserire nel MultiSet
    */
    void add(const value_type &value, size_type occ)
    {
        for (size_type i = 0; i < occ; ++i)
            add(value);
    }

    /**
        Funzione che rimuove una singola occorrenza del valore indicato
        come parametro.
        Se il MultiSet non contiene tale valore allora non viene modificato
        lo stato della classe.

        @param val reference al valore da eliminare dal MultiSet
    */
    void remove(const value_type &val)
    {
        if (contains(val))
        {
            if (occurrences_of(val) > 1)
            {
                size_type new_occ = occurrences_of(val) - 1;
                size_type index = index_of(val);
                element *tmp = new element[_size + 1];
                for (size_type i = 0; i < _size; ++i)
                {
                    if (i != index)
                        tmp[i] = _sequence[i];
                    else
                        tmp[i] = element(val, new_occ);
                }
                tmp[_size] = element();
                delete[] _sequence;
                _sequence = tmp;
            }
            else
            {
                if (_size > 1)
                {
                    element *tmp = new element[_size];
                    size_type found = 0;
                    for (size_type i = 0; i < _size; ++i)
                    {
                        if (i != index_of(val))
                            tmp[i - found] = _sequence[i];
                        else
                            found = 1;
                    }
                    tmp[_size - 1] = element();
                    delete[] _sequence;
                    _sequence = tmp;
                    _size--;
                }
                else
                {
                    remove_all();
                }
            }
        }
    }

    /**
        Funzione che pulisce il contenuto del MultiSet impostando la _sequence
        = nullptr e la _size = 0.

        @post _sequence == nullptr
        @post _size == 0
    */
    void remove_all()
    {
        delete[] _sequence;
        _sequence = nullptr;
        _size = 0;
    }

    /**
        Funzione che dice se un valore passato come parametro è contenuto
        nel MultiSet. Torna true se è presente, false altrimenti.

        @param val reference al valore del quale bisogna controllare la presenza
        @return bool che indica la presenza o meno del valore val
    */
    bool contains(const value_type &val) const
    {
        bool flag = false;
        if (_sequence != nullptr)
        {
            for (size_type i = 0; i < _size; ++i)
            {
                if (_sequence[i].value == val)
                {
                    flag = true;
                }
            }
        }
        return flag;
    }

    /**
        Funzione che ritorna il numero di occorrenze all' interno del MultiSet
        del valore passato come parametro.

        @param val reference al valore del quale si vogliono sapere le occorrenze
        @return numero di occorrenze del valore val
    */
    size_type occurrences_of(const value_type &val) const
    {
        if (contains(val))
            return _sequence[index_of(val)].occurrences;
        else
            return 0;
    }

    /**
        Funzione che torna il numero totale delle occorrenze di tutti i
        valori contenuti nel MultiSet.

        @return size_type numero di occorrenze totali nel multiset
    */
    const size_type size() const
    {
        size_type tmp = 0;
        for (size_type i = 0; i < _size; ++i)
        {
            tmp += occurrences_of(_sequence[i].value);
        }
        return tmp;
    }

    /**
        Funzione che torna il numero di valori singoli contenuti nel MultiSet.

        @return size_type numero di valori nel multiset
    */
    const size_type unique_size() const
    {
        return _size;
    }

    /**
        Funzione che true se il MultiSet contiene dei valori,
        false se il MultiSet è vuoto

        @return bool true se pieno, false se vuoto
    */
    bool is_empty() const
    {
        return _size == 0;
    }

    /**
        Costruttore secondario che crea un MultiSet di valori T a partire da
        una sequenza di dati generici Q identificata da una coppia di iteratori
        generici, uno per l'inizio e uno per la fine della sequenza.

        @param begin iteratore di inizio della sequenza
        @param end iteratore di fine della sequenza
    */
    template <typename Q>
    multiset(Q begin, Q end) : _sequence(nullptr), _size(0)
    {
        try
        {
            while (begin != end)
            {
                add(static_cast<T>(*begin));
                ++begin;
            }
        }
        catch (...)
        {
            delete[] _sequence;
            _sequence = nullptr;
            _size = 0;
            throw;
        }
    }

    /**
        Funzione che ridefinisce l'operatore == per la classe MultiSet.
        Confronta il MultiSet this con il MultiSet other e dice se
        contengono gli stessi valori con lo stesso numero di occorrenze.
        Utilizza gli iteratori per ciclare sul MultiSet.

        @param reference ad un MultiSet costante other da confrontare
        @return true: se this==other, false: se this != other
    */
    bool operator==(const multiset<T> &other) const
    {
        size_type index_other;
        bool flag = true;
        if (_size != other._size)
            flag = false;
        for (size_type i = 0; i < _size; i++)
        {
            if (other.contains(_sequence[i].value))
            {
                index_other = other.index_of(_sequence[i].value);
                if (occurrences_of(_sequence[i].value) !=
                    occurrences_of(other._sequence[index_other].value))
                {
                    flag = false;
                }
            }
            else
                flag = false;
        }
        return flag;
    }

    /**
        @brief Iteratore di sola lettura (const) per la classe MultiSet.

        E' un const_iterator di tipo forward_iterator.
    */
    class const_iterator
    {

    public:
        typedef std::forward_iterator_tag iterator_category; ///< iterator_category
        typedef T value_type;                                ///< value_type
        typedef ptrdiff_t difference_type;                   ///< difference_type
        typedef const T *pointer;                            ///< pointer
        typedef const T &reference;                          ///< reference

        /** Costruttore di default dell'iteratore. */
        const_iterator() : ptr(nullptr), occ(0) {}

        /** Costruttore di copia dell'iteratore. */
        const_iterator(const const_iterator &other) : ptr(other.ptr), occ(other.occ) {}

        /** Operatore di assegnamento dell' iteratore */
        const_iterator &operator=(const const_iterator &other)
        {
            ptr = other.ptr;
            occ = other.occ;
            return *this;
        }

        /** Distruttore di default dell'iteratore. */
        ~const_iterator() {}

        /** Dereferenziamento dell'iteratore. */
        reference operator*() const
        {
            return ptr->value;
        }

        /** Valore puntato dall'iteratore. */
        pointer operator->() const
        {
            return &(ptr->value);
        }

        /** Operatore di post-incremento dell' iteratore */
        const_iterator operator++(int)
        {
            const_iterator tmp(*this);
            if (occ == 1)
            {
                ++ptr;
                occ = ptr->occurrences;
            }
            else
                occ--;
            return tmp;
        }

        /** Operatore di pre-incremento dell' iteratore */
        const_iterator &operator++()
        {
            if (occ == 1)
            {
                ++ptr;
                occ = ptr->occurrences;
            }
            else
                occ--;
            return *this;
        }

        /** Operatore di uguaglianza dell' iteratore */
        bool operator==(const const_iterator &other) const
        {
            return (ptr == other.ptr); // && occ == other.occ);
        }

        /** Operatore di diversità dell' iteratore */
        bool operator!=(const const_iterator &other) const
        {
            return (ptr != other.ptr); // && occ != other.occ);
        }

    private:
        const element *ptr; ///< elemento di _sequence puntato dall' iteratore
        size_type occ;      ///< occorrenze del valore corrente rimaste

        friend class multiset;

        /**
            Costruttore privato dell' iteratore, utilizzato dalle funzioni
            begin e end della classe MultiSet
        */
        const_iterator(const element *e) : ptr(e)
        {
            if (ptr != nullptr)
                occ = ptr->occurrences;
            else
                occ = 0;
        }
    };

    /**
        Funzione che ritorna un iteratore all' elemento iniziale della sequenza.

        @return const_iterator che punta a _sequence
    */
    const_iterator begin() const
    {
        return const_iterator(_sequence);
    }

    /**
        Funzione che ritorna un iteratore all' elemento finale della sequenza.

        @return const_iterator che punta a _sequence + _size
    */
    const_iterator end() const
    {
        return const_iterator(_sequence + _size);
    }
};

/**
    Funzione templata che ridefinisce l'operatore << per la classe MultiSet.
    Utilizza gli iteratori per ciclare sul MultiSet.
    Stampa il MultiSet nella forma {<X1, occorrenzeX1>, <X2, occorrenzeX2>, ...}.

    @param ostream os
    @param reference ad un MultiSet da stampare su os
    @return ostream os
*/
template <typename T>
std::ostream &operator<<(std::ostream &os, const multiset<T> &ms)
{
    typename multiset<T>::size_type sz = ms.size();
    os << "{";
    if (sz != 0)
    {
        typename multiset<T>::const_iterator i = ms.begin(), ie = ms.end();
        typename multiset<T>::const_iterator tmp = i;
        typename multiset<T>::size_type num = 0;
        while (i != ie)
        {
            os << "<";
            while ((tmp == i) && (i != ie))
            {
                ++num;
                ++i;
            }
            os << *tmp << ", " << num << ">";
            tmp = i;
            num = 0;
            if (i != ie)
                os << ", ";
        }
    }
    os << "}";
    return os;
}

#endif // MULTISET_H
