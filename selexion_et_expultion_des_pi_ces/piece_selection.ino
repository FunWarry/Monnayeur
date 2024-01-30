void p_rendue() {
  for (i = 0; i < 50; i++) {
    if (list[i] == 200) {
      deuxE();
    }
    else if (list[i] == 100) {
      unE();
    }
    else if (list[i] == 50) {
      cinquanteC();
    }
    else if (list[i] == 20) {
      vingtC();
    }
    else if (list[i] == 10) {
      dixC();
    }
    else if (list[i] == 5) {
      cinqC();
    }
    else if (list[i] == 2) {
      deuxC();
    }
    else if (list[i] == 1) {
      unC();
    }
    list[i] = 0;
  }
}
