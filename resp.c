TLSE** cria(int n) {
  TLSE** resp = malloc(sizeof(TLSE*) * 2);
  TLSE* l = NULL;
  for (int c = 1; c < n; c++) {
    l = TLSE_insere(l, c);
  }
  for (int c = n; c > 0; c--) {
    l = TLSE_insere(l, c);
  }
  resp[0] = l;
  resp[1] = TLSE_busca(l->prox, 1);
  return resp;
}


void misc(TLSE *l, int x){
  TLSE* anterior = l;
  if (x < 2) { return; }
  if (l && l->info == x) {
    listas = cria(x);
    l->info = 1;
    listas[0] =TLSE_retira(listas[0], 1);
    TLSE* fim = TLSE_busca(l, x);
    l->prox = listas[0];
    listas[1] = fim->prox;
    anterior = fim->prox;
    free(fim); free(listas);
  }

  while (anterior->prox) {
    if (anterior->prox->info == x) {
      listas = cria(x);
      listas[1]->prox = anterior->prox->prox;
      free(anterior->prox);
      anterior->prox = listas[0];
      free(listas);
    }
      anterior = anterior->prox;
  }
}






void ret_nao_mult_N(TLSE* l, int n){
  if (!l) {return;}

  if (!l->info % n) {
    int res; TLSE* l2 = l->prox;
    int achou = 0;
    while (l2) {
      if (!l2->info % n) {
        achou = 1;
        res = l2->info;
      }
    }
    if (achou) {
      TLSE* l2prox = l2->prox;
      l2->prox = NULL;
      TLSE_libera(l->prox);
      l->prox = l2prox;
      l->info = res;
    }
  }
  ret_nao_mult_N(l, n);
}






TLSE *meio(TLSE *l, int *pos) {
  int vet_n = 2;
  TLSE** vet = calloc(vet_n * sizeof(TLSE*));
  int index = 0;
  for (; l; l = l->prox) {
    vet[index++] = l;
    if (index == vet_n) {
      vet_n *= 2;
      vet = realloc(vet, vet_n);
    }
  }
  *pos = index/2;
  return vet[index/2];
}



