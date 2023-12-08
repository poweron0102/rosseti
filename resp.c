TLSE** cria(int n) {
  TLSE** resp = malloc(sizeof(TLSE*) * 2);
  TLSE* l = NULL;
  for (int c = n-1; c > 0; c--) {
    l = TLSE_insere(l, c);
  }
  l = TLSE_insere(l, n);
  for (int c = n-1; c > 0; c--) {
    l = TLSE_insere(l, c);
  }
  resp[0] = l;
  resp[1] = TLSE_busca(TLSE_busca(l->prox, 1)->prox, n-1);
  return resp;
}


void misc(TLSE *l, int x){
  TLSE* anterior = l;
  if (x < 2) { return; }
  if (l && l->info == x) {
    TLSE** listas = cria(x);
    l->info = 1;
    listas[0] = TLSE_retira(listas[0], 1);
    TLSE* fim = l->prox;
    l->prox = listas[0];
    listas[1]->prox = fim;
    anterior = fim;
    free(listas);
  }
  while (anterior && anterior->prox) {
    if (anterior->prox->info == x) {
      TLSE** listas = cria(x);
      listas[1]->prox = anterior->prox->prox;
      free(anterior->prox);
      anterior->prox = listas[0];
      anterior = listas[1];
      free(listas);
      continue;
    }
    anterior = anterior->prox;
  }
}






void ret_nao_mult_N(TLSE* l, int n){
  if (!l) {return;}

  if ((l->info) % n) {
    int res; TLSE* l2 = l->prox;
    int achou = 0;
    while (l2) {
      if (!(l2->info % n)) {
        achou = 1;
        res = l2->info;
        break;
      }
      l2 = l2->prox;
    }
    if (achou) {
      TLSE* l2prox = l2->prox;
      l2->prox = NULL;
      TLSE_libera(l->prox);
      l->prox = l2prox;
      l->info = res;
    } else {
      l->prox = NULL;
    }
  }
  ret_nao_mult_N(l->prox, n);
}







TLSE *meio(TLSE *l, int *pos) {
  int vet_n = 2;
  TLSE** vet = calloc(vet_n, sizeof(TLSE*));
  int index = 0;
  for (; l; l = l->prox) {  // o for ja trata o (se !l). a função retornará Null e botara 0 em pos caso seja passado l = NULL, pq vet é iniciado com calloc. 
    vet[index++] = l;
    if (index == vet_n) {
      vet_n *= 2;
      vet = realloc(vet, vet_n * sizeof(TLSE*));
    }
  }
  *pos = (index + 1)/2;
  TLSE* resp = vet[index/2];
  free(vet);
  return resp;
}



