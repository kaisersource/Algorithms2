DJIKSTRA
=======

###1)Assegnare ad ogni nodo un valore "tentativo",nel grafo di partenza il nodo sorgente ha valore 0, tutti gli altri infinito.
###2)Memorizzare la lista dei nodi visitati in un heap.
###3)per il nodo corrente si guardano tutti i nodi vicini e si esegue una somma. Distanza[nodo_corrente]<H2>+</H2>peso dell'arco che      congiunge il nodo vicino con quello corrente. Se questa distanza e' monire del valore "tentativo" del nodo vicino allora lo      si inserisce (operazione di Relax).
