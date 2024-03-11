MultiSet di elementi generici T. Un MultiSet è come un insieme di dati che può contenere duplicati: es. S = {1,4,6,4,9,4,7,10,12}. Il MultiSet è implementato in modo tale da minimizzare l’uso della memoria cioè non dovete memorizzare i duplicati di un elemento. Facendo riferimento all’esempio precedente, il '4' viene memorizzato una sola volta sapendo però che ci sono tre occorrenze di '4' in S.
A parte i metodi essenziali per la classe (tra cui conoscere il numero totale di elementi, aggiunta/rimozione elementi, conteggio occorrenze di un elemento, ecc...), sono state implementate le seguenti funzionalità:
1. la costruzione di un MultiSet anche a partire da una sequenza di dati generici Q identificata da una coppia di iteratori generici. Questo costruttore prende in input: l’iteratore di inizio sequenza, l’iteratore di fine sequenza. Lasciate al compilatore la gestione della conversione di dati tra Q e T.
2. A read-only iterator (choose category) that returns a <value, occurrences> pair The iterator must return all elements of the MultiSet. That is, duplicates must be returned in the correct number. In the example case of S it could be a sequence of values like: 1 4 4 6 9 7 10 12
3. The comparison operator== between two MultiSets that returns true sif the two MultiSets (of the same type) contain the same elements with the same number of occurrences of duplicates.
4. The contains method that, given an element of type T, returns true if the element exists in the MultiSet.
5. The global operator<< function to send on std::ostream the contents of the MultiSet in the form: {<X1, occurrencesX1>, <X2, occurrencesX2>,...,<XN, occurrencesXN>}

- The order of the elements in the MultiSet is not relevant.
- Removal of an element X occurs when the number of occurrences of that element becomes zero.
- Elements in the MultiSet are immutable. Once inserted, they do not change value.
