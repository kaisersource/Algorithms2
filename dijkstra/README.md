DJIKSTRA (SINGLE SOURCE SHORTEST PATH)
=======

###1)Assegnare ad ogni nodo un valore "tentativo",nel grafo di partenza il nodo sorgente ha valore 0, tutti gli altri infinito.
###2)Memorizzare la lista dei nodi visitati in un heap.
###3)per il nodo corrente si guardano tutti i nodi vicini e si esegue una somma. Distanza[nodo_corrente] sommato al peso       ###dell'arco che congiunge il nodo vicino con quello corrente. Se questa distanza e' monire del valore "tentativo" del nodo ###vicino allora lo si inserisce (operazione di Relax).
###4)Quando ho considerato tutti i vicini, marco quel nodo come visitato e lo aggiungo al set di nodi visitati.
###5)Se la destinazione e' marcata come visitata l'algoritmo termina. Altrimenti si procede con un nuovo nodo current da visitare, precisamente quello col peso minore(calcolato con le Relax precedenti). Tornare allo step 3. 

##VANTAGGI: con heap binario COSTO SPAZIALE  O(|E|+|V|log(|V|) - COSTO TEMPORALE O(|V|) dato dal massimo numero di vertici memorizzabili
##SVANTAGGI: i cicli devono essere non negativi.
